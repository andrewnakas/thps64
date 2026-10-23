#include "common.h"

void func_80033D70(s32);
void func_8003925C(void *);
void func_800392E4(void *);
void func_80039500(void *);
void func_8009CAD0(void *);
void func_8009CB68(void *, f32 *);
void func_800A3FB0(void *);
void func_800A4350(void *, f32, f32, f32, f32);
void func_800A5730(void *, s32);
void func_800A68A0(void *);
void func_800A69C0(void *, s32);
extern u8 D_80019E30[];
extern u8 D_800FA670[];

u8 *func_800378BC(u8 *arg0) {
    u8 m[0x40];
    f32 v[3];
    u8 *a;
    u8 *b;
    u8 *c;

    func_80039500(arg0);
    *(u8 **)(arg0 + 0x2C) = D_80019E30;
    a = arg0 + 0x30;
    func_800A3FB0(a);
    b = arg0 + 0x710;
    func_800A68A0(b);
    c = arg0 + 0x798;
    func_800392E4(c);
    func_8003925C(c);
    func_800A5730(a, 1);
    func_800A4350(a, 1.0995574f, 0.8230973f, 20.0f, 625.0f);
    func_80033D70(0xE);
    func_8009CAD0(D_800FA670);
    v[0] = 10.0f;
    v[1] = 10.0f;
    v[2] = 10.0f;
    func_8009CB68(m, v);
    func_800A69C0(b, 0x67);
    return arg0;
}
