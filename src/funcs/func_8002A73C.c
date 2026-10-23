#include "common.h"

void func_80039E60(s32, s32, s32);
extern s32 D_800C0E20;
extern s32 D_800DE7A0;

typedef struct {
    u8 pad0[0x2C0];
    f32 t;
    s32 a;
    s32 b;
    s32 c;
    u8 pad2D0[4];
    s32 fb;
    s32 fa;
    s32 fc;
} S8002A73C;

void func_8002A73C(S8002A73C *arg0) {
    f32 t;
    f32 u;
    f32 v;
    f32 w;

    t = arg0->t;
    if (t < 6.0f) {
        return;
    }
    if (6.0f <= t && t < (w = 16.0f)) {
        if (arg0->fb != 0) {
            arg0->b += 2;
            if (arg0->b >= 0xFF) {
                arg0->fb = 0;
                arg0->b = 0xFF;
            }
        } else {
            arg0->b -= 2;
            if (arg0->b <= 0) {
                arg0->t = w;
            }
        }
        return;
    }
    u = arg0->t;
    if (16.0f <= u && u < (v = 26.0f)) {
        if (arg0->fa != 0) {
            arg0->a += 2;
            if (arg0->a >= 0xFF) {
                arg0->fa = 0;
                arg0->a = 0xFF;
            }
        } else {
            arg0->a -= 2;
            if (arg0->a <= 0) {
                arg0->t = v;
            }
        }
        return;
    }
    if (26.0f <= u && u < (v = 36.0f)) {
        if (arg0->fc != 0) {
            arg0->c += 2;
            if (arg0->c >= 0xFF) {
                D_800DE7A0 = 1;
                D_800C0E20 = 3;
                func_80039E60(0x30, 0x2710, 0);
                D_800C0E20 = 0;
                arg0->fc = 0;
                arg0->c = 0xFF;
            }
        } else {
            arg0->c -= 2;
            if (arg0->c <= 0) {
                arg0->t = v;
            }
        }
    }
}
