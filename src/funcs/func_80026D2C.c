#include "common.h"

typedef struct {
    u8 pad0[0x208];
    s32 unk208;
    u8 pad20C[0x228 - 0x20C];
    s32 unk228;
    u8 pad22C[0x28C - 0x22C];
    s32 unk28C;
    u8 pad290[0xF18 - 0x290];
    u8 unkF18[0x2208 - 0xF18];
    f32 unk2208[16];
    u8 pad2248[0x2290 - 0x2248];
    f32 unk2290[16];
} Obj80026D2C;

void func_80084CB8(void *, f32 *, s32);
void func_8009C8EC(f32 *, f32 *);
void func_8009D3F0(f32 *, f32);
void func_8009D8B4(f32 *, f32 *);

void func_80026D2C(Obj80026D2C *arg0) {
    f32 m[16];
    f32 v[3];
    f32 h;
    f32 x;
    f32 s;
    f32 *pm;
    f32 *pv;
    s32 t;

    pm = m;
    func_8009C8EC(pm, arg0->unk2208);
    t = arg0->unk208 & 2;
    h = 0.5f;
    x = h;
    if (t) {
        x = -h;
    }
    pv = v;
    v[0] = x;
    v[1] = h;
    v[2] = h;
    func_8009D8B4(pm, pv);
    func_8009D3F0(pm, 3.1415927f);
    arg0->unk228 = 0x10000;
    s = 0.0625f;
    v[0] = s;
    v[1] = s;
    v[2] = s;
    func_8009D8B4(pm, pv);
    m[12] *= s;
    m[13] *= s;
    m[14] *= s;
    func_80084CB8(arg0->unkF18, pm, arg0->unk28C);
    func_8009C8EC(arg0->unk2290, pm);
}
