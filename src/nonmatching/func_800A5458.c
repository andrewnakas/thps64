/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.903; w f2 vs f0 and game's mov.s copy of x*inv, best 112/124. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 112/124 (F5 draft, unchanged). Left: w gets f2 (game f0) and the game keeps a copy of x*inv
 * (mov.s f4,f2) for the +1.0 add, where ours adds straight from the product register. The CSE dump shows the
 * out->x read-back already replaced by the product pseudo, so the game's copy must come from a pseudo CSE could not
 * replace (different block or user variable). Inline screen-mapping helper and a block-local px copy: no change. */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0xC];
    s16 left;
    s16 right;
    s16 bottom;
    s16 top;
    u8 pad14[0x120 - 0x14];
    f32 m[4][4];
    u8 pad160[0x10];
    f32 near;
} View;

s32 func_800A5458(View *c, Vec3 *in, Vec3 *out, f32 *pw) {
    Vec3 t;
    f32 w;
    f32 inv;
    f32 sx;
    f32 sy;
    {
        Vec3 *_v = in;
        f32 (*_m)[4] = c->m;
        f32 _x = _v->x * _m[0][0] + _v->y * _m[1][0] + _v->z * _m[2][0] + _m[3][0];
        f32 _y = _v->x * _m[0][1] + _v->y * _m[1][1] + _v->z * _m[2][1] + _m[3][1];
        f32 _z = _v->x * _m[0][2] + _v->y * _m[1][2] + _v->z * _m[2][2] + _m[3][2];
        t.x = _x;
        t.y = _y;
        t.z = _z;
        *out = t;
    }
    if (out->z <= c->near) {
        out->x = out->y = 0.0f;
        out->z = 1000000.0f;
        return 0;
    }
    w = in->x * c->m[0][3] + in->y * c->m[1][3] + in->z * c->m[2][3] + c->m[3][3];
    if (pw != NULL) {
        *pw = w;
    }
    if (w <= 0.0f) {
        out->x = out->y = 0.0f;
        out->z = 1000000.0f;
        return 0;
    }
    inv = 1.0f / w;
    out->y *= inv;
    out->x *= inv;
    sx = (out->x + 1.0f) * 0.5f * (c->right - c->left);
    sy = (out->y + 1.0f) * 0.5f * (c->bottom - c->top);
    out->x = c->left + sx;
    out->y = c->top + sy;
    return 1;
}
