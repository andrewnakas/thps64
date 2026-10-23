/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 pad5[6];
    u8 unkB;
    u8 padC[3];
    u8 unkF;
    u8 pad10[3];
    u8 unk13;
    u8 pad14[3];
    u8 unk17;
    u8 pad18[8];
} Item4B630;

typedef struct {
    u8 pad0[0x58];
    Item4B630 items[7];
    u8 pad138[0x1C];
} Row4B630;

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[0xB];
} Ent4B630;

typedef struct {
    u8 v[5];
} Col4B630;

extern Row4B630 D_800D4D80[];
extern Col4B630 D_800D62DC[];
extern s32 D_800DE9A8;
extern Ent4B630 D_800DE9F4[];

void func_8004B630(u8 *arg0, s32 arg1) {
    s32 i;
    s32 j;

    if (D_800DE9A8 == 1) {
        for (i = 0; i < 7; i = j) {
            j = i + 1;
            if (D_800DE9F4[*(s32 *)(arg0 + 0x3E0)].unk8 < D_800D4D80[*(s32 *)(arg0 + 0x3E0)].items[j].unk4) break;
        }
        {
            Col4B630 *b = D_800D62DC;
            Col4B630 *c = &b[arg1];
            c->v[0] = D_800D4D80[*(s32 *)(arg0 + 0x3E0)].items[i].unkB;
            c->v[1] = D_800D4D80[*(s32 *)(arg0 + 0x3E0)].items[i].unkF;
            c->v[2] = D_800D4D80[*(s32 *)(arg0 + 0x3E0)].items[i].unk13;
            c->v[3] = D_800D4D80[*(s32 *)(arg0 + 0x3E0)].items[i].unk17;
        }
        return;
    }
    {
        Col4B630 *b = D_800D62DC;
        Col4B630 *c = &b[arg1];
        c->v[0] = 3;
        c->v[1] = 3;
        c->v[2] = 3;
        c->v[3] = 3;
    }
}
