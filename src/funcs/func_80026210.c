/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800349D4(void);
void func_800A7B50(void *, f32, f32, void *, s32, s32, s32);
f32 func_800B4200(s32, s32);
s32 func_800B4240(s32, s32);
s32 func_800B4264(s32, s32);
void func_800B8298(void *, s32, s32, s32, s32, s32, f32, s32, f32, s32, s32, s32, s32);
void *func_800BACE0(void *, s32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern u8 D_800EECF0[];

typedef struct {
    u8 pad0[0x30];
    u8 *spr;
    u8 pad34[0x8C - 0x34];
    u8 unk8C[0x2CC - 0x8C];
    s32 idx;
} Obj_80026210;

s32 func_80026210(Obj_80026210 *arg0) {
    s32 dir;
    s32 t;
    f32 w;
    f32 x;
    f32 y;
    f32 c;

    t = func_800B4240(0, 0x800);
    t |= func_800B4264(0, 0x100);
    dir = t != 0;
    t = func_800B4240(0, 0x400);
    t |= func_800B4264(0, 0x200);
    if (t != 0) {
        dir = -1;
    }
    if (dir != 0) {
        do {
            arg0->idx = (arg0->idx + dir + 0x5D0) % 1488;
        } while ((arg0->spr = func_800BACE0(D_800EECF0, arg0->idx)) == NULL);
    }
    func_800349D4();
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    w = *(u16 *)(arg0->spr + 0x38);
    if (func_800B4200(0, 0x78) >= 0.0f) {
        x = 2.0f * (func_800B4200(0, 0x78) + 1.0f) * w;
    } else {
        x = 2.0f * (1.0f - func_800B4200(0, 0x78)) * w;
    }
    w = *(u16 *)(arg0->spr + 0x3A);
    if (func_800B4200(0, 0x79) >= 0.0f) {
        y = 2.0f * (func_800B4200(0, 0x79) + 1.0f) * w;
    } else {
        y = 2.0f * (1.0f - func_800B4200(0, 0x79)) * w;
    }
    c = 50.0f;
    func_800B8298(arg0->spr, 0x32, x + c, 0x32, y + c, 0, 1.0f, 0, 1.0f, 0xFF, 0xFF, 0xFF, 0xFF);
    func_800A7B50(arg0->unk8C, c, 35.0f, arg0->spr + 0x18, 1, 0, 0);
    func_800BE5A4();
    return 0;
}
