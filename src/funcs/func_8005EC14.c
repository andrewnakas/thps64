#include "common.h"

extern s32 D_800C0E20;

s32 func_8005EC14(s32 *arg0) {
    s32 x;
    s32 y;
    s32 z;

    x = arg0[0] >> 12;
    y = arg0[1] >> 12;
    z = arg0[2] >> 12;
    if (D_800C0E20 == 0 && x == 0x1789 && y == -0x1BF && z == 0x3828) {
        arg0[0] = 0x01595000;
        arg0[1] = 0xFFE41000;
        arg0[2] = 0x037DC000;
        return 1;
    }
    if (D_800C0E20 == 4 && x == -0xEE9 && y == 0x85 && z == -0x195D) {
        arg0[0] = 0xFF117000;
        arg0[1] = 0x85000;
        arg0[2] = 0xFE66A000;
        return 1;
    }
    if (D_800C0E20 == 8 && x == 0xF9E && y == -0x257 && z == 0x10FE) {
        arg0[0] = 0xFAA000;
        arg0[1] = 0xFFDA9000;
        arg0[2] = 0x10FE000;
        return 1;
    }
    if (D_800C0E20 == 8 && x == -0x31F && y == -0x1E && z == -0x670) {
        arg0[0] = 0xFFCF4000;
        arg0[1] = 0xFFFE2000;
        arg0[2] = 0xFF990000;
        return 1;
    }
    if (D_800C0E20 == 8 && x == 0x63F && y == -0x368) {
        arg0[0] = 0x654000;
        arg0[1] = 0xFFC98000;
        arg0[2] = 0x13C9000;
        return 1;
    }
    return 0;
}
