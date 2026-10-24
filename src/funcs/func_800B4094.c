/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    u16 unkC;
    u16 unkE;
    s32 unk10;
    f32 unk14;
    f32 unk18;
} S;

extern f32 func_800B3FAC(s32, s32);
extern f32 func_800B4020(s32);

void func_800B4094(S *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t;

    arg0->unk10 = (arg3 << 16) | ((arg1 << 8) & 0xFF00) | (arg2 & 0xFF);
    t = arg0->unkC;
    arg0->unkE = t;
    arg0->unk14 = arg0->unk4;
    arg0->unk18 = arg0->unk8;
    arg0->unk4 = func_800B3FAC(arg1, t);
    arg0->unk8 = func_800B4020(arg2);
    arg0->unkC = arg3;

}
