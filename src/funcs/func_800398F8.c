#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[0xC];
    u8 vol;
    u8 pad11[3];
    s32 x14;
    u8 pad18[0x2C];
} Slot398F8;

typedef struct {
    u8 pad0[4];
    Slot398F8 s[3];
    u8 padD0[0x39];
    u8 b109;
} Obj398F8;

typedef struct {
    u8 pad0[0xC];
    s32 xC;
    u8 pad10[0x68];
} Ent5C1C_398F8;

typedef struct {
    u32 flags;
    u32 pad;
} Snd4040;

void func_800A9588(void *, s32);
void func_800AA73C(void *, void *);
void func_800AA8C8(void *, void *);
extern s32 D_800C0E20;
extern f32 D_800D0FEC;
extern Snd4040 D_800D4040[];
extern Ent5C1C_398F8 D_800D5C1C[];
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern u8 D_800EA9C0[];

static __inline__ u8 calc(Obj398F8 *arg0, u16 arg1) {
    s32 n;
    s32 x = arg1;

    n = x / arg0->b109;
    if (n >= 0x100) {
        f32 c;
        f32 t;
        u32 v;
        u32 m;

        t = D_800D0FEC * 255.0f;
        if (!(t >= (c = 2147483648.0f))) {
            v = (s32) t;
        } else {
            f32 d = t - c;
            m = 0x80000000;
            v = (s32) d | m;
        }
        return v;
    }
    if (n < 0) {
        return 0;
    }
    {
        f32 c;
        f32 t;
        u32 v;
        u32 m;

        c = (f32) n;
        t = D_800D0FEC;
        t *= c;
        if (!(t >= (c = 2147483648.0f))) {
            v = (s32) t;
        } else {
            f32 d = t - c;
            m = 0x80000000;
            v = (s32) d | m;
        }
        return v;
    }
}

void func_800398F8(Obj398F8 *o, s32 arg1, s32 arg2, s32 arg3) {
    u32 fl;
    u8 *p;

    if (D_800DC618 == 2 || D_800DC6D8 == 2) {
        return;
    }
    fl = D_800D4040[arg1 & 0xFF].flags;
    if (fl & 0x10000000) {
        u8 *d = D_800EA9C0;
        func_800AA8C8(d, &o->s[0]);
        func_800A9588(d, o->s[0].id);
        o->s[0].id = arg2 & 0xFF;
        p = &o->s[0].vol;
        if ((arg1 & 0xFF) != 7) {
            *p = calc(o, arg3);
        } else {
            o->s[0].vol = 0;
        }
        o->s[0].x14 = 0;
        if ((arg1 & 0xFF) != 7) {
            func_800AA73C(D_800EA9C0, &o->s[0]);
        }
    } else if (D_800D5C1C[D_800C0E20].xC != 0 && (fl & 0x20000000)) {
        u8 *d = D_800EA9C0;
        func_800AA8C8(d, &o->s[1]);
        func_800A9588(d, o->s[1].id);
        o->s[1].id = arg2 & 0xFF;
        o->s[1].vol = calc(o, arg3);
        o->s[1].x14 = 0;
        func_800AA73C(D_800EA9C0, &o->s[1]);
    } else if (D_800D4040[arg1 & 0xFF].flags & 0x08000000) {
        u8 *d = D_800EA9C0;
        func_800AA8C8(d, &o->s[2]);
        func_800A9588(d, o->s[2].id);
        o->s[2].id = arg2 & 0xFF;
        o->s[2].vol = calc(o, arg3);
        o->s[2].x14 = 0;
        func_800AA73C(D_800EA9C0, &o->s[2]);
    }
}
