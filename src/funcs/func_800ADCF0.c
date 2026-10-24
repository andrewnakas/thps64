/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 *ids;
} Snd800ADCF0;

typedef struct {
    u8 pad0[4];
    s32 busy;
    u8 pad8[0x48 - 0x8];
    s32 prio;
    u8 pad4C[0x74 - 0x4C];
    Snd800ADCF0 *owner;
    s32 active;
    u8 pad7C[4];
    s32 id;
    u8 pad84[0x130 - 0x84];
} Voice800ADCF0;

extern s32 D_800FC2F0;
extern Voice800ADCF0 *D_800FC2F8;
extern Voice800ADCF0 *D_800FC2FC;

s32 func_800ADCF0(Snd800ADCF0 *arg0, s32 arg1) {
    Voice800ADCF0 *v;
    s32 i;
    s32 best;
    s32 bi;

    i = 4;
    if (arg1 < 0) {
        for (i = 0, v = D_800FC2F8; i < 4; i++, v++) {
            if (v->busy == 0) {
                return i;
            }
        }
        i = 4;
    }
    v = D_800FC2FC;
    for (; i < D_800FC2F0; i++, v++) {
        if (v->busy == 0) {
            return i;
        }
    }
    i = 4;
    best = 0x7FFFFFFF;
    bi = 3;
    v = D_800FC2FC;
    for (; i < D_800FC2F0; i++, v++) {
        if (v->active != 0 && v->prio <= best) {
            best = v->prio;
            bi = i;
        }
    }
    if (bi >= 4) {
        return bi;
    }
    v = D_800FC2FC;
    for (i = 4; i < D_800FC2F0; i++) {
        if (v->active == 0 && v->owner != arg0) {
            return i;
        }
    }
    v = D_800FC2FC;
    for (i = 4; i < D_800FC2F0; i++, v++) {
        if (v->owner == arg0 && arg0->ids[arg1] == v->id) {
            return i;
        }
    }
    return arg1 % (D_800FC2F0 - 4) + 4;
}
