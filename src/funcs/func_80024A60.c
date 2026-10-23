#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx *D_800F36A4;
extern u32 D_800F5628;
extern u32 D_800F5664;
void func_800A6E74(void *, s32, s32, s32, s32);

void func_80024A60(u8 *arg0, s32 arg1) {
    u32 saved;
    Gfx *h;

    if (D_800F5664 < *(u32 *)(arg0 + 0x88)) {
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
        }
        h = D_800F36A4;
        D_800F36A4 = h + 1;
        h[0].w0 = 0xFB000000;
        h[0].w1 = (arg0[0x8C] << 24) | (arg0[0x8D] << 16) | (arg0[0x8E] << 8) | 0xFF;
        D_800F36A4 = h + 2;
        h[1].w0 = 0xFA000000;
        h[1].w1 = (arg0[0x8F] << 24) | (arg0[0x90] << 16) | (arg0[0x91] << 8) | 0xFF;
        D_800F36A4 = h + 3;
        h[2].w0 = 0xE200001C;
        h[2].w1 = 0x0C184240;
        saved = D_800F5628;
        D_800F5628 = saved & ~0x40000;
        func_800A6E74(arg0, arg1, -1, 0, -1);
        D_800F5628 = saved;
    }
}
