/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    s32 pad0;
    s32 v4;
} H5DF8C_20;

typedef struct {
    f32 t;
    f32 r[3];
    Vec3 pos;
    u8 pad1C[4];
    H5DF8C_20 *p20;
    u8 data[1];
} H5DF8C;

typedef struct {
    u8 pad0[0x40];
    s32 v40;
    s32 v44;
    u8 pad48[0x68 - 0x48];
    s32 v68;
    s32 v6C;
    s32 v70;
    s32 v74;
    s16 v78;
    s16 v7A;
    s16 v7C;
    u8 pad7E[0x80 - 0x7E];
    u8 *v80;
    u8 pad84[0xA4 - 0x84];
    Vec3 a;
    Vec3 b;
    u8 padBC[0xC8 - 0xBC];
    f32 scale;
    u8 padCC[0xF8 - 0xCC];
    H5DF8C *h;
} O5DF8C;

void func_80034DFC(O5DF8C *);
void func_80084424(O5DF8C *);
extern s32 D_800D7238;
extern s32 D_800D723C;
extern s32 D_800D7240;
extern s32 D_800D7244;
extern s32 D_800D7248;
extern s32 D_800D7364;
extern s32 D_800D7368;
extern s32 D_800D83E0;

s32 func_8005DF8C(O5DF8C *o, s32 arg1) {
    H5DF8C *h;
    Vec3 r, m, d, a;
    f32 t;
    f32 dx, dy, dz;
    f32 mx, my, mz;
    f32 rx, ry, rz;

    D_800D7368 = 0;
    D_800D7364 = -1;
    if (D_800D7248) {
        D_800D7368 = 0x400000;
    }
    if (D_800D7240) {
        D_800D7368 ^= 0x400000;
    }
    if (!D_800D723C) {
        D_800D7368 ^= 0x200000;
    }
    if (D_800D7238) {
        D_800D7364 = 0xFFEFFFFF;
    }
    if (D_800D7244) {
        D_800D7364 ^= 0x20000;
    }
    D_800D83E0 = -1;
    if (arg1) {
        func_80034DFC(o);
    }
    func_80084424(o);
    h = o->h;
    if (h != NULL) {
        o->v40 = h->t * o->scale;
        o->v44 = o->scale;
        o->v80 = h->data;
        o->v68 = h->p20->v4;
        t = h->t;
        a.x = o->a.x;
        a.y = o->a.y;
        a.z = o->a.z;
        dx = o->b.x - a.x;
        dy = o->b.y - a.y;
        dz = o->b.z - a.z;
        d.x = dx;
        d.y = dy;
        d.z = dz;
        mx = t * d.x;
        my = t * d.y;
        mz = t * d.z;
        m.x = mx;
        m.y = my;
        m.z = mz;
        rx = o->a.x + m.x;
        ry = o->a.y + m.y;
        rz = o->a.z + m.z;
        r.x = rx;
        r.y = ry;
        r.z = rz;
        h->pos = r;
        o->v6C = h->pos.x * 4096.0f;
        o->v70 = h->pos.y * 4096.0f;
        o->v74 = h->pos.z * 4096.0f;
        o->v78 = h->r[0] * 4096.0f;
        o->v7A = h->r[1] * 4096.0f;
        o->v7C = h->r[2] * 4096.0f;
        return 1;
    }
    return 0;
}
