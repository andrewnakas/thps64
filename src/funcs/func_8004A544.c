#include "common.h"

typedef struct {
    s32 x, y, z;
} V3;

typedef struct {
    s16 x, y, z;
} V3S;

typedef struct {
    s16 adj;
    void (*fn)(void *);
} VEnt;

typedef struct {
    u8 pad0[0x18];
    VEnt e3;
    VEnt e4;
} VTbl;

typedef struct {
    u16 flags;
    u8 pad2[2];
    V3 pos;
    V3S rot;
    u8 pad16[0x32];
    VTbl *vt;
    u8 pad4C[0x11D];
    u8 b169;
    u8 b16A;
    u8 pad16B;
    V3 x16C;
    u8 pad178[0x24];
    V3 x19C;
    u8 pad1A8[0xC];
    V3 x1B4;
    u8 pad1C0[0xC];
    V3S x1CC;
    u8 pad1D2[0xE];
    V3S x1E0;
    u8 pad1E6[0xE];
    V3S x1F4;
    u8 pad1FA[0x22];
    u16 h21C;
    u8 pad21E;
    u8 b21F;
    u8 pad220;
    u8 b221;
    u8 pad222[0xA];
    u16 h22C;
    u16 h22E;
    u8 b230;
    u8 b231;
} Obj4A544;

V3S func_8004690C(V3S *, V3S *);
void func_80046AF0(V3S *, s32 *);
void func_80046C1C(V3S *, V3S *);
void func_80046D00(V3S *);
V3 func_80046E04(V3 *, s32 *);
V3 func_80046FBC(V3 *, V3 *);
void func_800472C0(V3 *, V3 *);
void func_8004A314(void);

void func_8004A544(Obj4A544 *o) {
    s32 n;
    s32 m;
    V3S *a;

    if (o->flags & 2) {
        func_8004A314();
        o->vt->e4.fn((u8 *)o + o->vt->e4.adj);
        if (o->b169 < 2) {
            o->h22E = o->h21C;
            o->vt->e3.fn((u8 *)o + o->vt->e3.adj);
            o->h22C = o->h21C;
            o->b230 = o->b21F;
            o->b231 = o->b221;
            return;
        }
    } else {
        o->vt->e4.fn((u8 *)o + o->vt->e4.adj);
        if (o->b169 < 2) {
            o->vt->e3.fn((u8 *)o + o->vt->e3.adj);
            return;
        }
    }
    if (++o->b16A >= o->b169) {
        o->b16A = 0;
        o->pos = o->x19C;
        o->x16C = o->pos;
        o->rot = o->x1E0;
        o->x1CC = o->rot;
        if (o->flags & 2) {
            o->h22E = o->h21C;
            o->vt->e3.fn((u8 *)o + o->vt->e3.adj);
            o->h22C = o->h21C;
            o->b230 = o->b21F;
            o->b231 = o->b221;
        } else {
            o->vt->e3.fn((u8 *)o + o->vt->e3.adj);
        }
        o->x19C = o->pos;
        o->pos = o->x16C;
        {
            V3 t;
            V3 d;

            d = func_80046FBC(&o->x19C, &o->x16C);
            n = o->b169;
            t = func_80046E04(&d, &n);
            o->x1B4 = t;
        }
        o->x1E0 = o->rot;
        o->rot = o->x1CC;
        a = &o->x1F4;
        o->x1F4 = func_8004690C(&o->x1E0, &o->x1CC);
        if (o->x1F4.x < -0x800) {
            o->x1F4.x += 0x1000;
        }
        if (o->x1F4.x > 0x800) {
            o->x1F4.x -= 0x1000;
        }
        if (o->x1F4.y < -0x800) {
            o->x1F4.y += 0x1000;
        }
        if (o->x1F4.y > 0x800) {
            o->x1F4.y -= 0x1000;
        }
        if (o->x1F4.z < -0x800) {
            o->x1F4.z += 0x1000;
        }
        if (o->x1F4.z > 0x800) {
            o->x1F4.z -= 0x1000;
        }
        m = o->b169;
        func_80046AF0(a, &m);
    } else {
        func_800472C0(&o->pos, &o->x1B4);
        func_80046C1C(&o->rot, &o->x1F4);
        func_80046D00(&o->rot);
    }
}
