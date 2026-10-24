/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s32 dist;
} Rank;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    u8 pad20[0x30];
    Rank ranks[5];
} Board;

extern void *D_800D61A8;
extern Board D_800DC618;
extern Board D_800DC6D8;
extern s32 D_800DC824;
extern s32 D_800DC934;
extern s32 D_800DC938;
extern s32 D_800DC93C;
extern s32 D_800DC940;

void func_8006A538(u8 *arg0, s32 arg1) {
    Board *b;
    s32 pos;
    u32 neg;
    s32 d;
    s32 i;

    if (arg0 == D_800D61A8) {
        b = &D_800DC618;
    } else {
        b = &D_800DC6D8;
    }
    D_800DC824 = 0;
    D_800DC938 = b->unk1C;
    D_800DC940 = pos = *(s32 *)(arg0 + 8);
    neg = (u32)arg1 >> 31;
    if (arg1 < 0) {
        arg1 = -arg1;
    }
    if (arg1 == 0) {
        d = pos - D_800DC93C;
        if (d < 0) {
            d = D_800DC93C - pos;
        }
        arg1 = (d * 2) >> 12;
    } else {
        d = pos - D_800DC93C;
        if (d < 0) {
            d = D_800DC93C - pos;
        }
        arg1 += d >> 13;
    }
    i = 0;
    for (;;) {
        s32 j;
        if (i >= 5) {
            break;
        }
        if (b->ranks[i].dist < arg1) {
            for (j = 4; i < j; j--) {
                b->ranks[j] = b->ranks[j - 1];
            }
            D_800DC934 -= 15;
            if (D_800DC934 < 0) {
                D_800DC934 = 0;
            }
            if (neg) {
                D_800DC938 += 30;
            } else {
                do { D_800DC938 += 8; } while (0);
            }
            if (D_800DC938 >= 0xE10) {
                D_800DC938 = 0xE0F;
            }
            b->ranks[i].x = D_800DC934;
            b->ranks[i].y = D_800DC938;
            b->ranks[i].dist = arg1;
            return;
        }
        i++;
    }
}
