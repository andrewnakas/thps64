/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx4A50;

typedef struct {
    u8 pad0[0x60];
    f32 m60[4][4];
    f32 mA0[4][4];
    f32 mE0[4][4];
    u8 pad120[0x40];
    f32 p160, p164, p168, p16C, p170, p174;
    s32 unk178;
    u8 pad17C[0x650 - 0x17C];
    u16 unk650;
    u8 pad652[0x6DC - 0x652];
    u8 unk6DC;
} Cam4A50;

void func_8009C8EC(f32 (*)[4], f32 (*)[4]);
void func_8009CBB4(f32 (*)[4], f32);
void func_800A4EBC(Cam4A50 *);
void func_800A4624(Cam4A50 *, f32 (*)[4]);
void func_800A4EA8(Cam4A50 *, s32);
void func_800A4418(Cam4A50 *, f32, f32, f32, f32, f32, f32);
void func_8009CA00(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
void func_8009DC3C(f32 (*)[4]);
s32 func_800BD9F4(void);
void func_80001A30(f32 (*)[4], s32);
void func_8009CAD0(f32 (*)[4]);
void func_800A4E90(Cam4A50 *, s32);
void func_800A602C(Cam4A50 *);
extern Cam4A50 *D_800EA560;
extern Gfx4A50 *D_800F36A4;

void func_800A4A50(Cam4A50 *c) {
    f32 save[4][4];
    f32 rot[4][4];
    f32 mtx[4][4];
    f32 a, b, d, e, f, h;
    s32 mode;
    f32 far;
    s32 p;

    a = c->p160;
    b = c->p164;
    d = c->p168;
    e = c->p16C;
    f = c->p170;
    h = c->p174;
    D_800EA560 = c;
    func_8009C8EC(save, c->m60);
    func_8009CBB4(rot, -1.5707964f);
    rot[3][0] = c->m60[3][0];
    rot[3][2] = c->m60[3][2];
    if (c->unk6DC == 0) {
        rot[3][1] = 2000.0f;
    } else {
        rot[3][1] = -2000.0f;
    }
    func_800A4EBC(c);
    func_800A4624(c, rot);
    mode = c->unk178;
    func_800A4EA8(c, 2);
    far = rot[3][1] + 100.0f;
    func_800A4418(c, -4.5f, 4.5f, -3.5f, 3.5f, 10.0f, far);
    func_8009CA00(mtx, c->mE0, c->mA0);
    func_8009DC3C(mtx);
    p = func_800BD9F4();
    func_80001A30(mtx, p);
    {
        Gfx4A50 *_g = D_800F36A4++;
        _g->w0 = 0xDA380007;
        _g->w1 = p;
    }
    func_8009CAD0(mtx);
    p = func_800BD9F4();
    func_80001A30(mtx, p);
    {
        Gfx4A50 *_g = D_800F36A4++;
        _g->w0 = 0xDA380003;
        _g->w1 = p;
    }
    {
        Gfx4A50 *_g = D_800F36A4++;
        _g->w0 = 0xDB0E0000;
        _g->w1 = c->unk650;
    }
    func_800A4E90(c, mode);
    func_800A4418(c, a, b, d, e, f, h);
    func_800A4624(c, save);
    func_800A602C(c);
}
