/* cflags: -O2 */
/* NON_MATCHING: 19/442 positional instructions agree (target 439), difflib ratio 0.673; reviewed equivalent block by block. Only register allocation differs (ours uses f26/f28 for the min/max pairs) plus where loads are placed and reused (ours loads p0/box fields early). Control flow, constants, comparisons and stores are the same. */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec_B7A6C;

typedef struct {
    Vec_B7A6C min;
    Vec_B7A6C max;
} Box_B7A6C;

s32 func_800B7A6C(Box_B7A6C *box, Vec_B7A6C *p0, Vec_B7A6C *p1, f32 *t0, f32 *t1, s32 *f0, s32 *f1) {
    f32 *tp[2];
    s32 *fp[2];
    s32 n;
    s32 c;
    f32 maxx, minx, maxy, miny, maxz, minz;
    f32 dx, dy, dz;
    f32 t;
    f32 a, b;

    tp[0] = t0;
    tp[1] = t1;
    fp[0] = f0;
    fp[1] = f1;
    n = 0;
    {
        f32 ax = p0->x;
        f32 bx = p1->x;

        c = ax > bx;
        if (c) {
            maxx = ax;
            minx = bx;
        } else {
            maxx = bx;
            minx = ax;
        }
    }
    {
        f32 ay = p0->y;
        f32 by = p1->y;

        c = ay > by;
        if (c) {
            maxy = ay;
            miny = by;
        } else {
            maxy = by;
            miny = ay;
        }
    }
    {
        f32 az = p0->z;
        f32 bz = p1->z;

        c = az > bz;
        if (c) {
            maxz = az;
            minz = bz;
        } else {
            maxz = bz;
            minz = az;
        }
    }
    if (maxx < box->min.x || box->max.x < minx || maxy < box->min.y || box->max.y < miny || maxz < box->min.z ||
        box->max.z < minz) {
        return 0;
    }
    c = maxx <= box->max.x && box->min.x <= minx && maxy <= box->max.y && box->min.y <= miny && maxz <= box->max.z &&
        box->min.z <= minz;
    if (c) {
        return 3;
    }
    dx = p1->x - p0->x;
    dy = p1->y - p0->y;
    dz = p1->z - p0->z;
    if (minz <= box->min.z) {
        t = 0.0f;
        if (dz != 0.0f) {
            t = (box->min.z - p0->z) / dz;
        }
        a = p0->x + t * dx;
        b = p0->y + t * dy;
        c = box->min.x <= a && a <= box->max.x && box->min.y <= b && b <= box->max.y;
        if (c) {
            *tp[n] = t;
            *fp[n++] = -3;
            if (n == 2) return 2;
        }
    }
    if (box->max.z <= maxz) {
        t = 0.0f;
        if (dz != 0.0f) {
            t = (box->max.z - p0->z) / dz;
        }
        a = p0->x + t * dx;
        b = p0->y + t * dy;
        c = box->min.x <= a && a <= box->max.x && box->min.y <= b && b <= box->max.y;
        if (c) {
            *tp[n] = t;
            *fp[n++] = 3;
            if (n == 2) return 2;
        }
    }
    if (miny <= box->min.y) {
        t = 0.0f;
        if (dy != 0.0f) {
            t = (box->min.y - p0->y) / dy;
        }
        a = p0->x + t * dx;
        b = p0->z + t * dz;
        c = box->min.x <= a && a <= box->max.x && box->min.z <= b && b <= box->max.z;
        if (c) {
            *tp[n] = t;
            *fp[n++] = -2;
            if (n == 2) return 2;
        }
    }
    if (box->max.y <= maxy) {
        t = 0.0f;
        if (dy != 0.0f) {
            t = (box->max.y - p0->y) / dy;
        }
        a = p0->x + t * dx;
        b = p0->z + t * dz;
        c = box->min.x <= a && a <= box->max.x && box->min.z <= b && b <= box->max.z;
        if (c) {
            *tp[n] = t;
            *fp[n++] = 2;
            if (n == 2) return 2;
        }
    }
    if (minx <= box->min.x) {
        t = 0.0f;
        if (dx != 0.0f) {
            t = (box->min.x - p0->x) / dx;
        }
        a = p0->z + t * dz;
        b = p0->y + t * dy;
        c = box->min.z <= a && a <= box->max.z && box->min.y <= b && b <= box->max.y;
        if (c) {
            *tp[n] = t;
            *fp[n++] = -1;
            if (n == 2) return 2;
        }
    }
    if (box->max.x <= maxx) {
        t = 0.0f;
        if (dx != 0.0f) {
            t = (box->max.x - p0->x) / dx;
        }
        a = p0->z + t * dz;
        b = p0->y + t * dy;
        c = box->min.z <= a && a <= box->max.z && box->min.y <= b && b <= box->max.y;
        if (c) {
            *tp[n] = t;
            *fp[n++] = 1;
            if (n == 2) return 2;
        }
    }
    return n;
}
