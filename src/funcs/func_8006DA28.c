/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[8];
    s32 unk10;
    u8 pad14[0x10];
} Glyph8006DA28;

typedef struct {
    u8 pad0[0x14];
    Glyph8006DA28 *unk14;
    u8 pad18[2];
    u16 unk1A;
    u8 pad1C[8];
} Font8006DA28;

s32 func_8006DCC4(u8);
extern s32 D_800DC958;
extern Font8006DA28 D_800DCAB4[];
extern u8 D_800DCC1E;

s32 func_8006DA28(u8 *s) {
    s32 max;
    s32 c;
    s32 w;

    if (D_800DCC1E == 0) {
        return 0;
    }
    max = 0;
    while (1) {
        if (*s == 0) {
            break;
        }
        c = func_8006DCC4(*s);
        w = 0;
        if (c < 0xFA || c > 0xFE) {
            if (c != 0xFF) {
                w = D_800DCAB4[D_800DC958].unk14[c].unk4 - D_800DCAB4[D_800DC958].unk14[c].unk10;
            }
        }
        if (max < w) {
            max = w;
        }
        s++;
    }
    return (max * D_800DCAB4[D_800DC958].unk1A) >> 8;
}
