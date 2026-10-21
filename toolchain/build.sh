#!/bin/sh
# Build the THPS64 matching toolchain natively on Windows (Git Bash + zig), no WSL/MSYS2:
#   KMC-style GCC 2.7.2 cc1 (decompals/mips-gcc-2.7.2) and KMC gas 2.6 (decompals/mips-binutils-2.6).
#   sh toolchain/build.sh [WORKDIR]      (default E:/thps64-tools) -> WORKDIR/bin/{cc1.exe,mips-as.exe}
# zig cc targets 32-bit MinGW (the old sources assume a 32-bit host). Patches only touch temp files and
# text/binary mode; compat/ supplies the POSIX bits MinGW lacks. Preprocessing uses zig's clang (cccp crashes).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
W=${1:-/e/thps64-tools}
GCC_REV=43d1cdb67ed135879869b5266f01efaaada5e35a
BU_REV=54514ded39ceb32165a125ddba04ca5b551773a2
mkdir -p "$W/bin" "$W/compat/sys"
cp "$HERE/cc32" "$W/bin/cc32"; chmod +x "$W/bin/cc32"
sed -i "s|-I/e/thps64-tools/compat|-I$W/compat|" "$W/bin/cc32"
cp "$HERE/posix.c" "$HERE/compat.c" "$W/compat/"; cp "$HERE/sys/resource.h" "$W/compat/sys/"
CC="$W/bin/cc32"
"$CC" -c "$W/compat/compat.c" -o "$W/compat/compat.o"
"$CC" -c "$W/compat/posix.c" -o "$W/compat/posix.o"
AR=$(dirname "$(command -v zig 2>/dev/null || echo /c/Users/andre/bin/ar)")/ar
[ -x "$AR" ] || AR=/c/Users/andre/bin/ar

cd "$W"
[ -d mips-gcc-2.7.2 ] || git clone -q https://github.com/decompals/mips-gcc-2.7.2
cd mips-gcc-2.7.2 && git -c safe.directory='*' checkout -q $GCC_REV && git -c safe.directory='*' apply "$HERE/gcc-2.7.2-windows.patch" 2>/dev/null || true
CC="$CC" ./configure --target=mips-mips-gnu --prefix=/opt/cross --with-gnu-as --disable-gprof --disable-gdb \
  --disable-werror --host=i386-pc-linux --build=i386-pc-linux > ../gcc-configure.log
touch c-parse.c
make CC="$CC" HOST_CC="$CC" CFLAGS=-O1 CLIB="$W/compat/compat.o" cc1 > ../gcc-make.log
cp cc1.exe "$W/bin/"

cd "$W"
[ -d mips-binutils-2.6 ] || git clone -q https://github.com/decompals/mips-binutils-2.6
cd mips-binutils-2.6 && git -c safe.directory='*' checkout -q $BU_REV && git -c safe.directory='*' apply "$HERE/binutils-2.6-windows.patch" 2>/dev/null || true
CC="$CC" ./configure --target=mips-kmc-elf --prefix=/opt/cross --disable-gprof --disable-gdb --disable-werror \
  --host=i386-pc-linux --build=i386-pc-linux > ../bu-configure.log
make -C bfd CC="$CC" CFLAGS=-O1 AR="$AR" RANLIB=true > ../bu-make.log
make -C opcodes CC="$CC" CFLAGS=-O1 AR="$AR" RANLIB=true >> ../bu-make.log
# libiberty's link probe cannot run under clang; these are the functions MinGW lacks
(cd libiberty && touch dummy.o && for f in bcmp bcopy bzero getpagesize index insque random rindex vfork \
  sigsetmask waitpid sys_siglist psignal basename; do echo "undefined reference to \`$f'"; done > errors &&
  printf '#ifndef NEED_sys_siglist\n#define NEED_sys_siglist\n#endif\n#ifndef NEED_psignal\n#define NEED_psignal\n#endif\n#ifndef NEED_basename\n#define NEED_basename\n#endif\n' > lconfig.h)
make -C libiberty CC="$CC" CFLAGS=-O1 AR="$AR" RANLIB=true >> ../bu-make.log
make -C gas CC="$CC" CFLAGS="-O1 -Duint=unsigned" AR="$AR" RANLIB=true LOADLIBES="$W/compat/posix.o" >> ../bu-make.log
cp gas/as.new "$W/bin/mips-as.exe"
echo "toolchain ready: $W/bin/cc1.exe $W/bin/mips-as.exe"
