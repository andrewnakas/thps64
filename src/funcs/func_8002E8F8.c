#include "common.h"

s32 func_8003FEF4(s32);
s32 func_8003FF2C(s32);
s32 func_800B4264(s32, s32);
extern u8 D_800D0FC0[];

s16 func_8002E8F8(void) {
    s16 r;
    s32 x;
    s32 y;
    u8 *g;

    r = -45;
    g = D_800D0FC0;
    if (func_800B4264(g[2], 8)) {
        r = 8;
    } else if (func_800B4264(g[2], 4)) {
        r = 4;
    } else if (func_800B4264(g[2], 2)) {
        r = 2;
    } else if (func_800B4264(g[2], 1)) {
        r = 1;
    } else {
        x = func_8003FEF4(g[2]);
        if (x != 0) {
            y = func_8003FF2C(g[2]);
            if (y != 0) {
                if (y == 1) {
                    if (x == -1) {
                        r = 0x900;
                        goto done;
                    } else if (x == y) {
                        r = 0x500;
                        goto done;
                    }
                }
                if (y == -1) {
                    if (x == 1) {
                        r = 0x600;
                    } else if (x == y) {
                        r = 0xA00;
                    }
                }
            } else {
                if (x == 1) {
                    r = 0x400;
                } else if (x == -1) {
                    r = 0x800;
                }
            }
        } else {
            y = func_8003FF2C(g[2]);
            if (y != 0) {
                if (y == 1) {
                    r = 0x100;
                } else if (y == -1) {
                    r = 0x200;
                }
            }
        }
    }
done:
    return r;
}
