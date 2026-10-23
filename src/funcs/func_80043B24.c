#include "common.h"

extern u8 D_800D49E0[];
void func_80043FB0(u8 *);

void func_80043B24(void) {
    s32 i;
    u8 *p;

    i = 0;
    p = D_800D49E0;
    while (1) {
        if (!(i < 2)) {
            break;
        }
        func_80043FB0(p);
        *(s32 *)(p + 0x170) = 0;
        p[0x16B] = 0;
        p[0x16A] = 0;
        p[0x169] = 0;
        p[0x168] = 0;
        p += 0x18C;
        i++;
    }
}
