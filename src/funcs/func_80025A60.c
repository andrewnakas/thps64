/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    f32 m[3][4];
    Vec3 t;
    f32 w;
} Mtx25A60;

typedef struct {
    u8 pad0[0x88];
    Vec3 vel;
    Vec3 angvel;
    Vec3 pos;
    Vec3 rot;
    u8 padB8[0xB8 - 0xB8];
} Part25A60;

typedef struct {
    u8 pad0[8];
    s16 off;
    s16 pad;
    void (*fn)(void *, s32);
} VT25A60;

typedef struct {
    VT25A60 *vt;
    u8 pad4[4];
    Part25A60 parts[16];
    u8 padB88[0xB8C - 0xB88];
    f32 sx;
    f32 sy;
    f32 timer;
} Obj25A60;

void func_8003519C(void);
void func_8009CBB4(Mtx25A60 *, f32);
void func_8009D3F0(Mtx25A60 *, f32);
void func_8009D624(Mtx25A60 *, f32);
void func_8009D8B4(Mtx25A60 *, Vec3 *);
void func_800A6D38(Part25A60 *, s32, Mtx25A60 *);
extern f32 D_800F5668;

void func_80025A60(Obj25A60 *o) {
    f32 dt;
    f32 x, y, z;
    f32 x2, y2, z2;
    f32 sx, sy;
    f32 one;
    Vec3 v;
    Mtx25A60 m;
    Vec3 s;
    s32 i;
    Part25A60 *p;

    dt = D_800F5668;
    o->timer -= dt;
    if (o->timer <= 0.0f) {
        func_8003519C();
        if (o != NULL) {
            o->vt->fn((u8 *)o + o->vt->off, 3);
        }
    } else {
        i = 0;
        while (1) {
            if (i >= 16) {
                break;
            }
            p = &o->parts[i];
            p->vel.y += dt * 43.75f;
            x = p->vel.x * dt;
            y = p->vel.y * dt;
            z = p->vel.z * dt;
            v.x = x;
            v.y = y;
            v.z = z;
            p->pos.x += v.x;
            p->pos.y += v.y;
            p->pos.z += v.z;
            x2 = dt * p->angvel.x;
            y2 = dt * p->angvel.y;
            z2 = dt * p->angvel.z;
            v.x = x2;
            v.y = y2;
            v.z = z2;
            p->rot.x += v.x;
            p->rot.y += v.y;
            p->rot.z += v.z;
            func_8009CBB4(&m, p->rot.x);
            func_8009D3F0(&m, p->rot.y);
            func_8009D624(&m, p->rot.z);
            one = 1.0f;
            sx = o->sx;
            sy = o->sy;
            s.x = sx;
            s.y = sy;
            s.z = one;
            func_8009D8B4(&m, &s);
            m.t = p->pos;
            func_800A6D38(p, 0, &m);
            i++;
        }
    }
}
