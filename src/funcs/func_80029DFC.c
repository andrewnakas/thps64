#include "common.h"

typedef struct {
    s16 delta;
    s16 idx;
    void (*fn)(void *, s32);
} VEnt80029DFC;

typedef struct {
    u8 pad0[8];
    VEnt80029DFC e;
} VTbl80029DFC;

typedef struct {
    u8 pad0[0x48];
    VTbl80029DFC *vt;
} VObj80029DFC;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[2];
    u8 unk16;
} Glob80029DFC;

extern u8 D_80019060[];
extern Glob80029DFC D_800D0FC0;
extern u8 D_800EA9C0[];
void func_800A9460(void *, s32, s32, s32);
void func_800A735C(void *, s32);
void func_800A5FD0(void *, s32);
void func_800B19C0(void *, s32);
void func_800394A8(void *, s32);

void func_80029DFC(u8 *arg0, s32 arg1) {
    VObj80029DFC *o;

    *(void **)(arg0 + 0x2C) = D_80019060;
    o = *(VObj80029DFC **)(arg0 + 0x44);
    if (o != NULL) {
        o->vt->e.fn((u8 *)o + o->vt->e.delta, 3);
    }
    D_800D0FC0.unk10 = 0;
    if (D_800D0FC0.unk16 == 0) {
        func_800A9460(D_800EA9C0, 3, 0, -2);
    } else {
        func_800A9460(D_800EA9C0, 4, 0, -2);
    }
    func_800A735C(arg0 + 0x68, 2);
    func_800A5FD0(arg0 + 0x48, 2);
    func_800B19C0(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
