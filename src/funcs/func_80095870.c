#include "common.h"

s32 func_8006DF40(s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_8006F1A8(s32, s32, s32, s32); /* extern */
s32 func_8006F23C(s32);                     /* extern */
s32 func_8006F274(s32);                     /* extern */
s32 func_80087194(s32, s32);                /* extern */
extern s32 D_800D1E88;
extern u8 D_800DDC80[];
extern s32 D_800E9088;

void func_80095870(s32 arg0) {
    u8 *p;

    func_8006F274(1);
    func_8006F23C(0xC0);
    func_8006F1A8(0x96, 0x64, 0x19, 0);
    func_8006DF40(0xE3, D_800E9088 + 0xD6, arg0, 0, 0, 0x100, 0);
    p = D_800DDC80;
    if (arg0 == *(s32 *)(p + 0x184)) {
        func_80087194(D_800D1E88, 0);
    }
    if (arg0 == *(s32 *)(p + 0x19C)) {
        func_80087194(D_800D1E88, 2);
    }
    if (arg0 == *(s32 *)(p + 0x1A0)) {
        func_80087194(D_800D1E88, 1);
    }
}
