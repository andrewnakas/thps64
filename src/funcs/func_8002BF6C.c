#include "common.h"

extern u8 D_800D3668[];

void func_8002BF6C(void *arg0) {
    s32 i;
    s32 j;
    u32 p;

    *(s32 *)((u8 *)arg0 + 0x240) = 1;
    j = 13;
    i = 12;
    p = (u32)D_800D3668;
    for (; i >= 0; i--) {
        if (*(u8 *)(i + p) != ' ') {
            break;
        }
        j--;
    }
    *(u8 *)(j + p) = 0;
}
