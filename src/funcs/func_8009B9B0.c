/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 u;
    s16 v;
    s16 x;
    s16 pad6;
    s16 y;
    s16 z;
    u8 r, g, b, a;
} Vtx16;

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    s32 unk0;
    Vec3i unk4;
    Vtx16 *unk10;
    f32 unk14;
    f32 unk18;
} Quad;

void *func_8009E6B4(void *, s32, s32);
extern u8 D_800EA110[];

static inline void Vtx_init(Vtx16 *p, s16 u, s16 v) {
    p->u = u;
    p->v = v;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    p->r = 0xFF;
    p->g = 0xFF;
    p->b = 0xFF;
    p->a = 0xFF;
}

static inline void Vec_init(Vec3i *p) {
    p->z = 0;
    p->y = 0;
    p->x = 0;
}

Quad *func_8009B9B0(Quad *arg0) {
    Vtx16 *v;
    Vec3i t;

    arg0->unk0 = 0;
    v = func_8009E6B4(D_800EA110, 0x40, 8);
    arg0->unk10 = v;
    Vtx_init(&v[0], -1, -1);
    Vtx_init(&v[1], 1, -1);
    Vtx_init(&v[2], 1, 1);
    Vtx_init(&v[3], -1, 1);
    arg0->unk18 = 1.0f;
    arg0->unk14 = 1.0f;
    Vec_init(&t);
    arg0->unk4 = t;
    return arg0;
}
