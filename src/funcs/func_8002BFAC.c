#include "common.h"

extern u8 D_800D3668[];

void func_8002BFAC(void) {
    s32 n;
    s32 i;
    s32 p;

    n = 13;
    i = 12;
    p = (s32)D_800D3668;
    for (; i >= 0; i--) {
        if (*(u8 *)(i + p) != ' ') {
            break;
        }
        n--;
    }
    *(u8 *)(n + p) = 0;
}
