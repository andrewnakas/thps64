#include "common.h"

extern s32 D_800DE93C;
extern s32 D_800DDDE8;
extern s32 D_800DDDEC;
extern s32 D_800DDDF0;
extern s32 D_800DDDF4;
void func_8006EC5C(s32);
void func_8006EC54(s32, s32);
void func_8006DEB0(s32, s32);
void func_8006F274(s32);
void func_8006F178(s32, s32, s32, s32, s32, s32);
s32 func_8006EC3C(s32);

void func_80044DAC(s32 p, s32 x, s32 y) {
    s16 dx;
    s16 dy;
    s16 *px;
    s16 *py;
    s32 img;
    s32 obj;
    u32 idx;
    s32 t;
    u32 u;

    if (*(s32 *)(p + 0xBC8) != 0) {
        t = D_800DE93C;
        u = *(u16 *)(p + 0xA24);
        idx = t * 2 + u;
        px = &dx;
        py = &dy;
        switch (idx) {
        case 0:
        case 1:
            *px = 0;
            *py = 0;
            break;
        case 4:
            *px = 0;
            *py = 0x3C;
            break;
        case 6:
            *px = 0x80;
            *py = 0x3C;
            break;
        case 2:
            *px = 0x80;
            *py = 0;
            break;
        case 5:
            *px = 0;
            *py = -0x3C;
            break;
        case 7:
            *px = -0x80;
            *py = -0x3C;
            break;
        case 3:
            *px = -0x80;
            *py = 0;
            break;
        }
        switch (*(s32 *)(p + 0xBC8)) {
        case 1:
            img = D_800DDDE8;
            break;
        case 2:
            img = D_800DDDEC;
            break;
        case 3:
            img = D_800DDDF0;
            break;
        default:
            img = D_800DDDF4;
            break;
        }
        obj = p + 0xBCC;
        func_8006EC5C(obj);
        func_8006EC54(obj, 0x100);
        func_8006DEB0(obj, 1);
        func_8006F274(0);
        func_8006F178((u16)x + dx, (u16)y + dy, img, 0, 0, 0x100);
        if (func_8006EC3C(obj) == 0) {
            *(s32 *)(p + 0xBC8) = 0;
        }
        func_8006DEB0(obj, 0);
    }
}
