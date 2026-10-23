/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct { s32 x, y, z; } V3i_Q2;
typedef struct { s16 x, y, z; } V3s_Q2;

extern V3i_Q2 D_800D4880;
extern V3i_Q2 D_800D4890;
extern V3s_Q2 D_800D48A4;
extern V3i_Q2 D_800D48AC;

void func_80042F58(void) {
    V3i_Q2 *a;
    V3i_Q2 *b;
    s32 x, y, z;

    a = &D_800D4880;
    b = &D_800D4890;
    x = a->y * b->z - a->z * b->y;
    y = a->z * b->x - a->x * b->z;
    z = a->x * b->y - a->y * b->x;
    D_800D48A4.x = x;
    D_800D48A4.y = y;
    D_800D48A4.z = z;
    D_800D48AC.x = x;
    D_800D48AC.y = y;
    D_800D48AC.z = z;
}
