#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_4A9C;

typedef struct {
    s16 d;
    s16 i;
    s32 (*f)();
} VtEnt4A9C;

typedef struct {
    u16 flags;
    u8 pad2[0x2];
    V3_4A9C pos;
    u8 pad10[0x14];
    u16 u24;
    u16 u26;
    u16 u28;
    u8 pad2A[0x1E];
    VtEnt4A9C *vt;
    u8 pad4C[0x258];
    s32 u2A4;
    u16 *ptr;
    u8 pad2AC[0x50];
    V3_4A9C target;
    u8 pad308[0xC];
    u16 u314;
    u16 u316;
    u16 u318;
    u16 u31A;
    u16 u31C;
    u16 u31E;
    u16 u320;
    u8 pad322[0x2];
    u16 u324;
    s16 u326;
    s16 u328;
    s16 u32A;
    u8 pad32C[0x8];
    s32 u334;
    u8 pad338[0x4];
    s32 u33C;
    s32 u340;
    s32 u344;
    s32 u348;
    s32 u34C;
} Obj4A9C;

typedef struct {
    u8 pad0[0x960];
    void *u960;
} G4A9C;

typedef struct {
    u8 pad0[0x8];
    u16 *b;
} Mdl4A9C;

extern G4A9C *D_800D61A8;
Mdl4A9C *func_800350C8(Obj4A9C *);
void func_80039F88(s32);
s32 func_80039E60(s32, s32, s32);
s32 func_8003A0C4(s32, V3_4A9C *, s32);
void func_80047124(V3_4A9C *, s32 *);
void func_800472C0(V3_4A9C *, V3_4A9C *);
s32 func_8004706C(V3_4A9C *, V3_4A9C *);
void func_800617B8(V3_4A9C *, s32);
void func_80043628(Obj4A9C *, s32, s32);
s32 func_80070CE0(Obj4A9C *, s32);

static inline s16 sdiv_4A9C(u16 a, u16 n) {
    return ((s16)a << 12) / (n * 100);
}

static inline void scale_on_4A9C(Obj4A9C *o) {
    if (!(o->flags & 0x200)) {
        o->flags |= 0x200;
        o->u24 = o->u26 = o->u28 = 0x1000;
    }
}

s32 func_80064A9C(Obj4A9C *o, u16 cmd) {
    V3_4A9C v;
    s32 n1;
    s32 n2;

    switch (cmd) {
    case 0x4309: {
        Mdl4A9C *m;
        u16 t = *o->ptr++;
        o->u324 = t;
        if (t != 0) {
            o->u2A4 |= 0x10;
        } else {
            o->u2A4 &= ~0x10;
        }
        m = func_800350C8(o);
        if (m != NULL) {
            o->u326 = m->b[5] - m->b[4];
            o->u328 = m->b[7] - m->b[6];
            o->u32A = m->b[9] - m->b[8];
        } else {
            o->u326 = 0xC8;
            o->u328 = 0x2BC;
            o->u32A = 0xC8;
        }
        break;
    }
    case 0x4305:
        {
            u16 t = *o->ptr++;
            if (t != 0) {
                o->flags |= 8;
            } else {
                o->flags &= ~8;
            }
        }
        break;
    case 0x4507:
        if (o->u33C != 0) {
            func_80039F88(o->u33C);
        }
        {
            u16 t = *o->ptr++;
            o->u33C = func_80039E60(t, 0x2710, 0);
        }
        o->u340 = -1;
        break;
    case 0x4508:
        if (o->u33C != 0) {
            func_80039F88(o->u33C);
        }
        {
            u16 a = *o->ptr++;
            o->u340 = *o->ptr++;
            o->u33C = func_8003A0C4(a, &o->pos, 0);
            break;
        }
    case 0x4509:
        if (o->u33C != 0) {
            func_80039F88(o->u33C);
        }
        o->u33C = 0;
        break;
    case 0x4304:
        scale_on_4A9C(o);
        {
            u16 a = *o->ptr++;
            o->u314 = o->u316 = o->u318 = *o->ptr++;
            if (o->u318 != 0) {
                o->u31C = o->u31E = o->u31A = ((s16)a << 12) / (o->u314 * 100);
            } else {
                o->u31C = o->u31E = o->u31A = ((s16)a << 12) / 100;
            }
            o->u24 += o->u31A;
            o->u26 += o->u31C;
            o->u28 += o->u31E;
            break;
        }
    case 0x4306:
        scale_on_4A9C(o);
        {
            u16 a = *o->ptr++;
            o->u314 = *o->ptr++;
            if (o->u314 != 0) {
                o->u31A = sdiv_4A9C(a, o->u314);
            } else {
                o->u31A = ((s16)a << 12) / 100;
            }
            o->u24 += o->u31A;
            break;
        }
    case 0x4307:
        scale_on_4A9C(o);
        {
            u16 a = *o->ptr++;
            o->u316 = *o->ptr++;
            if (o->u316 != 0) {
                o->u31C = sdiv_4A9C(a, o->u316);
            } else {
                o->u31C = ((s16)a << 12) / 100;
            }
            o->u26 += o->u31C;
            break;
        }
    case 0x4308:
        scale_on_4A9C(o);
        {
            u16 a = *o->ptr++;
            o->u318 = *o->ptr++;
            if (o->u318 != 0) {
                o->u31E = sdiv_4A9C(a, o->u318);
            } else {
                o->u31E = ((s16)a << 12) / 100;
            }
            o->u28 += o->u31E;
            break;
        }
    case 0x4303:
        o->u320 = *o->ptr++;
        break;
    case 0x4302: {
        u16 x = *o->ptr++;
        u16 y = *o->ptr++;
        u16 z = *o->ptr++;
        o->u344 = x << 11;
        o->u348 = y << 11;
        o->u34C = z << 11;
        o->u2A4 |= 4;
        break;
    }
    case 0x4300:
        if (o->u334 != 0) {
            return 1;
        }
        o->ptr--;
        return 0;
    case 0x4220: {
        s32 *p = (s32 *)(((u32)o->ptr + 3) & ~3);
        v.x = *p++;
        v.y = *p++;
        v.z = *p++;
        n1 = 0xC;
        func_80047124(&v, &n1);
        o->ptr = (u16 *)p;
        goto check;
    }
    case 0x4221:
        {
            u16 a = *o->ptr++;
            if (a & 0x2000) {
                a = o->vt[10].f((u8 *)o + o->vt[10].d, a);
            }
            func_800617B8(&v, a);
            goto check;
        }
    case 0x4222: {
        s32 *p = (s32 *)(((u32)o->ptr + 3) & ~3);
        v.x = *p++;
        v.y = *p++;
        v.z = *p++;
        n2 = 0xC;
        func_80047124(&v, &n2);
        func_800472C0(&v, &o->pos);
        o->ptr = (u16 *)p;
    }
    check:
        if (func_8004706C(&o->target, &v) != 0) {
            o->target = v;
            o->u2A4 |= 1;
        }
        break;
    case 0x4205:
        o->vt[2].f((u8 *)o + o->vt[2].d);
        return 0;
    case 0x4301:
        if (D_800D61A8->u960 == o) {
            D_800D61A8->u960 = NULL;
        }
        o->flags |= 1;
        o->vt[2].f((u8 *)o + o->vt[2].d);
        func_80043628(o, 0, 0);
        return 0;
    default:
        return func_80070CE0(o, cmd);
    }
    return 1;
}
