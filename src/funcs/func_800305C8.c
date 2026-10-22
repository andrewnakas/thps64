#include "common.h"

s32 func_80039E60(s32, s32, s32);
s32 func_800B4264(s32, s32);
extern u8 D_800D0FC0[];
extern s32 D_800DE7F0;
extern s32 D_800DE9A8;
extern u8 D_800DE9F4[];
extern s32 D_800E9290;

void func_800305C8(u8 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    if ((*(s32 *)(arg0 + 0x7A8) != 0) && (*(s32 *)(arg0 + 0x7AC) != 0)) {
        D_800D0FC0[0x14] = D_800DE9F4[0x864] = arg0[0x78F];
        D_800D0FC0[0x15] = D_800DE9F4[0x865] = arg0[0x793];
        D_800E9290 = D_800D0FC0[0x14];
        D_800DE7F0 = D_800D0FC0[0x15];
        *arg1 = 0xC;
        D_800DE9A8 = 2;
        return;
    }
    if (func_800B4264(arg2, 0x4000) != 0) {
        if (*(s32 *)(arg0 + 0x7A8) != 0) {
            *(s32 *)(arg0 + 0x7A8) = 0;
        } else {
            *arg1 = 0xA;
        }
        func_80039E60(0x93, 0x2710, 0);
    } else if (func_800B4264(arg3, 0x4000) != 0) {
        if (*(s32 *)(arg0 + 0x7AC) != 0) {
            *(s32 *)(arg0 + 0x7AC) = 0;
        } else {
            *arg1 = 0xA;
        }
        func_80039E60(0x93, 0x2710, 0);
    }
}
