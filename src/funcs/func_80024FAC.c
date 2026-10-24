/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32);
} VEnt;

typedef struct {
    u8 pad0[0x40];
    u8 m40[0x40];
    f32 f80;
    u8 pad84[4];
    u8 b88;
    u8 pad89[3];
} Elem;

typedef struct {
    VEnt *vt;
    Elem e[8];
    u8 pad[0x468 - 4 - 8 * 0x8C];
    f32 f468;
    f32 f46C;
    f32 f470;
    u8 b474;
    u8 b475;
} Obj;

extern f32 D_800F5668;
void func_80024D20(Obj *);
void func_8003519C(void);
void func_8009C8EC(void *, void *);
void func_8009D8B4(void *, f32 *);

void func_80024FAC(Obj *arg0) {
    f32 v[3];
    f32 dt;
    f32 t;
    f32 a;
    f32 b;
    f32 s;
    s32 i;
    s32 off;
    f32 zero;
    f64 d;
    f32 x;
    u32 u;
    u32 m;
    f64 tt;
    f64 c;

    dt = D_800F5668;
    t = arg0->f468 - dt;
    arg0->f468 = t;
    zero = 0.0f;
    if (t <= zero) {
        func_8003519C();
        if (arg0 != NULL) {
            arg0->vt[1].fn((u8 *)arg0 + arg0->vt[1].delta, 3);
        }
    } else {
        if ((arg0->f470 -= dt) <= zero) {
            func_80024D20(arg0);
        }
        x = arg0->f468;
        if (x <= 2.0f) {
            u8 *p = &arg0->b474;
            d = x * 80.0;
            if (!((c = 2147483648.0) <= d)) {
                u = (s32)d;
            } else {
                tt = d - c;
                m = 0x80000000;
                u = (s32)tt;
                u |= m;
            }
            *p = u;
        }
        i = 0;
        a = 4.0f;
        b = 3.0f;
        off = 4;
        for (;;) {
            Elem *e = (Elem *)((u8 *)arg0 + off);
            if (i >= arg0->b475) {
                break;
            }
            s = arg0->f46C;
            if (e->b88 != 0) {
                s *= a;
            }
            { f32 o = e->f80; e->f80 = o + (s - o) * b * dt; }
            func_8009C8EC(e->m40, e);
            v[2] = v[1] = v[0] = e->f80;
            func_8009D8B4(e->m40, v);
            off += 0x8C;
            i++;
        }
    }
}
