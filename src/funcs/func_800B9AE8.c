/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx9AE8;

typedef struct {
    f32 u;
    f32 v;
    f32 du;
    f32 dv;
    s32 done;
} Scroll;

extern s32 D_800F36C0;
extern s32 *D_800F36C4[];
extern f32 D_800F5668;
extern Gfx9AE8 *D_800F36A4;

void func_800B9AE8(Scroll *o, s32 w, s32 h, s32 tile) {
    s32 uls;
    s32 ult;

    if (o->done == 0) {
        o->done = 1;
        D_800F36C4[D_800F36C0++] = &o->done;
        o->u += o->du * D_800F5668;
        while (o->du > 0.0f && o->u > 1.0f) {
            o->u -= 1.0f;
        }
        while (o->du < 0.0f && o->u < 0.0f) {
            o->u += 1.0f;
        }
        o->v += o->dv * D_800F5668;
        while (o->dv > 0.0f && o->v > 1.0f) {
            o->v -= 1.0f;
        }
        while (o->dv < 0.0f && o->v < 0.0f) {
            o->v += 1.0f;
        }
    }
    if (o->done > 0) {
        Gfx9AE8 *_g = D_800F36A4++;
        uls = o->u * w * 4.0f;
        ult = o->v * h * 4.0f;
        _g->w0 = (0xF2 << 24) | ((uls & 0xFFF) << 12) | (ult & 0xFFF);
        _g->w1 = ((tile & 7) << 24) | (((w * 4 + uls - 1) & 0xFFF) << 12) | ((h * 4 + ult - 1) & 0xFFF);
    }
}
