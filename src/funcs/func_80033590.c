/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    u8 pad0[8];
    s32 v8;
    u8 padC[0x58 - 0xC];
} Entry58;

typedef struct {
    u8 pad0[8];
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    s16 h10;
    s16 h12;
} Bone33590;

typedef struct {
    u8 pad0[8];
    Bone33590 *p8;
    Vec3f vC;
    Vec3f v18;
    Vec3f t;
    u8 pad30[0x10];
} Mtx40;

typedef struct {
    u8 pad0[4];
    Vec3i pos;
} Src33590;

typedef struct {
    Entry58 *p0;
    Mtx40 *p4;
    Src33590 *p8;
    u8 padC[4];
    u8 a10[0x98 - 0x10];
    Vec3f v98;
    u8 aA4[4];
    Vec3f vA8;
    u8 padB4[4];
    f32 fB8;
    f32 fBC;
    u8 padC0[4];
    Vec3i vC4;
    s8 bD0;
    u8 bD1;
    u8 bD2;
    u8 bD3;
    u8 padD4[4];
} Ent33590;

typedef struct {
    f32 m[12];
    Vec3f t;
    f32 w;
} Mtx33590;

void *func_80038F9C(Entry58 *, s32);
void func_8009BB40(void *, s32);
void func_8009CB68(f32 *, Vec3f *);
void func_8009D624(f32 *, f32);
void func_800A6AB0(void *, s32, s32 *, f32 *);
void func_800A6D38(void *, s32, f32 *);
extern s32 D_800D36D0;
extern s32 D_800D36EC;
extern s32 D_800D3C68[];
extern Mtx40 D_800F6C80[];
extern Ent33590 D_800F78C0[];
extern Entry58 D_800FA140[];

static inline void mtxinit_(f32 *m, Vec3f *t, s32 flip) {
    func_8009CB68(m, t);
    if (flip) {
        func_8009D624(m, 3.1415927f);
    }
}

void func_80033590(s32 id, Src33590 *src, s32 arg2, s32 arg3, s32 flip) {
    Ent33590 *tbl;
    Vec3f tmp;
    Vec3f tmp2;
    Ent33590 *e;
    Entry58 **pa;
    f32 sp7C;
    u32 k;
    Mtx40 **pb;
    f32 x0, y0, z0;
    f32 x1, y1, z1;
    f32 s;
    s32 ok;
    Mtx40 *m;
    f32 x2, y2, z2;
    s32 sp78;
    s32 i;
    Entry58 *ent;
    f32 x3, y3, z3;
    Mtx40 *found;

    if (D_800D36EC >= 0x30) {
        return;
    }
    ent = NULL;
    found = NULL;
    if (arg3 < 0) {
        pa = &ent;
        pb = &found;
        for (i = 0; i < D_800D36D0; i++) {
            *pa = &D_800FA140[i];
            if ((*pb = func_80038F9C(&D_800FA140[i], id)) != 0) {
                goto found1;
            }
        }
        ok = 0;
    check:
        if (!ok) {
            return;
        }
    }
    tbl = D_800F78C0;
    e = &tbl[D_800D36EC];
    D_800D36EC++;
    x0 = src->pos.x * (1.0f / 4096.0f);
    y0 = src->pos.y * (1.0f / 4096.0f);
    z0 = src->pos.z * (1.0f / 4096.0f);
    tmp.x = x0;
    tmp.y = y0;
    tmp.z = z0;
    e->v98 = tmp;
    e->p0 = ent;
    e->p4 = &D_800F6C80[D_800D36EC];
    e->p8 = src;
    e->vC4 = src->pos;
    e->bD2 = 0;
    e->bD3 = flip;
    if (found != NULL) {
        e->p4 = &D_800F6C80[D_800D36EC];
        m = e->p4;
        *m = *found;
        m->t = e->v98;
        tmp2.x = found->t.x;
        tmp2.y = found->t.y;
        tmp2.z = found->t.z;
        x1 = m->t.x - tmp2.x;
        y1 = m->t.y - tmp2.y;
        z1 = m->t.z - tmp2.z;
        tmp.x = x1;
        tmp.y = y1;
        tmp.z = z1;
        x2 = m->p8->h8;
        y2 = m->p8->hC;
        z2 = m->p8->h10;
        tmp2.x = x2;
        tmp2.y = y2;
        tmp2.z = z2;
        m->vC = tmp2;
        x3 = m->p8->hA;
        y3 = m->p8->hE;
        z3 = m->p8->h12;
        tmp2.x = x3;
        tmp2.y = y3;
        tmp2.z = z3;
        m->v18 = tmp2;
        tmp2.x = m->t.x;
        tmp2.y = m->t.y;
        tmp2.z = m->t.z;
        m->vC.x += tmp2.x;
        m->vC.y += tmp2.y;
        m->vC.z += tmp2.z;
        tmp2.x = m->t.x;
        tmp2.y = m->t.y;
        tmp2.z = m->t.z;
        m->v18.x += tmp2.x;
        m->v18.y += tmp2.y;
        m->v18.z += tmp2.z;
    } else {
        e->p4 = NULL;
    }
    goto after;
found1:
    ok = 1;
    goto check;
after:
    if (arg3 == -1) {
        sp78 = ent->v8;
        e->bD1 = 0;
    } else {
        sp78 = arg3;
        e->bD1 = 1;
    }
    sp7C = 750.0f;
    func_800A6AB0(e->a10, 1, &sp78, &sp7C);
    {
    f32 mtx[16];
    s = 0.0625f;
    tmp.x = s;
    tmp.y = s;
    tmp.z = s;
    mtxinit_(mtx, &tmp, flip);
    e->v98.x *= s;
    e->v98.y *= s;
    e->v98.z *= s;
    *(Vec3f *)&mtx[12] = e->v98;
    func_800A6D38(e->a10, 0, mtx);
    }
    e->bD0 = arg2;
    func_8009BB40(e->aA4, 0x4C9);
    e->fBC = e->fB8 = 12.5f;
    e->vA8 = e->v98;
    for (k = 0; k < 11; k++) {
        if (id == D_800D3C68[k]) {
            e->bD0 = -2;
        }
    }
}
