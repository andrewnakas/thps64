#include "common.h"

void func_8003E1C8(void);
extern s32 D_800DE7F8;
extern u8 D_800DE9F4[];

void func_80068FB0(void) {
    s32 base;
    s32 ff;
    u8 *p;
    s32 row;
    s32 j;
    u8 *end;

    if (D_800DE7F8 != 0) {
        base = (s32)D_800DE9F4;
        ff = 0xFF;
        p = (u8 *)base;
        row = 0;
        end = p + 0xDC;
        while (1) {
            j = 0;
            if ((s32)p >= (s32)end) {
                break;
            }
            p[8] = 0;
            p[0xB] = 0;
            p[0xA] = 0;
            p[9] = 0;
            do {
                *(u8 *)(j + row + base + 0xC) = ff;
                p[8] += 5;
                p[0xB] += 1;
                p[0xA] += 1;
                p[9] += 1;
                j++;
            } while (j < 10);
            p += 0x14;
            row += 0x14;
        }
    }
    func_8003E1C8();
}
