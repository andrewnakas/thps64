/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0xF];
    u8 b11;
    u8 pad12[0xE];
    u8 b20;
    u8 b21;
    u8 pad22[0xF];
    u8 b31;
    u8 pad32[0xF];
    u8 b41;
    u8 pad42[0xF];
    u8 b51;
    u8 pad52[0xF];
    u8 b61;
    u8 pad62[0xF];
    u8 b71;
    u8 pad72[0xF];
    u8 b81;
    u8 pad82[0xF];
    u8 b91;
    u8 pad92[0xF];
    u8 bA1;
    u8 padA2[0xF];
    u8 bB1;
    u8 padB2[0x3F];
    u8 bF1;
    u8 padF2[0x18C - 0xF2];
} Pad6CB4C;

extern Pad6CB4C D_800D49E0[2];
extern s32 D_800DC618[];
extern s32 D_800DC6D4;
extern s32 D_800DC828;
extern s32 D_800DE820;
extern s32 D_800DE874;
extern s32 D_800DE950;
extern s32 D_800DE9A8;
extern s32 D_800E8FA8;

void func_8006CB4C(void) {
    s32 i;
    s32 v;

    if (D_800DC618[0] != 2 || D_800DE950 == 0) {
        if (D_800DE950 == 0) {
            for (i = 0; i < 2; i++) {
                if (D_800D49E0[i].b1 != 0 || D_800D49E0[i].b11 != 0 || D_800D49E0[i].b41 != 0 || D_800D49E0[i].b51 != 0
                    || D_800D49E0[i].b61 != 0 || D_800D49E0[i].b71 != 0 || D_800D49E0[i].b81 != 0
                    || D_800D49E0[i].b91 != 0 || D_800D49E0[i].bA1 != 0 || D_800D49E0[i].bB1 != 0
                    || D_800D49E0[i].b21 != 0 || D_800D49E0[i].bF1 != 0) {
                    D_800D49E0[i].b31 = 1;
                }
            }
        }
        return;
    }
    if (D_800E8FA8 == 0x14 || D_800E8FA8 == 0x16 || D_800E8FA8 == 0x15) {
        return;
    }
    if (D_800D49E0[0].b11 != 0 || (D_800DE9A8 == D_800DC618[0] && D_800D49E0[1].b11 != 0)) {
        D_800D49E0[0].b11 = 0;
        D_800D49E0[1].b11 = 0;
        v = D_800DC618[0x2F] ^ 1;
        D_800DC618[0x2F] = v;
        D_800DE874 = D_800DE820 = v;
    }
    if (D_800DC6D4 == 0) {
        return;
    }
    D_800DE820 = 1;
    if (D_800D49E0[0].b20 != 0 || (D_800DE9A8 == 2 && D_800D49E0[1].b20 != 0)) {
        if (D_800DC828 != 0) {
            D_800DC828--;
        } else {
            D_800DC828 = 6;
            D_800DE820 = 0;
        }
        return;
    }
    if (D_800D49E0[0].b0 != 0 || (D_800DE9A8 == 2 && D_800D49E0[1].b0 != 0)) {
        if (D_800DC828 == 0) {
            D_800DC828 = 1;
            D_800DE820 = 0;
        } else {
            D_800DC828--;
        }
        return;
    }
    D_800DC828 = 0;
    return;
}
