#include "common.h"

typedef struct { f32 x, y, z; } Vec3;

typedef struct {
    u8 pad0[0x18];
    Vec3 unk18;
    Vec3 unk24;
    u8 pad30[0x14];
    void *unk44;
    s16 unk48;
    s16 unk4A;
    s32 unk4C;
    u8 pad50[0xE];
    s16 unk5E;
} Obj;

void func_80079E18(Obj *, Vec3 *, Vec3 *);
extern u8 D_8001E230[];

Obj *func_8007D3D0(Obj *arg0, Vec3 *arg1, Vec3 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_80079E18(arg0, arg1, arg2);
    arg0->unk44 = D_8001E230;
    arg0->unk18 = *arg1;
    arg0->unk24 = *arg2;
    arg0->unk4C |= 0x02000000;
    arg0->unk5E = arg4;
    arg0->unk4A = arg5;
    arg0->unk48 = arg6;
    return arg0;
}
