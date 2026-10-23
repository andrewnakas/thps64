/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
#include "common.h"

typedef struct {
    f32 x, y, z;
} V;

typedef struct Obj {
    u8 pad0[4];
    s32 pos[3];
    u8 pad10[0xC];
    struct Obj *next;
    u8 pad20[0x32];
    u16 flags;
    u8 pad54[0x108];
    u16 radius;
} Obj;

Obj *func_8005CA90(s32 *arg0, s32 *arg1, s32 arg2, Obj *arg3, Obj *arg4) {
    V a;
    V b;
    V mid;
    V s;
    V t1;
    V t2;
    V m;
    f32 r;
    f32 ax, ay, az, bx, by, bz, sx, sy, sz, dx, dy, dz, mx, my, mz;
    Obj *o;

    ax = arg0[0] * 0.00024414062f;
    ay = arg0[1] * 0.00024414062f;
    az = arg0[2] * 0.00024414062f;
    a.x = ax;
    a.y = ay;
    a.z = az;
    bx = arg1[0] * 0.00024414062f;
    by = arg1[1] * 0.00024414062f;
    bz = arg1[2] * 0.00024414062f;
    b.x = bx;
    b.y = by;
    b.z = bz;
    t1.x = ax;
    t1.y = ay;
    t1.z = az;
    sx = bx + ax;
    sy = by + ay;
    sz = bz + az;
    s.x = sx;
    s.y = sy;
    s.z = sz;
    mx = sx * 0.5f;
    my = sy * 0.5f;
    mz = sz * 0.5f;
    mid.x = mx;
    mid.y = my;
    mid.z = mz;
    t2.x = ax;
    t2.y = ay;
    t2.z = az;
    dx = bx - ax;
    dy = by - ay;
    dz = bz - az;
    s.x = dx;
    s.y = dy;
    s.z = dz;
    r = __builtin_sqrtf(dx * dx + dy * dy + dz * dz) * 0.5f;
    o = arg3;
    for (;;) {
        f32 rr;
        f32 l;
        f32 px, py, pz;
        if (o == NULL) {
            break;
        }
        if (o->flags & 0x40) {
            goto next;
        }
        if (o == arg4) {
            goto next;
        }
        rr = o->radius;
        px = o->pos[0] * 0.00024414062f;
        py = o->pos[1] * 0.00024414062f;
        pz = o->pos[2] * 0.00024414062f;
        s.x = px;
        s.y = py;
        s.z = pz;
        m.x = mx;
        m.y = my;
        m.z = mz;
        px = px - mx;
        py = py - my;
        pz = pz - mz;
        t1.x = px;
        t1.y = py;
        t1.z = pz;
        l = px * px + py * py + pz * pz;
        rr += r;
        if (!(rr * rr < l)) {
            return o;
        }
    next:
        o = o->next;
    }
    return NULL;
}
