/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

void func_80049C20(s32 *, s32 *); /* extern */
s32 func_80049D60(s32);                               /* extern */
extern u8 D_8001E2F0;
extern u8 D_8001E388;
extern s32 D_800DE520;

void *func_80079934(void *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    s32 sp10[4];
    s32 sp20[4];
    s32 sp30[4];
    s32 sp40[4];
    s32 ax, ay, az;
    s32 bx, by, bz;
    s32 cx, cy, cz;
    s32 scale;

    *(void **) ((u8 *) arg0 + 0x44) = &D_8001E388;
    *(u8 *) ((u8 *) arg0 + 0x3C) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3D) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3E) = 1;
    D_800DE520 += 1;
    *(void **) ((u8 *) arg0 + 0x44) = &D_8001E2F0;
    *(u8 *) ((u8 *) arg0 + 0x43) = 6;
    *(u16 *) ((u8 *) arg0 + 0x48) = arg1[0];
    *(u16 *) ((u8 *) arg0 + 0x4A) = arg1[1];
    *(u16 *) ((u8 *) arg0 + 0x4C) = arg1[2];
    *(u16 *) ((u8 *) arg0 + 0x50) = arg2[0];
    *(u16 *) ((u8 *) arg0 + 0x52) = arg2[1];
    *(u16 *) ((u8 *) arg0 + 0x54) = arg2[2];
    *(u16 *) ((u8 *) arg0 + 0x58) = arg3[0];
    *(u16 *) ((u8 *) arg0 + 0x5A) = arg3[1];
    *(u16 *) ((u8 *) arg0 + 0x5C) = arg3[2];
    ax = arg3[0] - arg1[0];
    ay = arg3[1] - arg1[1];
    az = arg3[2] - arg1[2];
    sp10[0] = ax;
    sp10[1] = ay;
    sp10[2] = az;
    bx = arg2[0] - arg1[0];
    by = arg2[1] - arg1[1];
    bz = arg2[2] - arg1[2];
    sp20[0] = bx;
    sp20[1] = by;
    sp20[2] = bz;
    cx = ay * bz - az * by;
    cy = az * bx - ax * bz;
    cz = ax * by - ay * bx;
    sp30[0] = cx;
    sp30[1] = cy;
    sp30[2] = cz;
    func_80049C20(sp40, sp30);
    scale = func_80049D60(0x60) + 0x80;
    *(s16 *) ((u8 *) arg0 + 0x60) = (sp40[0] * scale) >> 0xC;
    *(s16 *) ((u8 *) arg0 + 0x62) = (sp40[1] * scale) >> 0xC;
    *(s16 *) ((u8 *) arg0 + 0x64) = (sp40[2] * scale) >> 0xC;
    return arg0;
}
