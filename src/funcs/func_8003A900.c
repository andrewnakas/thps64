/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    void *p2C;
    s8 b30;
    u8 pad31[3];
    u8 a34[0x14];
    u8 a48[0x298 - 0x48];
    f32 f298;
    u8 pad29C[0x2A8 - 0x29C];
    s32 v2A8;
    u8 pad2AC[0x6B8 - 0x2AC];
    u8 a6B8[4];
    s32 v6BC;
    u8 pad6C0[0x6CC - 0x6C0];
    u8 a6CC[4];
    s32 v6D0;
    u8 pad6D4[0x6E0 - 0x6D4];
    s32 v6E0;
    s16 h[18];
    u8 b708;
    u8 pad709[3];
    f32 f70C;
    s32 v710;
} O3A900;

void func_80039500(void);
void func_800B198C(void *);
void func_8003BDC0(void *);
void func_8003A69C(void *);
void func_8003A8B4(void *);
void func_800242CC(void);
void func_8003C1A4(void *, s32, void *, s32, void *, s32, void *, s32, void *, s32, void *, s32, void *, s32);
void func_800B1A80(void *, s32);
void func_8003C838(void *, s32, s32);
extern u8 D_80019FC0[];
extern char D_80019F70[];
extern char D_80019F7C[];
extern u8 D_800D3F34[];
extern s32 D_800D4670;
extern f32 D_800ECEF0;
extern f32 D_800EA9B0;
extern u8 D_800D0FC3;
extern void *D_800DDC80[];

O3A900 *func_8003A900(O3A900 *o) {
    func_80039500();
    o->p2C = D_80019FC0;
    func_800B198C(o->a34);
    func_8003BDC0(o->a48);
    func_800B198C(o->a6B8);
    func_800B198C(o->a6CC);
    func_8003A69C(D_800D3F34);
    func_8003A8B4(D_800D3F34);
    {
        f32 f = D_800D4670;
        D_800ECEF0 = f;
        D_800EA9B0 = f;
    }
    func_800242CC();
    o->b30 = -1;
    o->v6E0 = 0;
    func_8003C1A4(o->a48, 6, D_800DDC80[0x3C / 4], 0x12, D_800DDC80[0x44 / 4], 0x14, D_800DDC80[0x40 / 4], 0x13,
                  D_80019F70, 0x15, D_800DDC80[0x1C4 / 4], 0x18, D_80019F7C, 0x17);
    o->f298 = 320.0f;
    o->v2A8 = 0x14A;
    func_800B1A80(o->a34, 0x98);
    if (D_800D0FC3 >= 4) {
        func_8003C838(o->a48, 1, 3);
    }
    func_800B1A80(o->a6B8, 3);
    o->v6BC = 1;
    func_800B1A80(o->a6CC, 2);
    o->v6D0 = 1;
    o->f70C = 0.5f;
    o->v710 = 1;
    o->b708 = 0;
    o->h[0] = 0x9B;
    o->h[1] = 0x1CE;
    o->h[2] = 0x8A;
    o->h[3] = 0x99;
    o->h[4] = 0x1D4;
    o->h[5] = 0xAE;
    o->h[6] = 0x87;
    o->h[7] = 0x1E3;
    o->h[8] = 0xCE;
    o->h[9] = 0xAD;
    o->h[10] = 0x1BD;
    o->h[11] = 0xF0;
    o->h[12] = 0xCB;
    o->h[13] = 0x1A1;
    o->h[14] = 0x112;
    o->h[15] = 0xD2;
    o->h[16] = 0x19A;
    o->h[17] = 0x135;
    return o;
}
