#include "common.h"

void *func_80039500(void *);
void func_800B198C(void *);
void func_800B1A80(void *, s32);
extern u8 D_80019598[];
extern s32 D_800D3690;
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;
extern s32 D_800F0CD8;

u8 *func_8002C8C8(u8 *arg0) {
    f32 f;

    func_80039500(arg0);
    *(void **) (arg0 + 0x2C) = D_80019598;
    func_800B198C(arg0 + 0x30);
    *(s32 *) (arg0 + 0x44) = 1;
    func_800B1A80(arg0 + 0x30, 0x98);
    f = D_800D3690;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    D_800F0CD8 = 0;
    return arg0;
}
