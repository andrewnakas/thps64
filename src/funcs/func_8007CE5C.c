/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u8 r, g, b;
    u8 padF;
    s16 unk10;
    u8 pad12[0x24 - 0x12];
} Key;

typedef struct {
    u8 pad0[0x44];
    void *vt;
    u8 pad48[4];
    s32 n;
    Key *keys;
    u8 pad54[0x88 - 0x54];
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
} Fx;

void func_8007C68C(Fx *, s32, s32);
s32 func_80049D60(s32);
void func_8007C5D0(Fx *, u8, u8, u8);
void func_8007C598(Fx *, u16);
void func_8007CD00(Fx *, u8, u8, u8, s32);
extern u8 D_8001E188[];

Fx *func_8007CE5C(Fx *this, u8 r, u8 g, u8 b, s32 arg4, s32 n, s32 arg6, s32 d, s32 a8, s32 a9, s32 a10, s32 a11,
                  s32 a12, s32 a13) {
    s32 r2, g2, b2;

    func_8007C68C(this, n + 1, 0);
    this->vt = D_8001E188;
    this->unk88 = a8;
    this->unk94 = a9;
    this->unk8C = a10;
    this->unk98 = a12;
    this->unk90 = a11;
    this->unk9C = a13;
    this->unkA0 = func_80049D60(0x1000);
    func_8007C5D0(this, r, g, b);
    this->keys[0].r = this->keys[this->n - 1].r = r >> 1;
    this->keys[0].g = this->keys[this->n - 1].g = g >> 1;
    this->keys[0].b = this->keys[this->n - 1].b = b >> 1;
    func_8007C598(this, d / 20);
    this->keys[0].unk10 = this->keys[this->n - 1].unk10 = d / 40;
    r2 = r * 2;
    if (r2 >= 0x100) {
        r2 = 0xFF;
    }
    g2 = g * 2;
    if (g2 >= 0x100) {
        g2 = 0xFF;
    }
    b2 = b * 2;
    if (b2 >= 0x100) {
        b2 = 0xFF;
    }
    func_8007CD00(this, r2, g2, b2, d / 80);
    return this;
}
