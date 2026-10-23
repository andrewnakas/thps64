/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

extern s32 D_800D4880[3];
extern s32 D_800D4890[3];
extern s16 D_800D48A4[3];
extern s32 D_800D48AC[3];

void func_80042C70(void) {
    s32 x;
    s32 y;
    s32 z;

    x = D_800D4880[1] * D_800D4890[2] - D_800D4880[2] * D_800D4890[1];
    y = D_800D4880[2] * D_800D4890[0] - D_800D4880[0] * D_800D4890[2];
    z = D_800D4880[0] * D_800D4890[1] - D_800D4880[1] * D_800D4890[0];
    x >>= 12;
    y >>= 12;
    z >>= 12;
    D_800D48A4[0] = x;
    D_800D48A4[1] = y;
    D_800D48A4[2] = z;
    D_800D48AC[0] = x;
    D_800D48AC[1] = y;
    D_800D48AC[2] = z;
}
