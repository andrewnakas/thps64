/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* D4 (from P3/B3b drafts): number formatter. Command records are 0x20 bytes and the final store marks the next record (c[1].unk0 = 1); the value is copied into a local n (n0 param) before the sign flip, which keeps the param in a2 like the game. */
#include "common.h"

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s8 *unk8;
    s32 unkC;
    s8 unk10;
    s8 unk11;
    u8 pad12[0xE];
} Cmd6F280;

extern s32 D_800DDA28;
extern Cmd6F280 *D_800DDA2C;
extern s8 *D_800DDC30;

void func_8006F280(s16 x, s16 y, s32 n0, u8 r, u8 g, u8 b, s32 a) {
    s32 started;
    s32 div;
    s32 q;
    Cmd6F280 *c;
    s32 n = n0;

    D_800DDA2C->unk0 = 0;
    D_800DDA2C->unk4 = x;
    D_800DDA2C->unk6 = y;
    D_800DDA2C->unk10 = 0;
    D_800DDA2C->unk11 = a;
    D_800DDA2C->unk8 = D_800DDC30;
    D_800DDA2C->unkC = D_800DDA28 | (b << 16) | (g << 8) | r;
    if (n < 0) {
        n = -n;
        *D_800DDC30++ = '-';
    }
    started = 0;
    div = 1000000000;
    while (1) {
        if (div <= 0) {
            break;
        }
        if (n >= div) {
            q = n / div;
            *D_800DDC30++ = q + '0';
            n -= q * div;
            started = 1;
        } else if (started || div == 1) {
            *D_800DDC30++ = '0';
        }
        div /= 10;
    }
    *D_800DDC30++ = 0;
    c = D_800DDA2C;
    D_800DDA2C = c + 1;
    c[1].unk0 = 1;
}
