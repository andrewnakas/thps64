/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Obj80080554 Obj80080554;

typedef struct {
    s16 delta;
    s16 idx;
    void (*fn)(void *, s32);
} VEnt80080554;

struct Obj80080554 {
    u8 pad0[0x48];
    VEnt80080554 *vt;
    u8 pad4C[0x214 - 0x4C];
    s32 unk214;
};

typedef struct {
    u8 pad0[0xB4];
    Obj80080554 *objs[3];
    u8 padC0[0x118 - 0xC0];
    s32 unk118;
} State80080554;

typedef struct {
    u8 pad0[0x3E0];
    s32 player;
} Cfg80080554;

typedef struct {
    u8 pad0[0xC];
    s32 active;
    u8 pad10[0x78 - 0x10];
} Slot80080554;

typedef struct {
    u8 pad0[0xC];
    u8 flags[124][20];
    u8 pad9BC[8];
    s32 mask[4];
} Rec80080554;

extern s32 func_80022DF4(void);
extern void func_8003A2DC(void);
extern void func_80043B24(void);
extern void func_80043F84(s32, s32);
extern void func_80043FA8(void *);
extern void func_80049E24(s32);
extern s32 func_80081F18(State80080554 *);
extern s32 func_80096020(s32, s32);
extern void func_800960E8(s32, u8);
extern s32 D_800C0E20;
extern Slot80080554 D_800D5C1C[];
extern u8 D_800D49E0[];
extern s32 D_800DDE38;
extern State80080554 D_800DE640;
extern Cfg80080554 *D_800DE7A8;
extern Rec80080554 D_800DE9F4;
extern s32 D_800E9054;

#define DEL(o)                                              \
    {                                                       \
        Obj80080554 *_o = (o);                              \
        if (_o != NULL) {                                   \
            _o->vt[1].fn((u8 *)_o + _o->vt[1].delta, 3);    \
        }                                                   \
    }

void func_80080554(s32 *arg0, s32 *arg1) {
    State80080554 *s;
    Obj80080554 *o;
    s32 i;
    s32 cnt;
    s32 ok;
    u8 *pad;
    s32 n;

    s = &D_800DE640;
    if (s->unk118 != 0) {
        if (func_80022DF4() == 0) {
            return;
        }
        s->unk118 = 0;
        func_800960E8(D_800E9054, func_80096020(D_800E9054, D_800DDE38));
        DEL(s->objs[0]);
        DEL(s->objs[1]);
        DEL(s->objs[2]);
        s->objs[0] = NULL;
        s->objs[1] = NULL;
        s->objs[2] = NULL;
        D_800DE9F4.mask[D_800DE7A8->player] |= (n = D_800C0E20, 1 << n);
        func_80043B24();
        pad = D_800D49E0;
        func_80043FA8(pad);
        func_80043FA8(pad + 0x18C);
        func_80043F84(0, 0);
        func_80043F84(0, 1);
        func_80049E24(10);
        *arg0 = 0x1B;
        return;
    }
    func_8003A2DC();
    if (*arg1 == 0) {
        return;
    }
    if (func_80081F18(s) != 0) {
        o = s->objs[0];
        ok = 1;
        if (o != NULL) {
            ok = o->unk214 >= 40;
        }
        if (ok == 0) {
            return;
        }
        cnt = 0;
        for (i = 0; i < 10; i++) {
            if (D_800D5C1C[i].active != 0 && (D_800DE9F4.flags[D_800DE7A8->player][i] & 0xE0)) {
                cnt++;
            }
        }
        if ((cnt ^ 3) == 0) {
            s->unk118 = 1;
            return;
        }
        *arg0 = 7;
        func_800960E8(D_800E9054, func_80096020(D_800E9054, D_800DDE38));
    } else {
        *arg0 = 0xE;
    }
    DEL(s->objs[0]);
    DEL(s->objs[1]);
    DEL(s->objs[2]);
    s->objs[0] = NULL;
    s->objs[1] = NULL;
    s->objs[2] = NULL;
    D_800DE9F4.mask[D_800DE7A8->player] |= (n = D_800C0E20, 1 << n);
}
