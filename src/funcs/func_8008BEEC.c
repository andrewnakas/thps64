/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8006F274(s32);
void func_8006F23C(s32);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
extern char D_8001FD50[];
extern s32 D_800E8FC0;
extern s32 D_800DE9A8;

void func_8008BEEC(void) {
    if (--D_800E8FC0 == 0) {
        D_800E8FC0 = 0x30;
    }
    if (D_800E8FC0 >= 0xD) {
        if (D_800DE9A8 == 2) {
            func_8006F274(0);
            func_8006F23C(0xFF);
            func_8006F1A8(0x96, 0x64, 0x19, 0);
            func_8006DF40(0x80, 0x23, D_8001FD50, 1, 0, 0x100, 0);
            func_8006DF40(0x180, 0x23, D_8001FD50, 1, 0, 0x100, 0);
        } else {
            func_8006F274(0);
            func_8006F23C(0xFF);
            func_8006F1A8(0x96, 0x64, 0x19, 0);
            func_8006DF40(0x100, 0x23, D_8001FD50, 1, 0, 0x100, 0);
        }
    }
}
