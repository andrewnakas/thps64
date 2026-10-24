#include "common.h"

s32 func_800BAC04(s32 *, u32); /* extern */

void func_800BABE0(s32 *arg0, s32 arg1) {
    func_800BAC04(arg0, (u32) (arg1 - *arg0) >> 3);
}
