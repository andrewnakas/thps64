#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[0x5];
    void *unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
} Obj8007C68C;

extern s32 func_8005EAB4(s32, s32, s32);
extern u8 D_8001E1C8[];
extern u8 D_8001E388[];
extern s32 D_800DE520;

Obj8007C68C *func_8007C68C(Obj8007C68C *arg0, s32 arg1, s32 arg2) {
    arg0->unk44 = D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520++;
    arg0->unk44 = D_8001E1C8;
    arg0->unk4C = arg1;
    arg0->unk50 = func_8005EAB4(arg1 * 0x24, 0, 1);
    arg0->unk48 = arg2;
    return arg0;
}
