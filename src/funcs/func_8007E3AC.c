#include "common.h"

extern u8 D_8001E338[];
extern u8 D_8001E388[];
extern s32 D_800DE520;

typedef struct {
    u8 pad0[0x3C];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[0x44 - 0x3F];
    void *unk44;
    u8 pad48[4];
    s32 unk4C;
    u8 pad50[0xC];
    s16 unk5C;
    s16 unk5E;
} Obj;

Obj *func_8007E3AC(Obj *arg0) {
    arg0->unk44 = D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520 += 1;
    arg0->unk44 = D_8001E338;
    arg0->unk5C = 0x80;
    arg0->unk5E = 0x190;
    arg0->unk4C = 0x2C808080;
    return arg0;
}
