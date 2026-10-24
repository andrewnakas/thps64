/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* D3: &mtx through static inline call wrappers (rematerialised like the game, not hoisted), loop bound in a local (n_adj = 10 hoisted into a1), 16.0f scale in its own local. */
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_80037DC8;

typedef struct {
    s16 id;
    s16 idx;
    s16 off;
} Adj80037DC8;

typedef struct {
    s32 x0;
    s32 pos[3];
    s16 rot[3];
    u16 x16;
    u8 pad18[0x24 - 0x18];
} Rec80037DC8;

typedef struct {
    s16 x0;
    u16 x2;
    void *x4;
    u8 *x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1C;
    f32 x20;
    Vec3f_80037DC8 x24;
    u8 pad30[0x3A - 0x30];
    u16 x3A;
    u8 pad3C[2];
    u8 x3E;
    u8 x3F;
} Ent80037DC8;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    Ent80037DC8 **xC;
    s32 x10;
    Rec80037DC8 *x14;
    s32 *x18;
    u8 *x1C;
    s32 x20;
    s32 x24;
    s32 x28;
    u8 *x2C;
    u8 pad30[4];
    f32 x34;
    f32 x38;
    f32 x3C;
    f32 x40;
} Lvl80037DC8;

void func_80037C84(Lvl80037DC8 *, s32);
void *func_8009B898(void *, s32, s32);
s32 func_80039328(void *, s32);
void func_80039340(void *, void *, s32);
void *func_8009B7D8(void *, void *, s32, s32);
void func_8009ECF8(void *, void *);
s32 func_800B477C(void *, s32);
void *func_8009E6B4(void *, s32, s32);
void *func_8009E30C(s32);
void func_8009CAD0(void *);
void func_8009D8B4(void *, Vec3f_80037DC8 *);
void func_80001A30(void *, void *);
void func_800379B0(Lvl80037DC8 *, Ent80037DC8 *);
void func_800385A4(Lvl80037DC8 *);
void func_8003912C(Lvl80037DC8 *);
void func_80038840(Lvl80037DC8 *);

extern u8 D_800D3EB0[];
extern Adj80037DC8 D_800D3EE8[];
extern u8 D_800EA110[];
extern u8 D_800ECFE0[];

static __inline__ void ident_(f32 (*m)[3]) {
    func_8009CAD0(m);
}

static __inline__ void scale_(f32 (*m)[3], Vec3f_80037DC8 *v) {
    func_8009D8B4(m, v);
}

static __inline__ void tofix_(f32 (*m)[3], void *dst) {
    func_80001A30(m, dst);
}

void func_80037DC8(Lvl80037DC8 *arg0, s32 arg1) {
    u8 buf[8];
    Vec3f_80037DC8 rot;
    Vec3f_80037DC8 pos;
    f32 mtx[4][3];
    Vec3f_80037DC8 copy;
    Vec3f_80037DC8 v;
    void *hdr;
    u8 *d;
    u8 *bp;
    u8 *sb;
    s32 n;
    s32 *p;
    s32 *q;
    s32 i;
    s32 k;
    s32 n_adj;
    Ent80037DC8 *e;
    Rec80037DC8 *rec;
    Adj80037DC8 *a;

    func_80037C84(arg0, arg1);
    arg0->x0 = arg1;
    d = D_800D3EB0;
    hdr = func_8009B898(d, arg1, 4);
    n = *(s32 *)(d + 4) + func_80039328(d, arg1);
    bp = buf;
    func_80039340(bp, hdr, n);
    p = func_8009B7D8(d, bp, 0, 8);
    arg0->x24 = (s32)p;
    sb = (u8 *)&arg0->x14;
    arg0->x18 = p;
    arg0->x14 = (Rec80037DC8 *)(p + 1);
    p = func_8009B7D8(d, bp, 1, 8);
    arg0->x28 = (s32)p;
    arg0->x20 = (s32)p;
    arg0->x1C = (u8 *)(p + 1);
    q = func_8009B7D8(d, bp, 3, 8);
    arg0->x8 = *q;
    func_8009ECF8(D_800EA110, q);
    func_8009ECF8(D_800EA110, hdr);
    arg0->x4 = func_800B477C(D_800ECFE0, arg0->x8);
    arg0->x10 = **(s32 **)(sb + 4);
    arg0->xC = func_8009E6B4(D_800EA110, arg0->x10 << 2, 4);
    arg0->x3C = arg0->x34 = 1000000.0f;
    arg0->x40 = arg0->x38 = -1000000.0f;
    arg0->x2C = func_8009E6B4(D_800EA110, arg0->x10 << 6, 8);
    i = 0;
    while (1) {
        if (i >= arg0->x10) {
            break;
        }
        e = func_8009E30C(0x40);
        arg0->xC[i] = e;
        e->x0 = i;
        rec = &arg0->x14[i];
        {
            f32 x = rec->rot[0] * 9.58767268e-05f;
            f32 y = rec->rot[1] * 9.58767268e-05f;
            f32 z = rec->rot[2] * 9.58767268e-05f;

            rot.x = x;
            rot.y = y;
            rot.z = z;
        }
        {
            f32 x = rec->pos[0] * 0.000244140625f;
            f32 y = rec->pos[1] * 0.000244140625f;
            f32 z = rec->pos[2] * 0.000244140625f;

            pos.x = x;
            pos.y = y;
            pos.z = z;
        }
        e->x3A = e->x2 = rec->x16;
        e->x3E = 2;
        e->x3F = 0;
        ident_(mtx);
        n_adj = 10;
        k = 0;
        while (1) {
            if (k >= n_adj) {
                break;
            }
            if (D_800D3EE8[k].id == arg1 && i == D_800D3EE8[k].idx) {
                pos.y -= D_800D3EE8[k].off;
            }
            k++;
        }
        v.x = 0.0625f;
        v.y = 0.0625f;
        v.z = 0.0625f;
        scale_(mtx, &v);
        pos.x *= 0.0625f;
        pos.y *= 0.0625f;
        pos.z *= 0.0625f;
        if (pos.x < -32000.0f) {
            pos.x = -32000.0f;
        }
        if (pos.x > 32000.0f) {
            pos.x = 32000.0f;
        }
        if (pos.y < -32000.0f) {
            pos.y = -32000.0f;
        }
        if (pos.y > 32000.0f) {
            pos.y = 32000.0f;
        }
        if (pos.z < -32000.0f) {
            pos.z = -32000.0f;
        }
        if (pos.z > 32000.0f) {
            pos.z = 32000.0f;
        }
        copy = pos;
        tofix_(mtx, arg0->x2C + i * 64);
        {
            f32 k16 = 16.0f;
            f32 x = pos.x * k16;
            f32 y = pos.y * k16;
            f32 z = pos.z * k16;

            v.x = x;
            v.y = y;
            v.z = z;
        }
        e->x24 = v;
        e->x4 = rec;
        e->x8 = arg0->x1C + rec->x16 * 24;
        func_800379B0(arg0, e);
        arg0->x34 = (arg0->x34 < e->xC) ? arg0->x34 : e->xC;
        arg0->x3C = (arg0->x3C < e->x14) ? arg0->x3C : e->x14;
        arg0->x38 = (arg0->x38 > e->x18) ? arg0->x38 : e->x18;
        arg0->x40 = (arg0->x40 > e->x20) ? arg0->x40 : e->x20;
        i++;
    }
    func_800385A4(arg0);
    func_8003912C(arg0);
    func_80038840(arg0);
}
