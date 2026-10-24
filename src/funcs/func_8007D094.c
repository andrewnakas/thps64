#include "common.h"

extern u8 D_8001E1E8[];
extern u8 D_8001E388[];
extern s32 D_800DE520;

typedef struct { f32 x, y, z; } Vec3;

typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    u8 padC[0xC];
    Vec3 unk18;
    u8 pad24[0x3C - 0x24];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[0x44 - 0x3F];
    void *unk44;
} Obj;

Obj *func_8007D094(Obj *arg0, Vec3 *arg1) {
    arg0->unk44 = D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520 += 1;
    arg0->unk44 = D_8001E1E8;
    arg0->unk18 = *arg1;
    arg0->unkA = 0x32;
    return arg0;
}
