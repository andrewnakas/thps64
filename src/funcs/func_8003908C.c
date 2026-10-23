#include "common.h"

extern u8 D_800ECFE0[];
void func_800B4A08(void *, s32, s32, s32, s32, s32, s32);

void func_8003908C(void *arg0, u16 *arg1) {
    u8 *p;
    s32 b;
    s32 s;
    s32 off;

    p = D_800ECFE0;
    s = *(s16 *)((u8 *)arg1 + 0x3A);
    off = arg1[0] << 6;
    b = *(s32 *)((u8 *)arg0 + 0x2C);
    func_800B4A08(p, *(s32 *)((u8 *)arg0 + 4), s, b + off, -1, 0, 0);
}
