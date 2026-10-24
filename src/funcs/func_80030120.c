#include "common.h"

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)();
} VEnt_80030120;

typedef struct {
    u8 pad0[0x48];
    VEnt_80030120 *vt;
    u8 pad4C[0x2260 - 0x4C];
    f32 unk2260;
    f32 unk2264;
    f32 unk2268;
    s32 unk226C;
} Obj_80030120;

extern u8 D_800F0DD0[];
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F329C;
extern s32 D_800D36B0;
void func_800BC0F4(void *);
void *func_8004B514(s32);
Obj_80030120 *func_80028238(void *, s32, s32, s32);
void func_80027ED8(Obj_80030120 *, s32, s32, s32, s32);
void func_8004AE2C(Obj_80030120 *, s32, s32);

void func_80030120(u8 *arg0, Obj_80030120 *p1, Obj_80030120 *p2, s32 arg3, s32 arg4) {
    f32 a1, b1, c1;
    s32 d1;
    f32 a2, b2, c2;
    s32 d2;
    Obj_80030120 *n1;
    Obj_80030120 *n2;

    if (p1 != NULL) {
        a1 = p1->unk2268;
        b1 = p1->unk2260;
        c1 = p1->unk2264;
        d1 = p1->unk226C;
        func_800BC0F4(D_800F0DD0);
        p1->vt[1].fn((u8 *)p1 + p1->vt[1].delta, 3);
    }
    if (p2 != NULL) {
        a2 = p2->unk2268;
        b2 = p2->unk2260;
        c2 = p2->unk2264;
        d2 = p2->unk226C;
        func_800BC0F4(D_800F0DD0);
        p2->vt[1].fn((u8 *)p2 + p2->vt[1].delta, 3);
    }
    n1 = func_80028238(func_8004B514(0x2388), arg3, 1, 0);
    n2 = func_80028238(func_8004B514(0x2388), arg4, 1, 1);
    func_80027ED8(n1, (f32)((s32)(D_800F3294 * 0.27f) + D_800D36B0) * D_800F329C,
                  (f32)((s32)(D_800F3294 * 0.45f) + D_800D36B0) * D_800F329C, D_800F3298 * 0.51f,
                  D_800F3298 * 0.84f);
    func_8004AE2C(n1, 0, 1);
    func_80027ED8(n2, (f32)((s32)(D_800F3294 * 0.69f) + D_800D36B0) * D_800F329C,
                  (f32)((s32)(D_800F3294 * 0.87f) + D_800D36B0) * D_800F329C, D_800F3298 * 0.51f,
                  D_800F3298 * 0.84f);
    func_8004AE2C(n2, 0, 1);
    if (p1 != NULL) {
        n1->unk2268 = a1;
        n1->unk2260 = b1;
        n1->unk2264 = c1;
        n1->unk226C = d1;
    }
    if (p2 != NULL) {
        n2->unk2268 = a2;
        n2->unk2260 = b2;
        n2->unk2264 = c2;
        n2->unk226C = d2;
    }
    *(Obj_80030120 **)(arg0 + 0x7B0) = n1;
    *(Obj_80030120 **)(arg0 + 0x7B4) = n2;
}
