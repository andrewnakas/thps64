/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx31240;

typedef struct {
    u8 pad0[0x34];
    s32 v34;
    u8 pad38[0x3E - 0x38];
    u8 b3E;
    u8 pad3F;
    u8 b40;
    u8 pad41;
    u8 b42;
    u8 pad43;
    u8 b44;
    u8 pad45[0x4A - 0x45];
    u8 b4A;
    u8 pad4B[0x298 - 0x4B];
    u8 a298[0x55C - 0x298];
    u8 a55C[0x584 - 0x55C];
    u8 a584[0x5AC - 0x584];
    u8 a5AC[0x5D4 - 0x5AC];
    u8 a5D4[0x5FC - 0x5D4];
    u8 a5FC[0x630 - 0x5FC];
    f32 f630;
    s16 h634;
    u8 pad636[2];
    s16 h638;
    u8 pad63A[2];
    s16 h63C;
    u8 pad63E[2];
    s16 h640;
    u8 pad642[0x64A - 0x642];
    s16 h64A;
    u8 pad64C[2];
    s16 h64E;
    s16 h650;
    u8 pad652[0x656 - 0x652];
    s16 h656;
    u8 pad658[0x65C - 0x658];
    s16 h65C;
    u8 pad65E[2];
    s16 h660;
    u8 pad662[2];
    s16 h664;
    u8 pad666[0x66A - 0x666];
    s16 h66A;
    s16 h66C;
    s16 h66E;
    u8 pad670[0x674 - 0x670];
    s16 h674;
    s16 h676;
} Obj31240;

void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
extern char D_80019B08[];
extern char D_80019B10[];
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F329C;
extern Gfx31240 *D_800F36A4;

void func_80031240(Obj31240 *o) {

    switch (o->b4A) {
    case 0:
        func_800B1AC4(o->a5D4, o->h638, o->h656, 0.925f, 0.95f);
        func_800B1AC4(o->a5AC, o->h63C, 223.0f, o->f630, o->f630);
        func_800B1AC4(o->a5FC, o->h664, o->h66A, 0.925f, 0.95f);
        {
            Gfx31240 *_g = (Gfx31240 *)(D_800F36A4++);
            f32 s = D_800F329C;
            _g->w0 = ((((s32)((f32)(s32)(s * 162.0f) * 4.0f)) & 0xFFF) << 12) | 0xED00020C;
            _g->w1 = ((((s32)((f32)(s32)(s * 222.0f) * 4.0f)) & 0xFFF) << 12) | 0x414;
        }
        if (o->b40 != o->b3E) {
            func_800B1AC4(o->a584, o->h64E, o->h650, o->f630, 0.45f);
        }
        func_800B1AC4(o->a55C, o->h634, o->h64A, o->f630, 0.45f);
        break;
    case 1:
        func_800B1AC4(o->a55C, o->h634, 141.0f, o->f630, 0.45f);
        func_800B1AC4(o->a5AC, o->h63C, 223.0f, o->f630, o->f630);
        func_800B1AC4(o->a5FC, o->h66C, o->h66E, 0.925f, 0.95f);
        func_800B1AC4(o->a5D4, o->h638, o->h656, 0.925f, 0.95f);
        break;
    case 2:
        func_800B1AC4(o->a55C, o->h634, 141.0f, o->f630, 0.45f);
        func_800B1AC4(o->a5D4, o->h638, o->h656, 0.925f, 0.95f);
        func_800B1AC4(o->a5FC, o->h674, o->h676, 0.925f, 0.95f);
        {
            Gfx31240 *_g = (Gfx31240 *)(D_800F36A4++);
            f32 s = D_800F329C;
            _g->w0 = ((((s32)((f32)(s32)(s * 267.0f) * 4.0f)) & 0xFFF) << 12) | 0xED000360;
            _g->w1 = ((((s32)((f32)(s32)(s * 320.0f) * 4.0f)) & 0xFFF) << 12) | 0x410;
        }
        if (o->b42 != o->b44) {
            func_800B1AC4(o->a584, o->h65C, o->h660, o->f630, o->f630);
        }
        func_800B1AC4(o->a5AC, o->h63C, o->h640, o->f630, o->f630);
        break;
    }
    {
        Gfx31240 *_g = (Gfx31240 *)(D_800F36A4++);
        _g->w0 = 0xED000000;
        _g->w1 = ((((s32)((f32)(D_800F3294 - 1) * 4.0f)) & 0xFFF) << 12) | (((s32)((f32)(D_800F3298 - 1) * 4.0f)) & 0xFFF);
    }
    if (o->v34 != 0) {
        func_800A8678(o->a298, D_80019B08, 239.0f, 305.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
        func_800A8678(o->a298, D_80019B10, 239.0f, 285.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    }
}
