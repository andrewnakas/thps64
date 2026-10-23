#include "common.h"

s32 func_800BACE0(void *, s32);
extern s32 D_800EECF0;

void func_80026494(u8 *arg0, s32 arg1) {
    s32 r;
    s32 t;

    if (arg1 != 0) {
        do {
            t = *(s32 *)(arg0 + 0x2CC);
            t += arg1;
            t += 0x5D0;
            t %= 1488;
            *(s32 *)(arg0 + 0x2CC) = t;
            r = func_800BACE0(&D_800EECF0, t);
            *(s32 *)(arg0 + 0x30) = r;
        } while (r == 0);
    }
}
