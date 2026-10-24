#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x14 - 0x8];
} Snd80084F00;

typedef struct {
    u8 pad[0x240];
} Font80084F00;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    u8 pad8[0xA0 - 0x8];
    u8 unkA0[0x18];
    u8 padB8[0xD4 - 0xB8];
    f32 col[15];
    u8 pad110[4];
    Snd80084F00 snd[5];
    s32 res[4];
    Font80084F00 fonts[8];
    s32 unk1388;
    u8 pad138C[0x594C - 0x138C];
    f32 unk594C[4];
} Menu80084F00;

extern void func_8008B490(void *, Font80084F00 *, s32);
extern void func_8008BB2C(void *, s32);
extern void func_8008BB50(void *);
extern void func_8009E0F0(void *, s32, s32);
extern void func_800A72C0(Font80084F00 *);
extern void func_800A73EC(Font80084F00 *, s32);
extern void func_800A7708(Font80084F00 *, f32);
extern void func_800B198C(Snd80084F00 *);
extern void func_800B1A80(Snd80084F00 *, s32);
extern s32 func_800BAB04(void *, s32);
extern u8 D_800EECF0[];
extern s32 D_800DE9B8;
extern s32 D_800DE9BC;
extern s32 D_800DE9C0;

Menu80084F00 *func_80084F00(Menu80084F00 *this) {
    u8 save[8];
    Font80084F00 *f;
    s32 i;
    u8 *r;
    f32 k;

    func_800B198C(&this->snd[0]);
    func_800B198C(&this->snd[1]);
    func_800B198C(&this->snd[2]);
    func_800B198C(&this->snd[3]);
    func_800B198C(&this->snd[4]);
    for (f = this->fonts, i = 7; i != -1; i--, f++) {
        func_800A72C0(f);
    }
    func_8008BB50(save);
    this->unk0 = 0;
    this->unk1388 = 0;
    this->unk2 = 0;
    func_800A73EC(&this->fonts[1], 2);
    func_800A73EC(&this->fonts[2], 0x4C6);
    func_800A7708(&this->fonts[2], 0.135f);
    func_8008B490(save, &this->fonts[2], 0x4C6);
    func_800A73EC(&this->fonts[5], 0x4C7);
    func_800A7708(&this->fonts[5], 0.2f);
    func_8008B490(save, &this->fonts[5], 0x4C7);
    func_800A73EC(&this->fonts[6], 0x4C8);
    k = 0.1f;
    func_800A7708(&this->fonts[6], k);
    func_8008B490(save, &this->fonts[6], 0x4C8);
    func_800A73EC(&this->fonts[7], 0x501);
    func_800A7708(&this->fonts[7], k);
    func_8008B490(save, &this->fonts[7], 0x501);
    this->col[0] = 1.0f;
    this->col[1] = 1.0f;
    this->col[2] = 0.9f;
    this->col[3] = 1.0f;
    this->col[4] = 1.0f;
    this->col[5] = 0.8f;
    this->col[6] = 0.8f;
    this->col[8] = 1.0f;
    this->col[9] = 1.0f;
    this->col[10] = 0.9f;
    this->col[11] = 1.0f;
    this->col[12] = 1.0f;
    this->col[13] = 1.0f;
    this->col[14] = 0.9f;
    D_800DE9BC = 6;
    D_800DE9C0 = 5;
    D_800DE9B8 = 2;
    this->unk594C[0] = 1.0f;
    this->unk594C[1] = 1.0f;
    this->unk594C[2] = 1.0f;
    this->unk594C[3] = 1.0f;
    func_800B1A80(&this->snd[0], 0xC7);
    this->snd[0].unk4 = 1;
    func_800B1A80(&this->snd[1], 0xC6);
    this->snd[1].unk4 = 1;
    func_800B1A80(&this->snd[2], 0xC7);
    this->snd[2].unk4 = 1;
    func_800B1A80(&this->snd[3], 0xC6);
    this->snd[3].unk4 = 1;
    r = D_800EECF0;
    this->res[0] = func_800BAB04(r, 0x5C4);
    this->res[1] = func_800BAB04(r, 0x5C5);
    this->res[2] = func_800BAB04(r, 0x586);
    this->res[3] = func_800BAB04(r, 0x587);
    func_800B1A80(&this->snd[4], 0xD2);
    this->snd[4].unk4 = 1;
    this->unk4 = 0;
    func_8009E0F0(this->unkA0, 0, 0x18);
    func_8008BB2C(save, 2);
    return this;
}
