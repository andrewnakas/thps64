/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    u8 pad0[0x60];
    Vec3i unk60;
    Vec3i unk6C;
} Trail;

typedef struct {
    u8 pad0[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    Vec3i *unk58;
    Trail **unk5C;
} History;

void func_8007C9EC(History *arg0, Vec3i *arg1) {
    s32 idx;
    s32 i;

    arg0->unk54++;
    if (arg0->unk54 == arg0->unk50) {
        arg0->unk54 = 0;
    }
    arg0->unk58[arg0->unk54] = *arg1;
    idx = arg0->unk54;
    for (i = arg0->unk48 - 1; i >= 0; i--) {
        arg0->unk5C[i]->unk6C = arg0->unk58[idx];
        idx -= arg0->unk4C;
        if (idx < 0) {
            idx += arg0->unk50;
        }
        arg0->unk5C[i]->unk60 = arg0->unk58[idx];
    }
}
