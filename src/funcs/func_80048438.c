/* cflags: -frerun-cse-after-loop */
#include "common.h"

typedef struct {
    s32 x, y, z;
    f32 fx, fy, fz;
    f32 gx, gy, gz;
    void *cur;
} Vec3i;

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct Obj48438 {
    u16 flags;
    u8 pad2[2];
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x1B - 0x10];
    u8 model;
    struct Obj48438 *next;
} Obj48438;

typedef struct Ped48438 {
    u8 pad0[4];
    struct Ped48438 *next;
    u8 pad8[0x18 - 8];
    s32 x;
    s32 y;
    s32 z;
    u8 pad24[0x43 - 0x24];
    u8 type;
} Ped48438;

typedef struct {
    u8 pad0[0x12];
    u8 b12;
    u8 pad13[0x48 - 0x13];
} Model48438;

void func_80034AA4(Vec3f *, Vec3f *, s32, s32, s32, s32);
extern Obj48438 *D_800D6180;
extern Obj48438 *D_800D6184;
extern void *D_800D61A0;
extern Obj48438 *D_800DAD8C;
extern Model48438 D_800DAF98[];
extern Obj48438 *D_800DC5A0;
extern Ped48438 *D_800DE5AC;
extern void *D_800DE7A8;
extern void *D_800DE7AC;
extern s32 D_800DE9A8;

#define INSIDE(o) (!((o)->x < minx) && !(maxx < (o)->x) && !((o)->z < minz) && !(maxz < (o)->z) && !((o)->y < miny) && !(maxy < (o)->y))
#define OUTSIDE(o) (((o)->x < minx || maxx < (o)->x) && ((o)->z < minz || maxz < (o)->z) && ((o)->y < miny || maxy < (o)->y))

void func_80048438(Vec3i *min, Vec3i *max, s32 clear, s32 inside) {
    s32 minx, miny, minz;
    s32 maxx, maxy, maxz;
    s32 set;
    s32 mask;
    Vec3f fa;
    Vec3f fb;
    Obj48438 *o0, *o1, *o2;
    Obj48438 *p;
    Ped48438 *q;
    s32 x, y, z;
    f32 fx, fy, fz;
    f32 gx, gy, gz;
    void *cur;

    minx = min->x;
    miny = min->y;
    minz = min->z;
    maxx = max->x;
    maxy = max->y;
    maxz = max->z;
    cur = D_800D61A0;
    if (cur == NULL || D_800DE9A8 == 1) {
        set = 0x41;
    } else if (cur == D_800DE7A8) {
        set = 1;
    } else if (cur == D_800DE7AC) {
        set = 0x40;
    }
    if (clear) {
        mask = ~set;
        set = 0;
    } else {
        mask = -1;
    }
    fx = min->x * (1.0f / 4096.0f);
    fy = min->y * (1.0f / 4096.0f);
    fz = min->z * (1.0f / 4096.0f);
    fa.x = fx;
    fa.y = fy;
    fa.z = fz;
    gx = max->x * (1.0f / 4096.0f);
    gy = max->y * (1.0f / 4096.0f);
    gz = max->z * (1.0f / 4096.0f);
    fb.x = gx;
    fb.y = gy;
    fb.z = gz;
    func_80034AA4(&fa, &fb, clear, inside, set, mask);
    p = D_800DAD8C;
    while (1) {
        if (p == NULL) {
            break;
        }
        if (D_800DAF98[p->model].b12 != 0) {
            x = p->x;
            y = p->y;
            z = p->z;
            if (inside) {
                if (!(x < minx) && !(maxx < x) && !(z < minz) && !(maxz < z) && !(y < miny) && !(maxy < y)) {
                    p->flags = (p->flags & mask) | set;
                }
            } else {
                if ((x < minx || maxx < x) && (z < minz || maxz < z) && (y < miny || maxy < y)) {
                    p->flags = (p->flags & mask) | set;
                }
            }
        }
        p = p->next;
    }
    for (o0 = D_800DC5A0; o0 != NULL; o0 = o0->next) {
        if (inside) {
            if (INSIDE(o0)) {
                o0->flags = (o0->flags & mask) | set;
            }
        } else {
            if (OUTSIDE(o0)) {
                o0->flags = (o0->flags & mask) | set;
            }
        }
    }
    for (o1 = D_800D6184; o1 != NULL; o1 = o1->next) {
        if (inside) {
            if (INSIDE(o1)) {
                o1->flags = (o1->flags & mask) | set;
            }
        } else {
            if (OUTSIDE(o1)) {
                o1->flags = (o1->flags & mask) | set;
            }
        }
    }
    for (o2 = D_800D6180; o2 != NULL; o2 = o2->next) {
        if (inside) {
            if (INSIDE(o2)) {
                o2->flags = (o2->flags & mask) | set;
            }
        } else {
            if (OUTSIDE(o2)) {
                o2->flags = (o2->flags & mask) | set;
            }
        }
    }
    for (q = D_800DE5AC; q != NULL; q = q->next) {
        if (q->type == 2) {
            if (inside) {
                if (INSIDE(q)) {
                }
            } else {
                if (OUTSIDE(q)) {
                }
            }
        }
    }
}
