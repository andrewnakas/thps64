/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Glyph {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x10];
} Glyph;

typedef struct Font {
    u8 pad0[0x10];
    s32 unk10;
    Glyph *unk14;
    u8 pad18[2];
    u16 unk1A;
    u8 pad1C[8];
} Font;

extern u8 D_800DCC1E;
extern u8 D_800DD920[];
extern u16 D_800DCAAC;
extern s32 D_800DC958;
extern Font D_800DCAB4[];
s32 func_8006DCC4(u8);

s32 func_8006DB34(u8 *arg0) {
    u8 *p;
    s32 r;

    if (D_800DCC1E == 0) {
        s32 max = 0;
        s32 w = max;
        s32 c;
        while (1) {
            c = *arg0;
            if (c == 0) {
                break;
            }
            c = D_800DD920[c];
            if (c == 0xFE) {
                c = -1;
            }
            if (c == 0xFD) {
                c = -1;
            }
            if (c == 0xFC) {
                c = -1;
            }
            if (c == 0xFB) {
                c = -1;
            }
            if (c == 0xFA) {
                c = -1;
            }
            if (c == 0xFF) {
                c = -1;
            }
            if (c >= 0) {
                if (max < w) {
                    max = w;
                }
            }
            arg0++;
        }
        r = max * D_800DCAAC;
    } else {
        s32 max;
        s32 k;
        s32 w;
        p = arg0;
        max = 0;
        while (1) {
            if (*p == 0) {
                break;
            }
            k = func_8006DCC4(*p);
            w = 0;
            if (k < 0xFA || k > 0xFE) {
                if (k != 0xFF) {
                    w = D_800DCAB4[D_800DC958].unk14[k].unk10;
                }
            }
            if (max < w) {
                max = w;
            }
            p++;
        }
        r = max * D_800DCAB4[D_800DC958].unk1A;
    }
    return r >> 8;
}
