/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 a, b;
} Pair;

typedef struct {
    s32 unk0[7];
    s32 unk1C;
    s32 unk20[12];
    Pair unk50[5];
    s32 unk78[18];
} Big;

typedef struct {
    s32 unk0;
    Pair unk4[5];
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
} Out;

typedef struct Player {
    u8 pad0[0x1C];
    struct Player *unk1C;
    u8 pad20[0x3E2 - 0x20];
    s16 unk3E2;
} Player;

extern s16 D_800C0E22;
extern Player *D_800D61A8;
extern Big D_800DC618;
extern Big D_800DC6D8;
extern s16 D_800DE7A2;
extern s16 D_800DE9AA;

void func_8006A854(Out *arg0, s32 arg1) {
    Big local;
    s32 i;
    Player *p;
    Player *q;

    if (arg1 != 0) {
        local = D_800DC6D8;
    } else {
        local = D_800DC618;
    }
    arg0->unk0 = local.unk1C;
    for (i = 0; i < 5; i++) {
        arg0->unk4[i] = local.unk50[i];
    }
    arg0->unk2C = D_800DE9AA;
    p = D_800D61A8;
    q = p->unk1C;
    switch (arg1) {
    case 0:
        arg0->unk2E = p->unk3E2;
        if (q != NULL) {
            arg0->unk30 = q->unk3E2;
        }
        break;
    case 1:
        arg0->unk2E = q->unk3E2;
        if (q != NULL) {
            arg0->unk30 = p->unk3E2;
        }
        break;
    }
    arg0->unk32 = D_800C0E22;
    arg0->unk34 = D_800DE7A2;
    arg0->unk36 = 0;
}
