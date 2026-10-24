/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_8003460C;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_8003460C;

typedef struct {
    u16 x0;
    u8 pad2[2];
    Vec3i_8003460C pos;
    s16 rot[3];
    u8 pad16[0x24 - 0x16];
    s16 scale[3];
    u8 pad2A[0x52 - 0x2A];
    u16 x52;
} Src8003460C;

typedef struct {
    u8 pad0[0xC];
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1C;
    f32 x20;
} Box8003460C;

typedef struct {
    u8 pad0[4];
    Box8003460C *box;
    Src8003460C *src;
    u8 padC[4];
    u8 mtx[0x98 - 0x10];
    Vec3f_8003460C x98;
    u8 padA4[4];
    Vec3f_8003460C xA8;
    u8 padB4[0xC4 - 0xB4];
    Vec3i_8003460C last;
    s8 xD0;
    s8 xD1;
    u8 xD2;
    u8 xD3;
    u8 xD4;
    u8 padD5[3];
} Ent8003460C;

void func_80023058(Vec3f_8003460C *, void *);
void func_8009CAD0(void *);
void func_8009CC6C(void *, f32);
void func_8009D8B4(void *, Vec3f_8003460C *);
void func_800A6D38(void *, s32, void *);
extern s32 D_800D36EC;
extern Ent8003460C D_800F78C0[];

void func_8003460C(void) {
    u8 mtx[0x30];
    Vec3f_8003460C save;
    Vec3f_8003460C v;
    Vec3f_8003460C sv;
    void *pm;
    Ent8003460C *e;
    Src8003460C *o;
    s32 i;
    s32 moved;
    s32 rot;
    s32 scl;
    s32 dx;
    s32 dy;
    s32 dz;
    f32 f;
    f32 g;
    f32 fx;
    f32 fy;
    f32 fz;

    i = 0;
    while (1) {
        if (i >= D_800D36EC) {
            break;
        }
        e = &D_800F78C0[i];
        if (e->xD2 != 0) {
            goto next;
        }
        o = e->src;
        if (o->x52 & 0x40) {
            e->xD2 = 1;
            goto next;
        }
        moved = 0;
        dx = o->pos.x - e->last.x;
        dy = o->pos.y - e->last.y;
        dz = o->pos.z - e->last.z;
        if (dx != 0 || dy != 0 || dz != 0) {
            moved = 1;
            e->last = e->src->pos;
            dx >>= 12;
            dy >>= 12;
            dz >>= 12;
            if (e->xD1 == 0) {
                if (dx != 0) {
                    f = dx;
                    g = e->box->xC;
                    e->box->xC = g + f;
                    g = e->box->x18;
                    e->box->x18 = g + f;
                }
                if (dy != 0) {
                    f = dy;
                    g = e->box->x10;
                    e->box->x10 = g + f;
                    g = e->box->x1C;
                    e->box->x1C = g + f;
                }
                if (dz != 0) {
                    f = dz;
                    g = e->box->x14;
                    e->box->x14 = g + f;
                    g = e->box->x20;
                    e->box->x20 = g + f;
                }
            }
        }
        rot = 0;
        if (*(s32 *)e->src->rot != 0 || e->src->rot[2] != 0) {
            f32 rx = e->src->rot[0] * 0.001533980831f;
            f32 ry = e->src->rot[1] * 0.001533980831f;
            f32 rz = e->src->rot[2] * 0.001533980831f;

            v.x = rx;
            v.y = ry;
            v.z = rz;
            rot = 1;
            if (e->xD3 != 0) {
                v.z += 3.141592741f;
            }
            func_80023058(&v, mtx);
        } else if (e->xD3 != 0) {
            func_8009CC6C(mtx, 3.141592741f);
        } else {
            func_8009CAD0(mtx);
        }
        e->xD4 = rot;
        scl = 0;
        if (e->src->x0 & 0x200) {
            f32 sx = e->src->scale[0] * 0.000244140625f;
            f32 sy = e->src->scale[1] * 0.000244140625f;
            f32 sz = e->src->scale[2] * 0.000244140625f;

            sv.x = sx;
            sv.y = sy;
            sv.z = sz;
            func_8009D8B4(mtx, &sv);
            scl = 1;
        }
        if (rot || moved || scl) {
            f32 px = e->src->pos.x * 0.000244140625f;
            f32 py = e->src->pos.y * 0.000244140625f;
            f32 pz = e->src->pos.z * 0.000244140625f;

            pm = mtx;
            v.x = px;
            v.y = py;
            v.z = pz;
            save = v;
            v.x = v.y = v.z = 0.0625f;
            func_8009D8B4(pm, &v);
            save.x *= 0.0625f;
            save.y *= 0.0625f;
            save.z *= 0.0625f;
            func_800A6D38(e->mtx, 0, pm);
            e->x98 = save;
            if (e->xD0 >= 0) {
                e->xA8 = save;
            }
        }
    next:
        i++;
    }
}
