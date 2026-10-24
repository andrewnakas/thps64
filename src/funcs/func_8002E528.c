#include "common.h"

typedef struct {
    u16 id;
    u8 pad[0x12];
} Ent_8002E528;

typedef struct {
    u8 pad0[0x10C];
    void *snd;
    u8 pad110[0x5C0 - 0x110];
    s32 sel;
    u8 pad5C4[0x5CC - 0x5C4];
    s32 mode;
    Ent_8002E528 ents[1];
} Obj_8002E528;

extern u8 D_800D0FC0[];
extern u8 D_800D0FD6;
void func_80027644(void *, s32, s32, f32);
s32 func_8003FEF4(s32);
void func_8002E448(Obj_8002E528 *, s32);
s32 func_800B4264(s32, s32);
void func_8004AE2C(void *, s32, s32);
void func_8004A204(void *, s32, s32, s32, s32);
void func_80039E60(s32, s32, s32);
void func_8002E818(Obj_8002E528 *);
s32 func_8002EAA0(Obj_8002E528 *);
void func_8002EA7C(Obj_8002E528 *);
void func_8002DA0C(Obj_8002E528 *);

s32 func_8002E528(Obj_8002E528 *arg0) {
    s32 ret;
    s32 c1;
    s32 c2;
    s32 mode;
    s32 t;
    s32 pressed;
    s32 v;
    s32 x;
    s32 m;

    ret = 0;
    c1 = D_800D0FC0[2];
    c2 = D_800D0FC0[3];
    func_80027644(arg0->snd, ret, 1, 60.0f);
    mode = arg0->mode;
    if (mode == 0) {
        t = func_8003FEF4(c1);
        if (t == 0) {
            t = func_8003FEF4(c2);
        }
        func_8002E448(arg0, t);
        pressed = 0;
        if (func_800B4264(c1, 0x8000) != 0 || func_800B4264(c2, 0x8000) != 0) {
            pressed = 1;
        }
        if (pressed) {
            x = arg0->sel;
            if (x == 0 || x == 0x14 || x == 0xF || x == 0x10 || x == 0x13) {
                func_8004AE2C(arg0->snd, arg0->ents[arg0->sel].id, 1);
            } else {
                func_8004A204(arg0->snd, arg0->ents[arg0->sel].id, 0, -1, -1);
            }
            func_80039E60(0x91, 10000, 0);
        }
        pressed = 0;
    } else if (mode == 1) {
        (*(s32 *)((u8 *)arg0 + 0x834))++;
        func_8002E818(arg0);
        if (func_8002EAA0(arg0) == 1) {
            func_8002EA7C(arg0);
            x = arg0->sel;
            if (x == 0 || x == 0x14 || x == 0xF || x == 0x10 || x == 0x13) {
                func_8004AE2C(arg0->snd, arg0->ents[arg0->sel].id, 1);
            } else {
                func_8004A204(arg0->snd, arg0->ents[arg0->sel].id, 0, -1, -1);
            }
        }
        pressed = 0;
    } else {
        pressed = 0;
    }
    if (func_800B4264(c1, 0x1000) != 0 || func_800B4264(c2, 0x1000) != 0) {
        pressed = 1;
    }
    if (pressed) {
        m = arg0->mode;
        if (m == 0) {
            arg0->mode = 1;
        } else if (m == 1) {
            arg0->mode = 0;
        }
        *(s32 *)((u8 *)arg0 + 0x834) = 0;
        func_80039E60(0x91, 10000, 0);
    } else {
        pressed = 0;
        if (func_800B4264(c1, 0x4000) != 0 || func_800B4264(c2, 0x4000) != 0) {
            pressed = 1;
        }
        if (pressed) {
            func_80039E60(0x93, 10000, 0);
            v = D_800D0FD6;
            if (v == 0x25) {
                ret = 0x25;
            } else if (v == 0x26) {
                ret = 0x26;
            } else {
                ret = 3;
            }
        }
    }
    func_8002DA0C(arg0);
    return ret;
}
