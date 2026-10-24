/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* D4: the angle delta is sign-extended by hand into one reused variable (t = b << 16; t >>= 16): CSE then cannot fold the later >> 3 into one >> 19 (the overwritten intermediate invalidates the shift equivalence), like the game. Both turn tails use the same inline. (G4 draft) */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_430C;

typedef struct {
    s16 x, y, z;
} SV_430C;

typedef struct {
    s32 x, y, z, pad;
} V4_430C;

typedef struct {
    u8 pad0[0x4];
    V3_430C pos;
    SV_430C rot;
    u8 pad16[0xE];
    u16 u24;
    u16 u26;
    u16 u28;
    u8 pad2A[0x26];
    u16 u50;
    u8 pad52[0x32];
    s32 u84;
    s32 u88;
    s32 u8C;
    u8 pad90[0xC];
    s32 u9C;
    s32 uA0;
    s32 uA4;
    u8 padA8[0x10];
    s32 uB8;
    s16 uBC;
    u8 padBE[0xE];
    s32 uCC;
    s16 uD0;
    u8 padD2[0x1C2];
    u8 u294;
    u8 pad295[0x1];
    u8 u296;
    u8 pad297[0x1];
    u8 u298;
    u8 pad299[0x3];
    u16 u29C;
    u8 pad29E[0x6];
    s32 u2A4;
    s32 u2A8;
    u8 pad2AC[0x20];
    u16 u2CC;
    u8 pad2CE[0x2];
    u16 u2D0;
    u8 pad2D2[0x22];
    u16 u2F4;
    u8 pad2F6[0x6];
    V3_430C target;
    u8 pad308[0xC];
    u16 u314;
    u16 u316;
    u16 u318;
    u16 u31A;
    u16 u31C;
    u16 u31E;
    u8 pad320[0x14];
    s32 u334;
    s32 u338;
    s32 u33C;
    s32 u340;
} Obj430C;

extern u8 D_800D6FDC[];
extern s32 D_800DE808;
void func_80063AD8(Obj430C *);
void func_80072B2C(Obj430C *, s32);
void func_800658F8(Obj430C *);
void func_80046FBC(V4_430C *, V3_430C *, V3_430C *);
s32 func_800474C8(V4_430C *);
void func_80047D40(SV_430C *, V3_430C *, V3_430C *);
void func_80047980(s32 *, s32, SV_430C *);
void func_80049934(SV_430C, s32 *, s32 *, SV_430C, s32);
void func_800472C0(s32 *, u8 *);
void func_800648AC(Obj430C *);
void func_8003A0CC(s32, V3_430C *, s32);

#define STEER_430C(o, ang)                                            \
    {                                                                 \
        V4_430C t;                                                    \
        s32 v;                                                        \
        func_80047D40(&ang, &o->pos, &o->target);                     \
        func_80046FBC(&t, &o->target, &o->pos);                       \
        v = 0x1FE0 / func_800474C8(&t);                               \
        if (v < -0x100) {                                             \
            v = -0x100;                                               \
        } else if (v > 0x100) {                                       \
            v = 0x100;                                                \
        } else if (v > 0 && v < 4) {                                  \
            v = 4;                                                    \
        } else if (v < 0 && v > -4) {                                 \
            v = -4;                                                   \
        }                                                             \
        func_80049934(o->rot, &o->uB8, &o->uCC, ang, v);              \
        o->rot.x = 0;                                                 \
    }

static inline void turn_430C(Obj430C *o, s16 b) {
    if (b < -0x800) {
        b += 0x1000;
    }
    if (b > 0x800) {
        b -= 0x1000;
    }
    {
        s32 t;
        t = b << 16;
        t >>= 16;
        if (t == 0) {
            o->uBC = 0;
        } else {
            o->uD0 = t >> 3;
        }
    }
}

void func_8006430C(Obj430C *o) {
    V4_430C d;
    SV_430C ang;
    s16 a;

    if (o->u314 != 0) {
        o->u314--;
        o->u24 += o->u31A;
    }
    if (o->u316 != 0) {
        o->u316--;
        o->u26 += o->u31C;
    }
    if (o->u318 != 0) {
        o->u318--;
        o->u28 += o->u31E;
    }
    o->u9C = o->uA0 = o->uA4 = 0;
    if (o->u334 == 0) {
        o->u338++;
    }
    o->u29C = o->u50;
    if (o->u50 & 1) {
        o->u298++;
        o->u50 &= ~1;
    }
    if (o->u2A4 & 0x10) {
        func_80063AD8(o);
        return;
    }
    if (o->u294 != 0) {
        if (o->u2F4 != 0) {
            o->u2F4--;
        } else {
            func_80072B2C(o, o->u2A8);
        }
    } else {
        func_800658F8(o);
    }
    if (o->u2A4 & 1) {
        func_80046FBC(&d, &o->pos, &o->target);
        if (func_800474C8(&d) <= o->u2CC) {
            o->pos = o->target;
            if (o->u2D0 < 2) {
                o->u84 = o->u88 = o->u8C = 0;
            }
            o->u2A4 &= ~1;
        } else if (o->u2D0 == 0) {
            func_80047D40(&ang, &o->pos, &o->target);
            func_80047980(&o->u84, o->u2CC, &ang);
        } else if (o->u2D0 == 1) {
            STEER_430C(o, ang);
            func_80047980(&o->u9C, o->u2CC, &ang);
            if (o->u2A4 & 0x20) {
                a = (ang.y - o->rot.y) & 0xFFF;
            } else {
                a = 0;
            }
            if (a > 0x800) {
                a -= 0x1000;
            }
            if (a > 0x400) {
                a = 0x400;
            } else if (a < -0x400) {
                a = -0x400;
            }
            turn_430C(o, ((-a >> 1) & 0xFFF) - o->rot.z);
        } else if (o->u2D0 == 2) {
            STEER_430C(o, ang);
            func_80047980(&o->u9C, o->u2CC, &ang);
        }
    } else if (o->u2D0 == 1) {
        turn_430C(o, -o->rot.z);
    }
    if (o->u296 != 0) {
        func_800472C0(&o->u9C, D_800D6FDC);
    }
    func_800648AC(o);
    if (o->u340 != -1 && D_800DE808 % o->u340 == 0) {
        func_8003A0CC(o->u33C, &o->pos, 0);
    }
    o->u334 = 0;
}
