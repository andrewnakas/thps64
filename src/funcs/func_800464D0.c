#include "common.h"
extern s32 D_800DE7A0;
extern s32 D_800DE7A8;
void func_8006F1A8(s32, s32, s32, s32);
void func_800464D0(s32 arg0) {
    if (D_800DE7A0 == 8) {
        if (arg0 == D_800DE7A8) {
            func_8006F1A8(0x50, 0x50, 0x80, 0);
        } else {
            func_8006F1A8(0x80, 0x50, 0x50, 0);
        }
    }
}
