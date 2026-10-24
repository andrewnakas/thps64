/* cflags: -O2 -fno-strength-reduce */
/* NON_MATCHING: aln 0.882. Equivalent C; only register choices differ (loop counter, block-move temps, the %4 sequence). `row` walks the object in 12-byte steps, so row->p[0] is arg0->p[i]. */
/* NEARLY func_800A4EBC (243/296, cflags -O2 -fno-strength-reduce): only register choices differ (loop counter a1 vs a2, block-move temps a2-t0 vs a3-t1, mod-sequence v0/v1, a0 vs v0 for one pointer). */
#include "common.h"

typedef struct {
    f32 x, y, z;
} V3_4EBC;

typedef struct {
    u8 pad0[0x60];
    u8 unk60[0x160 - 0x60];
    f32 unk160;
    f32 unk164;
    f32 unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0x188 - 0x178];
    V3_4EBC n[6];
    V3_4EBC tn[6];
    V3_4EBC p[6];
    V3_4EBC tp[6];
} O4EBC;


#define SET3(v, a, b, c) \
    {                    \
        f32 _c = c;      \
        V3_4EBC *_p = v; \
        _p->x = a;       \
        _p->y = b;       \
        _p->z = _c;      \
    }

#define XFORM(in, mtx, out)                                               \
    {                                                                     \
        V3_4EBC *_v = in;                                                 \
        f32 (*_m)[4] = mtx;                                               \
        f32 _x = _v->x * _m[0][0] + _v->y * _m[1][0] + _v->z * _m[2][0] + _m[3][0]; \
        f32 _y = _v->x * _m[0][1] + _v->y * _m[1][1] + _v->z * _m[2][1] + _m[3][1]; \
        f32 _z = _v->x * _m[0][2] + _v->y * _m[1][2] + _v->z * _m[2][2] + _m[3][2]; \
        t.x = _x;                                                         \
        t.y = _y;                                                         \
        t.z = _z;                                                         \
        *(out) = t;                                                       \
    }

#define CROSS(a, b, out)                         \
    {                                            \
        V3_4EBC *_a = a;                         \
        V3_4EBC *_b = b;                         \
        f32 _x = _a->y * _b->z - _a->z * _b->y;  \
        f32 _y = _a->z * _b->x - _a->x * _b->z;  \
        f32 _z = _a->x * _b->y - _a->y * _b->x;  \
        t.x = _x;                                \
        t.y = _y;                                \
        t.z = _z;                                \
        *(out) = t;                              \
    }

#define NORM(v)                                                         \
    {                                                                   \
        V3_4EBC *_v = v;                                                \
        f32 _l = __builtin_sqrtf(_v->x * _v->x + _v->y * _v->y + _v->z * _v->z); \
        if (_l != 0.0f) {                                               \
            f32 _s = 1.0f / _l;                                         \
            _v->x *= _s;                                                \
            _v->y *= _s;                                                \
            _v->z *= _s;                                                \
        }                                                               \
    }
void func_8009C8EC(f32 (*)[4], void *);

void func_800A4EBC(O4EBC *arg0) {
    f32 m[4][4];
    V3_4EBC t;
    f32 k;
    f32 l;
    f32 r;
    f32 b;
    f32 tp;
    s32 i;
    s32 j;
    O4EBC *ri;
    O4EBC *row;

    k = arg0->unk174 / arg0->unk170;
    l = arg0->unk164 * k;
    r = arg0->unk168 * k;
    b = arg0->unk16C * k;
    tp = arg0->unk160 * k;
    SET3(&arg0->p[0], l, r, -arg0->unk174);
    SET3(&arg0->p[1], l, b, -arg0->unk174);
    SET3(&arg0->p[2], tp, b, -arg0->unk174);
    SET3(&arg0->p[3], tp, r, -arg0->unk174);
    SET3(&arg0->p[4], 0.0f, 0.0f, -arg0->unk174);
    {
        V3_4EBC *_p = &arg0->p[5];
        _p->x = 0.0f;
        _p->y = 0.0f;
        _p->z = 0.0f;
    }
    i = 0;
    while (1) {
        if (i >= 4) {
            break;
        }
        ri = (O4EBC *)((V3_4EBC *)arg0 + i);
        j = (i + 1) % 4;
        CROSS(&((O4EBC *)(j + (V3_4EBC *)arg0))->p[0], &ri->p[0], &ri->n[0]);
        NORM(&ri->n[0]);
        i++;
    }
    arg0->n[4] = arg0->p[4];
    NORM(&arg0->n[4]);
    arg0->n[5].x = -arg0->n[4].x;
    arg0->n[5].y = -arg0->n[4].y;
    arg0->n[5].z = -arg0->n[4].z;
    func_8009C8EC(m, arg0->unk60);
    i = 0;
    row = arg0;
    while (1) {
        if (i >= 6) {
            break;
        }
        XFORM(&row->p[0], m, &row->tp[0]);
        row = (O4EBC *)((V3_4EBC *)row + 1);
        i++;
    }
    i = 0;
    row = arg0;
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    while (1) {
        if (i >= 6) {
            break;
        }
        XFORM(&row->n[0], m, &row->tn[0]);
        row = (O4EBC *)((V3_4EBC *)row + 1);
        i++;
    }
}
