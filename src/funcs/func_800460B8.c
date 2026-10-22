#include "common.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 time;
    s32 e;
} Ent800460B8;

typedef struct {
    u8 pad0[4];
    s32 score;
    u8 pad8[0x140 - 0x8];
    s32 unk140;
    u8 pad144[0x148 - 0x144];
    s32 unk148;
    s32 unk14C;
    s32 unk150;
    s32 unk154;
    u8 pad158[0x1F8 - 0x158];
    Ent800460B8 ent[20];
    s32 count;
    u8 pad38C[0x4C0 - 0x38C];
    s32 unk4C0;
    u8 pad4C4[0x4F4 - 0x4C4];
    s32 unk4F4;
} Obj800460B8;

void func_800057E4(char *, void *, s32, s32);
void func_80045A70(Obj800460B8 *);
extern s32 D_8001B298;
extern s32 D_800D60FC;

void func_800460B8(Obj800460B8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[128];
    void *fmt;
    s32 t;
    Ent800460B8 *e;

    arg0->unk154 = 1;
    if (D_800D60FC != 0) {
        arg2 *= 10;
    }
    fmt = &D_8001B298;
    func_800057E4(buf, fmt, arg0->score, arg1);
    t = arg0->unk4C0;
    if (t < 3) {
        if (t >= 0) {
            if (arg2 > 0) {
                if (arg0->count == 0) {
                    arg0->score += arg0->unk140;
                    arg0->unk140 = 0;
                    arg0->unk148 = 0;
                    arg0->unk4F4 = 0;
                }
                e = (Ent800460B8 *)(arg0->count * 20 + (s32)arg0 + 0x1F8);
                e->e = 0;
                e->a = arg1;
                e->b = arg2;
                e->c = arg3;
                e->time = 0x12;
                if (arg0->count < 0x13) {
                    arg0->count++;
                }
            }
        }
    }
    if (arg0->count != 0) {
        arg0->unk14C = 1;
        arg0->unk150 = 0;
        func_80045A70(arg0);
    } else {
        arg0->unk14C = 0;
    }
}
