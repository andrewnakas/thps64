/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} SynCfg;

typedef struct {
    u8 pad0[0x48];
    s32 unk48;
} Player;

typedef struct {
    s32 unk0;
    s32 unk4;
} Pool;

s32 func_8009E6B4(void *, s32, s32);
s32 func_8009B7D8(void *, void *, s32, s32);
s32 func_800AC44C(s32);
s32 func_800AE424(Pool *, s32);
extern u8 D_800EA110[];
extern u8 D_800F5684[];
extern Pool D_800F5678;
extern f32 D_800ECB40;

s32 func_800AC770(SynCfg *arg0, Player *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 r;
    s32 t;

    arg0->unk4 = 0x18;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 3;
    arg0->unk10 = func_8009E6B4(D_800EA110, 0x1D4C0, 0x10);
    arg0->unk14 = 0x1D4C0;
    arg0->unk18 = func_8009B7D8(D_800F5684, D_800F5684, arg2, 0x10);
    arg0->unk20 = 0;
    arg1->unk48 = 0;
    if (arg3 != -1) {
        arg0->unk20 = func_8009B7D8(D_800F5684, D_800F5684, arg3, 0x10);
        arg1->unk48 = func_800AC44C(arg0->unk20);
    }
    r = func_800AE424(&D_800F5678, arg4);
    t = D_800F5678.unk4;
    arg0->unk24 = 0x100;
    arg0->unk28 = 0x80;
    arg0->unk2C = arg5;
    arg0->unk30 = 0x1000;
    arg0->unk34 = 1;
    arg0->unk38 = 0x28;
    arg0->unk3C = 0x200;
    arg0->unk1C = t + r;
    D_800ECB40 = arg0->unk2C;
    return 1;
}
