/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    u8 pad0[0x28];
    f32 minX, minY, minZ;
    f32 maxX, maxY, maxZ;
    f32 x, y, z;
    f32 r4C;
    f32 r50;
} Box;

typedef struct {
    u8 pad0[0xA4];
    Box box;
} Coll;

typedef struct {
    u8 pad0[4];
    u16 *flags;
    u8 pad8[4];
    f32 minX, minY, minZ;
    f32 maxX, maxY, maxZ;
    u8 pad24[4];
    f32 y;
    u8 pad2C[4];
    f32 radius;
    u8 pad34[4];
    u16 frame;
    u8 pad3A[5];
    u8 off;
} Obj;

typedef struct {
    u8 pad0[0x54];
    u16 frame;
} Game;

s32 func_800837C8(Coll *, Obj *, s32);
extern Game *D_800E8A10;
extern s32 D_800D2838;
extern s32 D_800DE7A8;
extern s32 D_800DE7AC;

s32 func_80084274(Coll *c, Obj *o, f32 *p, s32 arg3) {
    Box *b;
    s32 mask;
    s32 hit;
    u16 f;
    f32 px, pz;
    f32 dx, dz, dy, d, r, rr;

    b = &c->box;
    f = D_800E8A10->frame;
    if (o->frame != f) {
        o->frame = f;
        if (D_800D2838 == D_800DE7A8) {
            mask = 1;
        } else if (D_800D2838 == D_800DE7AC) {
            mask = 0x40;
        }
        if (*o->flags & (mask | 0x20)) {
            return 0;
        }
        if (o->off != 0) {
            return 0;
        }
        if (arg3 == 0) {
            hit = 0;
            if (b->maxX > o->minX && b->minX < o->maxX && b->maxZ > o->minZ && b->minZ < o->maxZ && b->maxY > o->minY && b->minY < o->maxY) {
                hit = 1;
            }
            if (hit == 0) {
                return 0;
            }
        }
        px = p[0];
        dx = b->x - px;
        pz = p[2];
        dz = b->z - pz;
        r = o->radius;
        rr = r + b->r50;
        rr = rr * rr;
        d = dx * dx + dz * dz;
        if (rr < d) {
            return 0;
        }
        dy = b->y - o->y;
        d += dy * dy;
        rr = r + b->r4C;
        rr = rr * rr;
        if (rr < d) {
            return 0;
        }
        return func_800837C8(c, o, arg3);
    }
    return 0;
}
