/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    f32 m[3][4];
    Vec3 t;
    f32 w;
} Mtx2572C;

typedef struct {
    u8 pad0[8];
    s32 v8;
} VT2572C;

typedef struct {
    VT2572C *vt;
    u8 pad4[2];
    s8 b6;
    u8 pad7[0x88 - 7];
    Vec3 vel;
    Vec3 angvel;
    Vec3 pos;
    Vec3 rot;
} Part2572C;

typedef struct {
    void *vt;
    u8 pad4[4];
    Part2572C parts[16];
    u8 padB88[0xB8C - 0xB88];
    f32 sx;
    f32 sy;
    f32 timer;
} Obj2572C;

typedef struct {
    s32 id;
    Vec3 v;
} Ent2572C;

void func_80025634(Obj2572C *, s32);
void func_80035228(Obj2572C *);
f32 func_8009F2CC(void);
void func_800A69C0(Part2572C *, s32);
extern Ent2572C D_800F6460[];

void func_8002572C(Obj2572C *o, Mtx2572C *m, Vec3 *vel, f32 sx, f32 sy) {
    Vec3 a;
    Vec3 tmp;
    Vec3 d;
    Vec3 t;
    f32 x, y, z;
    f32 rx, ry, rz;
    f32 px, py, pz;
    f32 vx, vy, vz;
    s32 i;
    f32 pi;
    f32 scale;
    Part2572C *p;
    Vec3 *e;

    o->sx = sx * 0.000625f;
    o->sy = sy * 0.000625f;
    scale = 0.0625f;
    m->t.x *= scale;
    m->t.y *= scale;
    m->t.z *= scale;
    i = 0;
    while (1) {
        if (i >= 16) {
            break;
        }
        p = &o->parts[i];
        e = &D_800F6460[i].v;
        x = e->x * o->sx;
        y = e->z * o->sy;
        z = e->y;
        a.x = x;
        a.y = y;
        a.z = z;
        px = x * m->m[0][0] + y * m->m[1][0] + z * m->m[2][0] + m->t.x;
        py = x * m->m[0][1] + y * m->m[1][1] + z * m->m[2][1] + m->t.y;
        pz = x * m->m[0][2] + y * m->m[1][2] + z * m->m[2][2] + m->t.z;
        tmp.x = px;
        tmp.y = py;
        tmp.z = pz;
        p->pos = tmp;
        func_800A69C0(p, D_800F6460[i].id);
        p->b6 = 0;
        vx = vel->x * 0.0625f;
        vy = vel->y * 0.0625f;
        vz = vel->z * 0.0625f;
        tmp.x = vx;
        tmp.y = vy;
        tmp.z = vz;
        p->vel = tmp;
        t.x = m->t.x;
        t.y = m->t.y;
        t.z = m->t.z;
        {
            f32 dx, dy, dz;
            dx = p->pos.x - t.x;
            dy = p->pos.y - t.y;
            dz = p->pos.z - t.z;
            d.x = dx;
            d.y = dy;
            d.z = dz;
        }
        {
            f32 sx2, sy2, sz2;
            sx2 = d.x + d.x;
            sy2 = d.y + d.y;
            sz2 = d.z + d.z;
            tmp.x = sx2;
            tmp.y = sy2;
            tmp.z = sz2;
        }
        p->vel.x += tmp.x;
        p->vel.y += tmp.y;
        p->vel.z += tmp.z;
        rx = func_8009F2CC() * 5.0f;
        ry = func_8009F2CC() * 5.0f;
        rz = func_8009F2CC() * 5.0f;
        pi = 3.1415927f;
        tmp.x = rx;
        tmp.y = ry;
        tmp.z = rz;
        p->angvel = tmp;
        tmp.x = 0.0f;
        tmp.y = pi;
        tmp.z = 0.0f;
        p->rot = tmp;
        func_80025634(o, p->vt->v8);
        i++;
    }
    o->timer = 3.0f;
    func_80035228(o);
}
