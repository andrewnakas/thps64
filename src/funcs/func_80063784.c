#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    s32 *data;
    u8 pad20[0x48 - 0x20];
} Entry_63784;

s32 *func_8005EAB4(s32, s32, s32);
extern Entry_63784 D_800DAF98[];
extern s32 *D_800DC2E0[];

void func_80063784(s32 arg0) {
    s32 *src;
    s32 *dst;
    s32 size;
    s32 i;

    src = D_800DAF98[arg0].data;
    size = 0x7530;
    dst = func_8005EAB4(size, 1, 1);
    D_800DC2E0[arg0] = dst;
    i = 0;
    while (1) {
        if (i >= size / 4) {
            break;
        }
        i++;
        *dst = *src;
        src++;
        dst++;
    }
}
