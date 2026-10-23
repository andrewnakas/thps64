#include "common.h"

extern s32 func_80049D60(s32);

void func_8006EC84(s16 *a0) {
    s16 *p;
    s32 i;

    i = 0;
    p = a0;
    do {
        *p = func_80049D60(30) + 15;
        i++;
        p++;
    } while (i < 32);
    a0[0x20] = 0x118;
    a0[0x23] = 0xF0;
}
