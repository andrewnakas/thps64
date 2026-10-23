/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

extern s32 D_800D4870[3];
extern s16 D_800D48A4[3];
extern s32 D_800D48AC[3];
extern s16 D_800D4958[9];

void func_80042D98(void) {
    s32 x;
    s32 y;
    s32 z;
    s32 *o;
    s16 *os;

    x = (D_800D4958[0] * D_800D4870[0] + D_800D4958[1] * D_800D4870[1] + D_800D4958[2] * D_800D4870[2]) >> 12;
    y = (D_800D4958[3] * D_800D4870[0] + D_800D4958[4] * D_800D4870[1] + D_800D4958[5] * D_800D4870[2]) >> 12;
    z = (D_800D4958[6] * D_800D4870[0] + D_800D4958[7] * D_800D4870[1] + D_800D4958[8] * D_800D4870[2]) >> 12;
    os = D_800D48A4;
    o = D_800D48AC;
    D_800D48AC[0] = x;
    D_800D48A4[0] = x;
    o[1] = y;
    os[1] = y;
    o[2] = z;
    os[2] = z;
}
