/* cflags: -O2 */
#include "common.h"

void func_800A5F10(void *);
s32 func_8009E6B4(void *, s32, s32);
void *func_8009CAD0(void *);
void func_800A4624(void *, void *);
void func_800A4418(void *, f32, f32, f32, f32, f32, f32);
void func_800A62C4(void *, s32, s32, s32, s32);
void func_80001A30(void *, void *);
extern u8 D_80021810[];
extern u8 D_800EA110[];
extern s32 D_800F3294;
extern s32 D_800F3298;

typedef struct {
    u8 pad0[0x1C];
    void *vt;
    u8 pad20[0x60 - 0x20];
    u8 m60[0x40];
    u8 mA0[0x40];
    u8 mE0[0x98];
    s32 unk178;
    u8 pad17C[4];
    u8 unk180;
    u8 pad181[3];
    s32 unk184;
    u8 pad188[0x3A0 - 0x188];
    u8 unk3A0;
    u8 pad3A1[0x658 - 0x3A1];
    u8 m658[0x40];
    u8 m698[0x40];
    s32 unk6D8;
    u8 unk6DC;
} Cam;

Cam *func_800A3FB0(Cam *this) {
    u8 tmp[0x40];
    s32 i;

    func_800A5F10(this);
    this->vt = D_80021810;
    i = 5;
    do {
        i--;
    } while (i != -1);
    i = 5;
    do {
        i--;
    } while (i != -1);
    i = 5;
    do {
        i--;
    } while (i != -1);
    i = 5;
    do {
        i--;
    } while (i != -1);
    i = 8;
    do {
        i--;
    } while (i != -1);
    i = 0;
    do {
        i--;
    } while (i != -1);
    i = 3;
    do {
        i--;
    } while (i != -1);
    this->unk6DC = 0;
    this->unk184 = func_8009E6B4(D_800EA110, 0x40, 8);
    func_8009CAD0(this->mE0);
    func_8009CAD0(this->mA0);
    func_8009CAD0(this->m60);
    func_800A4624(this, func_8009CAD0(tmp));
    this->unk178 = 7;
    func_800A4418(this, -0.45f, 0.45f, -0.35f, 0.35f, 2.0f, 500.0f);
    func_800A62C4(this, 0, D_800F3294 - 1, 0, D_800F3298 - 1);
    this->unk6D8 = 0;
    this->unk180 = 0;
    this->unk3A0 = 0;
    func_8009CAD0(this->m698);
    func_80001A30(this->m698, this->m658);
    return this;
}
