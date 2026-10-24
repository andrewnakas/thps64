/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 delta;
    s16 idx;
    void (*fn)(void *);
} VEnt800A100C;

typedef struct {
    u8 pad0[0x3EC];
    u8 unk3EC[0x428 - 0x3EC];
    s32 unk428;
    u8 pad42C[0x434 - 0x42C];
    s32 unk434;
    u8 pad438[0x444 - 0x438];
    u8 unk444[0x474 - 0x444];
    s32 unk474;
    u8 pad478[0x4F8 - 0x478];
    VEnt800A100C *vt;
} Obj800A100C;

extern s32 func_8000B470(void *, void *, s32);
extern s32 func_8000C140(void *);
extern void func_800A0870(Obj800A100C *, s32, s32);
extern void func_800A0C6C(Obj800A100C *, s32);
extern void func_800A3750(Obj800A100C *, void *, s32, s32, s32, void *, s32);
extern u8 D_80020A40[];
extern u8 D_80020D50[];
extern u8 D_80020D64[];

void func_800A100C(Obj800A100C *arg0) {
    u8 buf[0x68];
    s32 r;
    VEnt800A100C *e;

    r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
    switch (r) {
    case 2:
        e = &arg0->vt[6];
        e->fn((u8 *)arg0 + e->delta);
        func_800A0C6C(arg0, arg0->unk428);
        func_800A3750(arg0, D_80020A40, arg0->unk434, 0, 0, arg0->unk444, 0);
        return;
    case 0:
    case 10:
        if (func_8000C140(buf) == 0 && func_8000B470(arg0->unk3EC, buf, arg0->unk434) == 0) {
            e = &arg0->vt[5];
            e->fn((u8 *)arg0 + e->delta);
            func_800A0C6C(arg0, arg0->unk428);
            func_800A3750(arg0, D_80020D50, arg0->unk434, 0, 0, arg0->unk444, 0);
            arg0->unk474 = 1;
            return;
        }
        e = &arg0->vt[6];
        e->fn((u8 *)arg0 + e->delta);
        func_800A0C6C(arg0, arg0->unk428);
        func_800A3750(arg0, D_80020D64, arg0->unk434, 0, 0, arg0->unk444, 0);
        return;
    default:
        func_800A0870(arg0, r, 0);
        return;
    }
}
