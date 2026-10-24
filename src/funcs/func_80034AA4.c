#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[4];
    u16 *unk4;
    u8 pad8[0x1C];
    Vec3 pos;
} Obj;

typedef struct {
    u8 pad0[0xC];
    Obj **unkC;
    s32 unk10;
} Tbl;

extern Tbl D_800FA350;

void func_80034AA4(Vec3 *lo, Vec3 *hi, s32 arg2, s32 inside, s32 orv, s32 andv) {
    s32 i;
    Tbl *t;

    i = 0;
    t = &D_800FA350;
    while (1) {
        Obj *o;
        u16 *f;
        Vec3 p;
        s32 r;
        f32 x;

        if (!(i < t->unk10)) {
            break;
        }
        o = t->unkC[i];
        f = o->unk4;
        p.x = x = o->pos.x;
        p.y = o->pos.y;
        p.z = o->pos.z;

        if (inside) {
            r = 0;
            if (lo->x <= x && x <= hi->x) {
                r = 1;
            }
            if (!r) {
                goto next;
            }
            r = 0;
            if (p.z >= lo->z && p.z <= hi->z) {
                r = 1;
            }
            if (!r) {
                goto next;
            }
            r = 0;
            if (p.y >= lo->y && p.y <= hi->y) {
                r = 1;
            }
        } else {
            r = 0;
            if (x < lo->x || hi->x < x) {
                r = 1;
            }
            if (!r) {
                goto next;
            }
            r = 0;
            if (p.z < lo->z || hi->z < p.z) {
                r = 1;
            }
            if (!r) {
                goto next;
            }
            r = 0;
            if (p.y < lo->y || hi->y < p.y) {
                r = 1;
            }
        }
        i++;
        if (r) {
            *f = (*f & andv) | orv;
        }
        continue;
next:
        i++;
    }
}
