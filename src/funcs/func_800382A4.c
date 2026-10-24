/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} V3f_382A4;

typedef struct {
    s32 flags;
    u8 pad4[0x10];
    s16 lodModel;
    s16 lodDist;
} Info_382A4;

typedef struct {
    u16 id;
    u16 model;
    u16 *flags;
    Info_382A4 *info;
    u8 padC[0x18];
    V3f_382A4 pos;
    f32 radius;
    u8 pad34[6];
    s16 cur;
    u8 pad3C[3];
    u8 hidden;
} Ent_382A4;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[4];
    Ent_382A4 **ents;
    s32 count;
    u8 pad14[0x18];
    s32 base;
} Obj_382A4;

typedef struct {
    u8 pad0[0x90];
    V3f_382A4 pos;
    u8 pad9C[0x174 - 0x9C];
    f32 scale;
} Cam_382A4;

void func_8003546C(Ent_382A4 *, s32);
s32 func_800A535C(Cam_382A4 *, V3f_382A4 *, f32, s32);
void func_800A5738(Cam_382A4 *, s32);
void func_800A57E0(Cam_382A4 *, s32);
void func_800B4978(void *);
void func_800B4998(void *, s32, s32);
void func_800B4A08(void *, s32, s32, s32, s32, s32, s32);
extern u8 D_800ECFE0[];
extern s32 D_800EEC98;

void func_800382A4(Obj_382A4 *arg0, Cam_382A4 *arg1, s32 arg2) {
    V3f_382A4 v;
    V3f_382A4 d;
    V3f_382A4 p;
    s32 mask;
    s32 i;
    Ent_382A4 *e;
    s32 f;
    u32 big;
    u32 hl;
    f32 k;
    f32 dist;
    f32 r;
    f32 lod;

    func_800A57E0(arg1, 1);
    func_800B4978(D_800ECFE0);
    mask = 0x40;
    if (arg2 == 0) {
        mask = 1;
    }
    i = 0;
    k = 0.0625f;
    while (1) {
        if (i >= arg0->count) {
            break;
        }
        e = arg0->ents[i];
        f = *e->flags;
        if (f & mask) {
            goto next;
        }
        if (e->info->flags & 0x20) {
            goto next;
        }
        if (e->hidden != 0) {
            goto next;
        }
        big = (u16)(f & 0x2000);
        {
            f32 x0 = e->pos.x * k;
            f32 y0 = e->pos.y * k;
            f32 z0 = e->pos.z * k;
            v.x = x0;
            v.y = y0;
            v.z = z0;
        }
        r = e->radius * k;
        if (big == 0) {
            if (func_800A535C(arg1, &v, r, 1) == 0) {
                goto next;
            }
        }
        e->cur = e->model;
        if (e->info->lodModel != -1) {
            p.x = v.x;
            p.y = v.y;
            p.z = v.z;
            {
                f32 x1 = arg1->pos.x - p.x;
                f32 y1 = arg1->pos.y - p.y;
                f32 z1 = arg1->pos.z - p.z;
                d.x = x1;
                d.y = y1;
                d.z = z1;
                dist = x1 * x1 + y1 * y1 + z1 * z1;
            }
            lod = e->info->lodDist;
            if (lod > 0.0f) {
                r = 0.125f;
            } else {
                r = arg1->scale * lod;
                lod = -0.0009765625f;
            }
            r = r * lod;
            if (r * r < dist) {
                e->cur = e->info->lodModel;
            }
        }
        hl = (u16)(*e->flags & 0x800);
        if (hl != 0) {
            D_800EEC98 = 1;
        }
        if (big != 0 && (*e->flags & 0x20)) {
            func_8003546C(e, arg2);
        } else {
            func_800B4A08(D_800ECFE0, arg0->unk4, e->cur, arg0->base + (e->id << 6), -1, 0, 0);
        }
        if (hl != 0) {
            D_800EEC98 = 0;
        }
    next:
        i++;
    }
    func_800B4998(D_800ECFE0, 0, 0);
    func_800A5738(arg1, 1);
    func_800B4998(D_800ECFE0, 0, 1);
    func_800A57E0(arg1, 1);
    func_800B4998(D_800ECFE0, 1, 0);
    func_800A5738(arg1, 1);
}
