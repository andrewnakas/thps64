/* cflags: -O2 */
/* D4 (from K17 draft): D_800F36A4 is volatile here and the list is built from a local base (D_800F36A4 = g; then &g[i+1] per command), so every pointer store is kept like the game; the f64 accumulate sits before the list. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxBE3D8;

s32 *func_800BC154(void *, s32, s32);
void func_800B9D6C(void);
void func_800BFDD4(void);
void func_800BD740(s32, s32, s32, s32);
extern u8 D_800F0DD0[];
extern s32 D_800F32C0;
extern s32 D_800F32AC;
extern s32 D_800EECE8;
extern f32 D_800F32A0;
extern s32 D_800F36B8;
extern f32 D_800F30F4;
extern f32 D_800F5668;
extern s32 D_800FC8C0;
extern GfxBE3D8 *D_800FC8B0[];
extern s32 D_800F32B8;
extern GfxBE3D8 *volatile D_800F36A4;
extern f64 D_800F32B0;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F32A8;
extern u8 D_800F35E0[];
extern s32 D_800F5628;
extern s32 D_800F562C;

void func_800BE3D8(void) {
    s32 *p;
    GfxBE3D8 *g;

    D_800F32AC = 1;
    D_800EECE8 = -1;
    p = func_800BC154(D_800F0DD0, D_800F32C0, 4);
    D_800F36B8 = p[0];
    if (D_800F32A0 == 0.0f) {
        D_800F5668 = (f32)p[1] * D_800F30F4;
    } else {
        D_800F5668 = D_800F32A0;
    }
    func_800B9D6C();
    D_800FC8C0 = 0;
    D_800F32B0 += D_800F5668;
    g = D_800FC8B0[D_800F32B8];
    D_800F36A4 = g;
    {
        GfxBE3D8 *_g = &g[0];
        D_800F36A4 = &g[1];
        _g->w0 = 0xDB060000;
        _g->w1 = 0;
    }
    {
        GfxBE3D8 *_g = &g[1];
        D_800F36A4 = &g[2];
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxBE3D8 *_g = &g[2];
        D_800F36A4 = &g[3];
        _g->w0 = 0xFF100000 | ((D_800F3294 - 1) & 0xFFF);
        _g->w1 = D_800F36B8;
    }
    {
        GfxBE3D8 *_g = &g[3];
        D_800F36A4 = &g[4];
        _g->w0 = 0xFE000000;
        _g->w1 = D_800F32A8;
    }
    {
        GfxBE3D8 *_g = &g[4];
        D_800F36A4 = &g[5];
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxBE3D8 *_g = &g[5];
        D_800F36A4 = &g[6];
        _g->w0 = 0xDE000000;
        _g->w1 = (u32)D_800F35E0;
    }
    func_800BFDD4();
    func_800BD740(0, D_800F3294 - 1, 0, D_800F3298 - 1);
    D_800F5628 = 0x170000;
    D_800F562C = -1;
}
