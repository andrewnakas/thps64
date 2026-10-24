/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} SmpEnt;

typedef struct {
    u8 pad0[0x18];
    SmpEnt ents[1];
} Smp;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x28];
    f32 unk30;
    u8 pad34[0x14];
    s32 unk48;
    u8 pad4C[0x2C];
    s32 unk78;
    u8 pad7C[0x4F];
    u8 unkCB;
    u8 unkCC;
    u8 padCD[0x63];
} Voice;

s32 func_800ADEEC(Voice *, Smp *, s32, s32, s32, s32);
extern s32 D_800FC2F0;
extern Voice *D_800FC2FC;

s32 func_800AE068(Smp *arg0, s32 arg1, s32 arg2, s32 arg3, s32 prio, s32 vol, f32 arg6) {
    Voice *v;
    void *best;
    s32 i;
    s32 low;

    if (prio == -1) {
        prio = arg0->ents[arg1].unk4;
    }
    i = 4;
    v = D_800FC2FC;
    low = prio + 1;
    for (; i < D_800FC2F0; i++, v++) {
        if (v->unk4 == 0) {
            v->unk30 = arg6;
            if (vol < 0) {
                vol = 0;
            } else if (vol >= 0x80) {
                vol = 0x7F;
            }
            v->unkCB = vol;
            v->unkCC = 0xFF;
            best = arg0;
            return func_800ADEEC(v, best, arg1, arg2, arg3, prio);
        }
        if (v->unk78 != 0 && v->unk48 < low) {
            low = v->unk48;
            best = v;
        }
    }
    if (low < prio) {
        v->unk30 = arg6;
        if (vol < 0) {
            vol = 0;
        } else if (vol >= 0x80) {
            vol = 0x7F;
        }
        v->unkCB = vol;
        v->unkCC = 0xFF;
        return func_800ADEEC(best, arg0, arg1, arg2, arg3, prio);
    }
    return 0;
}
