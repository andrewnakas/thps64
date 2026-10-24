#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    u8 pad0[8];
    s16 off8;
    s16 padA;
    void (*fn8)(void *, s32);
    s16 off10;
    s16 pad12;
    void (*fn10)(void *);
} VT480B4;

typedef struct Obj480B4 {
    u8 pad0[4];
    Vec3i pos;
    u8 pad10[0x1C - 0x10];
    struct Obj480B4 *next;
    u8 pad20[0x48 - 0x20];
    VT480B4 *vt;
} Obj480B4;

s32 func_8004AEE0(Obj480B4 *);
extern Obj480B4 *D_800D6180;
extern Obj480B4 *D_800D6184;
extern Obj480B4 *D_800DC5A0;
extern Obj480B4 *D_800DDC60;

s32 func_800480B4(Vec3i *min, Vec3i *max) {
    Obj480B4 *o;
    Obj480B4 *next0, *next1, *next2, *next3;
    Vec3i p;
    s32 n0, n1, n2, n3;
    s32 total;

    total = 0;
    o = D_800DDC60;
    n0 = 0;
    while (1) {
        if (o == NULL) {
            break;
        }
        next0 = o->next;
        if (func_8004AEE0(o) == 0) {
            p = o->pos;
            if (p.x >= min->x && max->x >= p.x && p.z >= min->z && max->z >= p.z && p.y >= min->y && max->y >= p.y) {
                o->vt->fn10((u8 *)o + o->vt->off10);
                n0++;
            }
        }
        o = next0;
    }
    total += n0;
    o = D_800D6180;
    n1 = 0;
    while (1) {
        if (o == NULL) {
            break;
        }
        next1 = o->next;
        if (func_8004AEE0(o) == 0) {
            p = o->pos;
            if (p.x >= min->x && max->x >= p.x && p.z >= min->z && max->z >= p.z && p.y >= min->y && max->y >= p.y) {
                o->vt->fn10((u8 *)o + o->vt->off10);
                n1++;
            }
        }
        o = next1;
    }
    total += n1;
    o = D_800DC5A0;
    n2 = 0;
    while (1) {
        if (o == NULL) {
            break;
        }
        next2 = o->next;
        if (func_8004AEE0(o) == 0) {
            p = o->pos;
            if (p.x >= min->x && max->x >= p.x && p.z >= min->z && max->z >= p.z && p.y >= min->y && max->y >= p.y) {
                o->vt->fn10((u8 *)o + o->vt->off10);
                n2++;
            }
        }
        o = next2;
    }
    total += n2;
    o = D_800D6184;
    n3 = 0;
    while (1) {
        if (o == NULL) {
            break;
        }
        next3 = o->next;
        if (func_8004AEE0(o) == 0) {
            p = o->pos;
            if (p.x >= min->x && max->x >= p.x && p.z >= min->z && max->z >= p.z && p.y >= min->y && max->y >= p.y) {
                o->vt->fn8((u8 *)o + o->vt->off8, 3);
                n3++;
            }
        }
        o = next3;
    }
    return total + n3;
}
