/* cflags: -ffast-math -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec80082CB0;

typedef struct {
    Vec80082CB0 min;
    Vec80082CB0 max;
    Vec80082CB0 size;
    f32 len;
    Vec80082CB0 lo;
    Vec80082CB0 hi;
} View80082CB0;

typedef struct {
    s32 imin[3];
    s32 imax[3];
    u8 pad18[0xA4 - 0x18];
    Vec80082CB0 min;
    Vec80082CB0 max;
    Vec80082CB0 size;
    f32 len;
    Vec80082CB0 lo;
    Vec80082CB0 hi;
    Vec80082CB0 center;
    f32 radius;
    f32 radiusXZ;
} Box80082CB0;

extern void func_80039168(s32);
extern u8 D_800FC0C0;
extern s32 D_800E8A10;

#define VSET(t, a, b, c)       \
    {                          \
        f32 _x = (a);          \
        f32 _y = (b);          \
        f32 _z = (c);          \
        (t).x = _x;            \
        (t).y = _y;            \
        (t).z = _z;            \
    }

#define MINMAX(lo, hi, a, b)          \
    {                                 \
        s32 _t = (a) < (b);           \
        if (_t) {                     \
            (lo) = (a);               \
            (hi) = (b);               \
        } else {                      \
            (lo) = (b);               \
            (hi) = (a);               \
        }                             \
    }

void func_80082CB0(Box80082CB0 *arg0, s32 arg1) {
    View80082CB0 *v;
    Vec80082CB0 tmp;
    Vec80082CB0 b;
    Vec80082CB0 sum;
    Vec80082CB0 b2;

    v = (View80082CB0 *)&arg0->min;
    if (arg1 == 0) {
        VSET(tmp, arg0->imin[0] * 0.000244140625f, arg0->imin[1] * 0.000244140625f, arg0->imin[2] * 0.000244140625f);
        arg0->min = tmp;
        VSET(tmp, arg0->imax[0] * 0.000244140625f, arg0->imax[1] * 0.000244140625f, arg0->imax[2] * 0.000244140625f);
        arg0->max = tmp;
    }
    b.x = arg0->max.x;
    b.y = arg0->max.y;
    b.z = arg0->max.z;
    VSET(tmp, arg0->min.x - b.x, arg0->min.y - b.y, arg0->min.z - b.z);
    arg0->size = tmp;
    arg0->len = __builtin_sqrtf(arg0->size.x * arg0->size.x + arg0->size.y * arg0->size.y + arg0->size.z * arg0->size.z);
    b2.x = arg0->max.x;
    b2.y = arg0->max.y;
    b2.z = arg0->max.z;
    VSET(sum, arg0->min.x + b2.x, arg0->min.y + b2.y, arg0->min.z + b2.z);
    VSET(tmp, sum.x * 0.5f, sum.y * 0.5f, sum.z * 0.5f);
    arg0->center = tmp;
    arg0->radius = arg0->len * 0.5f;
    arg0->radiusXZ = __builtin_sqrtf(arg0->size.x * arg0->size.x + arg0->size.z * arg0->size.z) * 0.5f;
    MINMAX(arg0->lo.x, arg0->hi.x, arg0->min.x, arg0->max.x);
    MINMAX(v->lo.y, v->hi.y, v->min.y, v->max.y);
    MINMAX(v->lo.z, v->hi.z, v->min.z, v->max.z);
    D_800FC0C0 = 0;
    func_80039168(D_800E8A10);
}
