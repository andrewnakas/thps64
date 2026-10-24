#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec8007D4CC;

typedef struct {
    u8 pad0[0x18];
    Vec8007D4CC unk18;
    u8 pad24[0x20];
    void *unk44;
    u8 pad48[0x4];
    s32 unk4C;
    u8 pad50[0x9];
    u8 unk59;
    u8 pad5A[0x4];
    s16 unk5E;
    u8 pad60[0x10];
    s32 unk70;
    s32 unk74;
} Obj8007D4CC;

extern void func_80079E18(Obj8007D4CC *);
extern u8 D_8001E248[];

Obj8007D4CC *func_8007D4CC(Obj8007D4CC *arg0, Vec8007D4CC *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_80079E18(arg0);
    arg0->unk44 = D_8001E248;
    arg0->unk18 = *arg1;
    arg0->unk5E = arg3;
    if (arg4 != 0) {
        arg0->unk4C |= 0x02000000;
    }
    arg0->unk70 = arg5;
    if (arg6 == -1) {
        arg0->unk74 = arg0->unk59 - 1;
    } else {
        arg0->unk74 = arg6;
    }
    return arg0;
}
