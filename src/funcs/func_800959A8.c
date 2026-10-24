#include "common.h"

extern void func_8006DF40(s32, s32, s32, s32, s32, s32, s32);
extern void func_8006F1A8(s32, s32, s32, s32);
extern void func_8006F23C(s32);
extern void func_8006F274(s32);
extern s32 D_800DDE18;
extern s32 D_800E9088;

void func_800959A8(void) {
    func_8006F274(1);
    func_8006F23C(0xC0);
    func_8006F1A8(0x96, 0x64, 0x19, 0);
    func_8006DF40(0x5C, D_800E9088 + 0xD6, D_800DDE18, 0, 0, 0x100, 0);
    func_8006F274(0);
}
