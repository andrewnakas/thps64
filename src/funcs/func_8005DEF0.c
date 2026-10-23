#include "common.h"

extern s32 D_800D7720;

void func_8005DEF0(void) {
    s32 i;
    s32 j;
    s32 row;
    s32 off;
    s32 p;
    s32 q;

    D_800D7720 = 0;
    i = 0;
    p = (s32)&D_800D7720;
    row = 0;
    while (1) {
        j = 0;
        if (i >= 20) {
            break;
        }
        off = row;
        do {
            *(s32 *)(off + p + 0x20) = 0;
            j++;
            off += 4;
        } while (j < 20);
        row += 0x50;
        i++;
    }
    q = (s32)&D_800D7720;
    *(s32 *)(q + 0x660) = 0;
    i = 0;
    p = q;
    row = 0;
    while (1) {
        j = 0;
        if (i >= 20) {
            break;
        }
        off = row;
        do {
            *(s32 *)(off + p + 0x680) = 0;
            j++;
            off += 4;
        } while (j < 20);
        row += 0x50;
        i++;
    }
}
