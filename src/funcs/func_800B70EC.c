#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_800B70EC;

typedef struct {
    Vec3i_800B70EC unk0;
    Vec3i_800B70EC unkC;
    s32 unk18;
} Unk_800B70EC;

void func_800B70EC(Unk_800B70EC *arg0) {
    Vec3i_800B70EC v;

    arg0->unk18 = 1;
    v.z = 0;
    v.y = 0;
    v.x = 0;
    arg0->unkC = v;
    arg0->unk0 = arg0->unkC;
}
