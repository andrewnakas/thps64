/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* cflags: -O2 -fno-schedule-insns */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3i;

typedef struct {
    s32 x, y, z, w;
} Q4i;

typedef struct {
    s32 unk0;
    V3i pos;
} Src;

typedef struct {
    u8 pad[0x964];
    void *board;
} Owner;

typedef struct {
    s16 unk1A_pad[0xC];
    s16 c;
    s16 b;
    s16 a;
} Tbl;

typedef struct {
    s16 f0;
    u8 pad2[0x38];
    s16 f3A;
    u8 pad3C[0xC];
    void *f48;
    u8 pad4C[0x6];
    u16 f52;
    u8 pad54[0x108];
    s16 f15C;
    u8 pad15E[0xAA];
    s16 f208;
    u8 pad20A[0x2AA];
    Owner *f4B4;
    u8 pad4B8[0x4];
    s32 f4BC;
    u8 pad4C0[0xC];
    s32 f4CC;
    V3i f4D0;
    u8 pad4DC[0xC];
    s32 f4E8;
    Owner *f4EC;
    s32 f4F0;
    u8 pad4F4[0xC];
    V3i f500;
    u8 pad50C[0xC];
    s32 f518;
    s32 f51C;
    u8 pad520[0x8];
    s32 f528;
    u8 pad52C[0x18];
    s16 f544;
    s16 f546;
    u8 pad548[0xC];
    s32 f554;
    s32 f558;
    s32 f55C;
    s32 f560;
    s32 f564;
    s32 f568;
    s32 f56C;
    s32 f570;
    s32 f574;
    s32 f578;
    s32 f57C;
    s32 f580;
    s32 f584;
    s32 f588;
    s32 f58C;
    s32 f590;
    s32 f594;
    s32 f598;
    s32 f59C;
    s32 f5A0;
    u8 pad5A4[0xC];
    s32 f5B0;
    u8 pad5B4[0x24];
    s32 f5D8;
    s32 f5DC;
    s16 f5E0;
    s16 f5E2;
    s16 f5E4;
    u8 pad5E6[0x22];
    s32 f608;
    s32 f60C;
    s32 f610;
    void *f614;
    s32 f618;
    s32 f61C;
    s32 f620;
    s32 f624;
    u8 pad628[0x20];
    u8 f648;
    u8 pad649[0x3];
    s32 f64C;
    s32 f650;
    u8 pad654[0x4];
    s32 f658;
    u8 pad65C[0xC];
    s32 f668;
    u8 pad66C[0x1C];
    s32 f688;
    u8 pad68C[0x10];
    s32 f69C;
    u8 pad6A0[0x24];
    V3i f6C4;
    u8 pad6D0[0x1C];
    s16 f6EC;
    u8 pad6EE[0x12];
    s32 f700;
    s32 f704;
    s32 f708;
    s32 f70C;
    u8 pad710[0x10];
    s32 f720;
} Obj73AE0;

void func_8004A08C(void *);
void func_8007919C(void *);
void func_80073EA0(void *);
void func_8004B30C(void *, void *);
extern u8 D_8001DF68[];
extern u8 D_800D49E0[];
extern s32 D_800DE0EC;
extern s32 D_800DE0C0;
extern s32 D_800DE0C4;
extern s32 D_800DE0C8;
extern Tbl D_800DE0F0;
extern u8 D_800DE144[];
extern s32 D_800DE140;

Obj73AE0 *func_80073AE0(Obj73AE0 *o, Owner *owner, s32 id) {
    V3i t;
    s32 one;
    void *q;

    func_8004A08C(o);
    o->f48 = D_8001DF68;
    o->f208 = id;
    func_8007919C((u8 *)o + 0x20C);
    func_8007919C((u8 *)o + 0x2B4);
    func_8007919C((u8 *)o + 0x35C);
    func_8007919C((u8 *)o + 0x404);
    o->f4B4 = owner;
    o->f4BC = 1;
    o->f4CC = 0;
    o->f4EC = owner;
    o->f4F0 = 1;
    o->f51C = 0xC0;
    o->f528 = 0;
    o->f544 = 0;
    o->f546 = 0;
    one = 0x1000;
    o->f554 = 0;
    o->f558 = 0;
    o->f55C = 0;
    o->f560 = one;
    o->f564 = 0;
    o->f568 = 0;
    o->f56C = 0;
    o->f570 = 0x1000;
    o->f574 = 0;
    o->f578 = 0;
    o->f57C = 0;
    o->f580 = 0x1000;
    o->f584 = 0;
    o->f588 = 0;
    o->f58C = 0;
    o->f590 = 0x1000;
    o->f594 = 0;
    o->f598 = 0;
    o->f59C = 0;
    o->f5A0 = 0x1000;
    o->f5B0 = 1;
    o->f5D8 = -1;
    o->f5DC = -1;
    o->f5E0 = 0x200;
    o->f5E2 = 0x310;
    o->f5E4 = 0x568;
    o->f608 = 0;
    o->f60C = 0xF;
    q = &o->f610;
    o->f610 = 0;
    o->f614 = q;
    o->f618 = 0;
    o->f61C = 0;
    o->f620 = 0;
    o->f624 = 0x1000;
    o->f648 = 0;
    o->f64C = 0;
    o->f650 = 0;
    o->f658 = 0;
    o->f6EC = 0;
    o->f700 = 0;
    o->f704 = 0;
    o->f708 = 0;
    o->f70C = 0x1000;
    o->f720 = 0;
    {
        Owner *ow = o->f4EC;
        u8 *bd = D_800D49E0;
        if (ow->board == bd) {
            o->f208 = 0;
        } else if (ow->board == bd + 0x18C) {
            o->f208 = 1;
        }
    }
    {
        s32 k = 0x1000;
        t.x = 0;
        t.y = 0;
        t.z = k;
    }
    o->f6C4 = t;
    o->f688 = 0;
    o->f69C = 0x3E8;
    o->f668 = 0;
    o->f4D0 = ((Src *)o->f4B4)->pos;
    o->f4E8 = 0;
    o->f500 = ((Src *)o->f4EC)->pos;
    o->f518 = 0;
    o->f3A = 0x63;
    D_800DE0EC = 2;
    D_800DE0C0 = D_800DE0F0.a;
    D_800DE0C4 = D_800DE0F0.b;
    D_800DE0C8 = D_800DE0F0.c;
    o->f0 = 1;
    func_80073EA0(o);
    func_8004B30C(o, D_800DE144);
    D_800DE140++;
    o->f15C = 0;
    o->f52 &= ~2;
    return o;
}
