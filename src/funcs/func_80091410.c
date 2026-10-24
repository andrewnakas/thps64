#include "common.h"

s32 func_800B4240(u8, s32);
s32 func_80091320(s32);
extern s32 D_800DE868;
extern s32 D_800DE820;
extern u8 D_800D49E0[];
extern s32 D_800E9248;
extern s32 D_800E924C;
extern u8 D_800D0FC0[];

void func_80091410(s32 *a, s32 *b, s32 *c, s32 *d) {
    u8 *k;
    s32 pressed;
    s32 x;
    s32 r;

    *a = 0;
    if (D_800DE868 == 0 || D_800DE820 == 0) {
        x = 0;
        if (D_800D49E0[0xE1] != 0 || D_800D49E0[0x26D] != 0) {
            x = 1;
        }
        *d = x;
        D_800E9248 = D_800D49E0[0xE1];
        if (D_800E9248 == 0) {
            D_800E924C = D_800D49E0[0x26D];
        } else {
            D_800E924C = 0;
        }
        D_800D49E0[0xE1] = 0;
        D_800D49E0[0x26D] = 0;
    } else {
        *d = 0;
    }
    pressed = 0;
    k = D_800D0FC0;
    if (func_800B4240(k[3], 0x2000) != 0 || func_800B4240(k[2], 0x2000) != 0) {
        pressed = 1;
    }
    if (pressed) {
        *d = 0;
        return;
    }
    r = func_80091320(0x8000);
    *a = *d != 0 || r != 0;
    k = D_800D49E0;
    k[0x31] = 0;
    k[0x1BD] = 0;
    *b = func_80091320(0x4000);
    k[0x1] = 0;
    k[0x18D] = 0;
    *c = *b | *a;
    if (k[0x11] != 0) {
        k[0x11] = 0;
        *c = 1;
    }
    if (k[0x21] != 0) {
        k[0x21] = 0;
        *c = 1;
    }
    if (k[0xF1] != 0) {
        k[0xF1] = 0;
        *c = 1;
    }
    if (k[0x41] != 0) {
        k[0x41] = 0;
        *c = 1;
    }
    if (k[0x51] != 0) {
        k[0x51] = 0;
        *c = 1;
    }
    if (k[0x61] != 0) {
        k[0x61] = 0;
        *c = 1;
    }
    if (k[0x71] != 0) {
        k[0x71] = 0;
        *c = 1;
    }
    if (k[0x19D] != 0) {
        k[0x19D] = 0;
        *c = 1;
    }
    if (k[0x1AD] != 0) {
        k[0x1AD] = 0;
        *c = 1;
    }
    if (k[0x27D] != 0) {
        k[0x27D] = 0;
        *c = 1;
    }
    if (k[0x1CD] != 0) {
        k[0x1CD] = 0;
        *c = 1;
    }
    if (k[0x1DD] != 0) {
        k[0x1DD] = 0;
        *c = 1;
    }
    if (k[0x1ED] != 0) {
        k[0x1ED] = 0;
        *c = 1;
    }
    if (k[0x1FD] != 0) {
        k[0x1FD] = 0;
        *c = 1;
    }
    if (*a != 0) {
        *b = 0;
    }
}
