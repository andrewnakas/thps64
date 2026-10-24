/* cflags: -O2 */
#include "common.h"

extern void func_8009E334(u8 *);
extern void func_8009ECF8(u8 *, s32);
extern u8 D_80021828[];
extern u8 D_800EA110[];

void func_800A5FD0(u8 *arg0, s32 arg1) {
    *(u8 **)(arg0 + 0x1C) = D_80021828;
    func_8009ECF8(D_800EA110, *(s32 *)arg0);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
