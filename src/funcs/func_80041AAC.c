/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* D3: one shared increment behind nested bit tests (no fold to & 0xE0, arg0 refs counted once), block-scoped base pointer for the last D_800D5C1C index. */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x3C - 0x14];
    s32 unk3C;
    s32 unk40;
    u8 pad44[0x78 - 0x44];
} E78;

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
    u8 unkC[8];
} E14;

extern u32 D_800C0E20;
extern u8 D_800D0FC0[];
extern u8 D_800D0FD4;
extern E78 D_800D5C1C[];
extern s32 D_800DE9A8;
extern E14 D_800DE9F4[];

void func_80041AAC(u8 *arg0) {
    s32 i;
    s32 step;
    u8 f;
    E78 *e;

    if (D_800D5C1C[D_800C0E20].unk3C > 0) {
        if (D_800DE9F4[D_800D0FD4].unk8 >= D_800D5C1C[D_800C0E20].unk3C) {
            D_800D5C1C[D_800C0E20].unk10 = 0;
        } else {
            D_800D5C1C[D_800C0E20].unk10 = 1;
        }
    } else if (D_800D5C1C[D_800C0E20].unk40 > 0) {
        arg0[0x2B6] = 0;
        step = 3;
        for (i = step; i < 9; i += step, step--) {
            f = D_800DE9F4[D_800D0FC0[0x14]].unkC[i];
            if (!(f & 0x80)) {
                if (!(f & 0x40)) {
                    if (!(f & 0x20)) {
                        continue;
                    }
                }
            }
            arg0[0x2B6]++;
        }
        {
            E78 *base = D_800D5C1C;
            e = base + D_800C0E20;
        }
        if (arg0[0x2B6] >= e->unk40) {
            e->unk10 = 0;
        } else {
            e->unk10 = 1;
        }
    }
    if (D_800DE9A8 == 2 && D_800C0E20 < 5) {
        D_800D5C1C[D_800C0E20].unk10 = 0;
    }
}
