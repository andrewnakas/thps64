/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0xC];
    u16 flags;
} P37540;

typedef struct {
    f32 f0;
    u8 pad4[0xC];
    Vec3 pos;
} Q37540;

typedef struct {
    u8 pad0[0x68];
    s32 hit;
    u8 pad6C[0x80 - 0x6C];
    P37540 *p80;
    u8 pad84[0x88 - 0x84];
    u8 b88;
    u8 pad89[0xA4 - 0x89];
    Vec3 a;
    Vec3 b;
    u8 padBC[0xF8 - 0xBC];
    Q37540 *pF8;
    u8 padFC[0x100 - 0xFC];
} Ctx37540;

typedef struct {
    u8 pad0[0x20];
    Vec3 v20;
    u8 pad2C[4];
    Vec3 v30;
} G37540;

void func_8005CCD8(Ctx37540 *, s32);
void func_8005DF8C(Ctx37540 *, s32);
s32 func_800B4240(s32, s32);
s32 func_800B4264(s32, s32);
void func_800A6C08(void *, Vec3 *);
void func_800BE7D0(s32, s32, s32, s32, u8, s32, s32, s32);
extern G37540 D_800FA670;

void func_80037540(u8 *o) {
    Ctx37540 ctx;
    Ctx37540 *c;
    Vec3 r;
    Vec3 m;
    Vec3 s;
    f32 x, y, z;
    f32 k, k2, k3;
    f32 x1, y1, z1, x2, y2, z2;
    f32 f;
    s32 cr, cg, cb;

    c = &ctx;
    ctx.a = D_800FA670.v30;
    k = 200.0f;
    x1 = D_800FA670.v20.x * k;
    y1 = D_800FA670.v20.y * k;
    z1 = D_800FA670.v20.z * k;
    m.x = x1;
    m.y = y1;
    m.z = z1;
    x2 = ctx.a.x + m.x;
    y2 = ctx.a.y + m.y;
    z2 = ctx.a.z + m.z;
    r.x = x2;
    r.y = y2;
    r.z = z2;
    ctx.b = r;
    k2 = 16.0f;
    ctx.a.x *= k2;
    ctx.a.y *= k2;
    ctx.a.z *= k2;
    ctx.b.x *= k2;
    ctx.b.y *= k2;
    ctx.b.z *= k2;
    func_8005CCD8(c, 1);
    cr = func_800B4240(1, 0x8000);
    if (cr) {
        ctx.b88 = 1;
    }
    func_8005DF8C(c, 1);
    r.z = 0.0f;
    r.y = 0.0f;
    r.x = 0.0f;
    if (ctx.hit) {
        r = ctx.pF8->pos;
    }
    if (!func_800B4240(0, 0x100)) {
        k3 = 0.0625f;
        x = r.x * k3;
        y = r.y * k3;
        z = r.z * k3;
        s.x = x;
        s.y = y;
        s.z = z;
        func_800A6C08(o + 0x710, &s);
    }
    func_800B4264(0, 0x400);
    if (ctx.hit) {
        f = ctx.pF8->f0;
        if (ctx.p80->flags & 2) {
            cr = 0;
            do { cg = 0xFF; } while (0);
            cb = cr;
        } else {
            cg = cr = 0;
            cb = 0xFF;
        }
        func_800BE7D0(0x28, f * 250.0f + 45.0f, 0x28, 0x32, cr, cg, cb, 0xFF);
    } else {
        func_800BE7D0(0x28, 0x3C, 0x28, 0x32, 0xFF, 0, 0, 0xFF);
    }
}
