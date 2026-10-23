#include "common.h"

extern u8 D_800D4AE0[];

void func_80043FE8(s32 arg0) {
    u8 *p;
    s32 i;

    p = D_800D4AE0 + arg0 * 0x18C;
    for (i = 3; i >= 0; i--) {
        p[1] = 0;
        p += 0x10;
    }
}
