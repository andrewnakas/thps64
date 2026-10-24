#include "common.h"

void func_800960E8(u8 *a0, s32 i) {
    u8 *e;
    a0[2] = i;
    for (i = 0, e = a0; i < 15; i++, e += 0x18) {
        u16 *c = (u16 *)(e + 0x1A);
        u16 v;
        if (i == a0[2]) {
            v = *(u16 *)(e + 0x1C);
        } else {
            v = *(u16 *)(e + 0x1E);
        }
        *c = v;
        *(u16 *)(e + 0x18) = *(u16 *)(e + 0x1A);
    }
}
