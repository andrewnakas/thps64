/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    s16 h10;
    s16 h12;
} BBox654C8;

typedef struct {
    u8 pad0[8];
    BBox654C8 *bb;
} Mdl654C8;

typedef struct {
    s16 f0;
    u16 f1;
    u16 f2;
    u16 f3;
    s16 f4;
    s16 f5;
} Box654C8;

typedef struct Sk654C8 {
    u16 flags;
    u8 pad2[2];
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x1C - 0x10];
    struct Sk654C8 *next;
    u8 pad20[0x84 - 0x20];
    u8 a84[0x16C - 0x84];
    s32 px;
    s32 py;
    s32 pz;
    u8 pad178[0x2A4 - 0x178];
    s32 v2A4;
} Sk654C8;

Mdl654C8 *func_800350C8(Sk654C8 *);
void func_80063830(Sk654C8 *, Sk654C8 *, void *);
extern Sk654C8 *D_800D6180;
extern s32 D_800D61A4;
extern Sk654C8 *D_800D61A8;

#define INBOX(o, b, minx, maxx, miny, maxy, minz, maxz) \
    ((o)->x + ((s16)(b)->f1 << 12) <= (maxx) && (o)->x + ((s16)(b)->f0 << 12) >= (minx) && \
     (o)->z + ((s16)(b)->f5 << 12) <= (maxz) && (o)->z + ((s16)(b)->f4 << 12) >= (minz) && \
     (o)->y + ((s16)(b)->f3 << 12) <= (maxy) && (o)->y + ((s16)(b)->f2 << 12) >= (miny))

void func_800654C8(void) {
    Sk654C8 *p1;
    Sk654C8 *p2;
    Sk654C8 *o;
    Sk654C8 *q;
    s32 minx1, maxx1, miny1, maxy1, minz1, maxz1;
    s32 minx2, maxx2, miny2, maxy2, minz2, maxz2;
    s32 t;
    Box654C8 box;
    Mdl654C8 *m;
    Box654C8 *b;

    p1 = D_800D61A8;
    p2 = (Sk654C8 *)p1->next;
    minx1 = p1->px;
    maxx1 = p1->x;
    if (maxx1 < minx1) {
        t = minx1;
        minx1 = maxx1;
        maxx1 = t;
    }
    minx1 -= 0x14000;
    maxx1 += 0x14000;
    miny1 = p1->py;
    maxy1 = p1->y;
    if (maxy1 < miny1) {
        t = miny1;
        miny1 = maxy1;
        maxy1 = t;
    }
    miny1 -= 0x14000;
    maxy1 += 0x14000;
    minz1 = p1->pz;
    maxz1 = p1->z;
    if (maxz1 < minz1) {
        t = minz1;
        minz1 = maxz1;
        maxz1 = t;
    }
    minz1 -= 0x14000;
    maxz1 += 0x14000;
    if (D_800D61A4 >= 2) {
        minx2 = p2->px;
        maxx2 = p2->x;
        if (maxx2 < minx2) {
            t = minx2;
            minx2 = maxx2;
            maxx2 = t;
        }
        minx2 -= 0x14000;
        maxx2 += 0x14000;
        miny2 = p2->py;
        maxy2 = p2->y;
        if (maxy2 < miny2) {
            t = miny2;
            miny2 = maxy2;
            maxy2 = t;
        }
        miny2 -= 0x14000;
        maxy2 += 0x14000;
        minz2 = p2->pz;
        maxz2 = p2->z;
        if (maxz2 < minz2) {
            t = minz2;
            minz2 = maxz2;
            maxz2 = t;
        }
        minz2 -= 0x14000;
        maxz2 += 0x14000;
    }
    o = D_800D6180;
    while (1) {
        if (o == NULL) {
            break;
        }
        if (!(o->flags & 0x100)) {
            goto next;
        }
        q = o;
        if (!(o->v2A4 & 0x10)) {
            goto next;
        }
        o->flags |= 0x20;
        if (o->v2A4 & 0x20) {
            goto next;
        }
        m = func_800350C8(o);
        box.f0 = m->bb->hA;
        box.f1 = m->bb->h8;
        box.f2 = m->bb->hE;
        box.f3 = m->bb->hC;
        box.f4 = m->bb->h12;
        box.f5 = m->bb->h10;
        b = &box;
        if (INBOX(o, b, minx1, maxx1, miny1, maxy1, minz1, maxz1)) {
            func_80063830(o, D_800D61A8, D_800D61A8->a84);
        } else if (D_800D61A4 >= 2 && INBOX(q, b, minx2, maxx2, miny2, maxy2, minz2, maxz2)) {
            func_80063830(q, p2, p2->a84);
        }
    next:
        o = o->next;
    }
}
