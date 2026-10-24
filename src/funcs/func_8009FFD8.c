/* cflags: -O2 */
#include "common.h"

extern void func_800043D0(u8 *, s32, void (*)(void), u8 *, u8 *, s32);
extern u8 *func_8009E6B4(u8 *, s32, s32);
extern u8 D_800EA110[];
extern void func_800A00F4(void);

void func_8009FFD8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(u8 **)(arg0 + 0x1B0) = func_8009E6B4(D_800EA110, arg3, 8);
    *(s32 *)(arg0 + 0x1B4) = arg3;
    *(s32 *)(arg0 + 0x1B8) = 1;
    func_800043D0(arg0, arg1, func_800A00F4, arg0, *(u8 **)(arg0 + 0x1B0) + arg3, arg2);
}
