/* cflags: -O2 */
#include "common.h"

void func_800B5210(u8 *);
void func_800B555C(u8 *, s32, s32);

#define W(o) (*(s32 *)(arg0 + (o)))

void func_800B4998(u8 *arg0, s32 arg1, s32 arg2) {
    func_800B5210(arg0);
    func_800B555C(arg0, arg1, arg2);
    W(0x1CA0) = 0;
    W(0x1C9C) = 0;
    W(0x188C) = 0;
    W(0x80) = 0;
    if (arg1 != 0) {
        W(0x1C98) = 0;
    }
    W(0x84) = 0;
    if (arg2 != 0) {
        W(0x88) = 0;
    }
}
