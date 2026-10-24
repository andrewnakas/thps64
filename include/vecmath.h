/* Vector / matrix types and the game's fixed-point (x.12, 4096 = 1.0) vector library at 0x800223C0-0x80023430.
 * Include after common.h. Nothing here emits code unless used.
 *
 * Types (each shape recurs across the matched files: Vec3f x12 files, Vec3i x13, Vec3s/V3S x8, s16 m[3][3] x6):
 *   Vec3f  f32 x,y,z              (func_80022964, func_800226A0, func_8003460C, func_80082CB0, ...)
 *   Vec3i  s32 x,y,z  (x.12)      (func_8009B9B0, func_80058A94, skater +0x8D0, object +0x4 / +0x16C)
 *   Vec3s  s16 x,y,z  (angles, 4096 = full turn) (func_80022598 arg0, func_8004A544)
 *   Mtx3s  s16 m[3][3] (x.12 rotation) (skater +0x884: func_8004BD2C, func_8004D2D4, func_80022598)
 *
 * Library declarations: return types as the definitions have them; the integer/pointer-argument ones are left
 * unprototyped (`s32 func_80022E54();`) so they stay compatible with the defining file, with callers' own
 * prototypes and with any vector struct pointer; that changes no code for int/pointer arguments. Argument types are
 * in the comments. Behaviour notes are from the matched C of each function, not names.
 *
 * Inline helpers: copied from matched files (only the type/name changed). Keep them static __inline__/inline as
 * given; GCC 2.8 inlines them at -O1 and the matched callers rely on that.
 */
#ifndef VECMATH_H
#define VECMATH_H

#define FIX12_ONE 4096

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    s16 m[3][3];
} Mtx3s;

typedef struct {
    s32 x, y, z, w;   /* x.12 quaternion: func_800673B0 (Q4), func_80077350 / func_80078498 */
} Quat4i;

/* ---- library (0x80001CA0 is libultra-range float sin; the rest is the game's x.12 vector code) ---- */
f32 func_80001CA0(f32);                      /* sin(radians): isin() below, func_80022C04 */
void func_80022964();                        /* (s32 *v): normalize an s32[3] x.12 vector in place (via floats + sqrtf) */
s32 func_80022E14();                         /* (s32 a, s32 b): x.12 multiply: a * b / 4096 (through floats) */
s32 func_80022E54();                         /* (s32 *a, s32 *b): x.12 dot product of two s32[3] */
s32 func_80022F6C();                         /* (a, b, c, d): x.12 (a*b + c*d) / 4096 */
s32 func_8002311C();                         /* (s32 a): angle (4096 per turn) of func_8009F9D0(a / 4096), wrapped to >= 0 */
s32 func_80023190();                         /* (s32 a, s32 b): angle (4096 per turn) of func_8009F6BC(a/4096, b/4096), wrapped >= 0 */
s32 func_800233B8();                         /* (s32 a): sqrt of the argument taken as unsigned */
s32 func_800233EC();                         /* (s32 a): sqrt for a > 0, else 0 */
void *func_800226A0();                       /* (obj, s32 *in, s32 *out): transform s32[3] arg1 by object arg0's matrix into arg2; returns arg2 */
s32 *func_800230FC();                        /* (s32 *dst, s32 *src): copy an s32[3] into words 5..7 of arg0, returns arg0 */
/* x.12 quaternion product. The definition returns a Quat4i by value (`Quat4i func_800673B0(Quat4i *, Quat4i *)`);
 * matched callers declare the hidden return pointer as a first argument: (out, a, b). */
void func_800673B0();                        /* (out, a, b); not for func_800673B0.c itself */

/* ---- inline helpers ---- */

/* func_800226A0 (vset / vscale) */
static inline void vec3f_set(Vec3f *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void vec3f_scale(Vec3f *v, f32 s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

/* func_80082CB0 (VSET): evaluate all three values into temporaries first, then store */
#define VEC3_SET(t, a, b, c)   \
    {                          \
        f32 _x = (a);          \
        f32 _y = (b);          \
        f32 _z = (c);          \
        (t).x = _x;            \
        (t).y = _y;            \
        (t).z = _z;            \
    }

/* func_8009B9B0 (Vec_init): zero in z, y, x order */
static inline void vec3i_zero(Vec3i *p) {
    p->z = 0;
    p->y = 0;
    p->x = 0;
}

/* func_80058A94 (muldiv) */
static inline s32 muldiv(s32 a, s32 b, s32 c) {
    return a * b / c;
}

/* func_8007D808 (isin): x.12 sine of a 4096-per-turn angle */
static inline s32 isin(s32 a) {
    if (a == 0) {
        return 0;
    }
    a %= 4096;
    return (s32)(func_80001CA0((f32)a * 0.000244140625f * 6.283185) * 4096.0f);
}

/* func_800766E4 (rsin_): same with the angle masked to 12 bits first, single return */
static inline s32 isin_masked(s32 a) {
    s32 t;
    s32 r;

    t = a & 0xFFF;
    if (t == 0) {
        r = 0;
    } else {
        t %= 4096;
        r = func_80001CA0((f32)t * 0.000244140625f * 6.283185) * 4096.0f;
    }
    return r;
}

/* func_80077584 (absdot_): |dot(a, b)| calling the dot product again for the result, as the game does */
static inline s32 vec3i_absdot(void *a, void *b) {
    if (func_80022E54(a, b) >= 0) {
        return func_80022E54(a, b);
    }
    return -func_80022E54(a, b);
}

#endif
