@echo off
rem Build the THPS64 recomp port (clang-cl + Ninja, like the Pilotwings port). Run detached; log goes to build.log.
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul
set PATH=C:\Users\andre\.local\clang+llvm-23.1.2-x86_64-pc-windows-msvc\bin;%PATH%
cd /d E:\thps64\port
cmake -B build -G Ninja "-DCMAKE_C_COMPILER=clang-cl" "-DCMAKE_CXX_COMPILER=clang-cl" "-DCMAKE_BUILD_TYPE=RelWithDebInfo" "-DCMAKE_POLICY_VERSION_MINIMUM=3.5" "-DTHPS_WITH_RUNTIME=ON" "-DTHPS_WITH_RECOMPILED=ON" || exit /b 1
cmake --build build --target THPS64Recomp -j 3 || exit /b 1
echo BUILD OK
