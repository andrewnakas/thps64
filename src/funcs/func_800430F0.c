/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

extern s32 D_800D4870[3];
extern s16 D_800D48A4[3];
extern s16 *D_800D4918[3];

void func_800430F0(void) {
    s16 **r = D_800D4918;

    D_800D48A4[0] = (r[0][0] * D_800D4870[0] + r[0][1] * D_800D4870[1] + r[0][2] * D_800D4870[2]) >> 12;
    D_800D48A4[1] = (r[1][0] * D_800D4870[0] + r[1][1] * D_800D4870[1] + r[1][2] * D_800D4870[2]) >> 12;
    D_800D48A4[2] = (r[2][0] * D_800D4870[0] + r[2][1] * D_800D4870[1] + r[2][2] * D_800D4870[2]) >> 12;
}
