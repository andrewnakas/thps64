/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x4];
    struct {
        s32 unk0;
        s32 unk4;
    } unk18[1];
} Res800ADEEC;

typedef struct {
    u8 pad0[0x4];
    s32 unk4;
    u8 pad8[0x3C];
    s32 unk44;
    s32 unk48;
    u8 pad4C[0x2C];
    Res800ADEEC *unk78;
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x1A];
    s16 unk9E;
    u8 padA0[0x6];
    s16 unkA6;
    u8 padA8[0x8];
    s16 unkB0;
} Obj800ADEEC;

extern void func_800ADBC4(Obj800ADEEC *);
extern s32 D_800FC30C;

s32 func_800ADEEC(Obj800ADEEC *arg0, Res800ADEEC *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_800ADBC4(arg0);
    arg0->unkA6 = arg2;
    arg0->unk78 = arg1;
    arg0->unk9E = arg3;
    arg0->unkB0 = arg4;
    arg0->unk44 = D_800FC30C++;
    arg0->unk48 = arg5;
    if (arg1->unk10 != 0) {
        arg0->unk7C = arg1->unk10;
    }
    arg0->unk4 = arg0->unk80 = arg1->unk18[arg2].unk0;
    return arg0->unk44;
}
