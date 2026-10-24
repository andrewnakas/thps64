/* cflags: -O2 */
#include "common.h"

f32 func_800AD81C(f32);
void func_800AFB50(s32, f32);
extern s32 D_800FC2F4;

typedef struct {
    u8 pad0[0x24];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x1C];
    f32 unk4C;
    f32 unk50;
    u8 pad54[0x56];
    u16 unkAA;
    u8 padAC[0xC];
    u8 unkB8;
    u8 padB9[2];
    u8 unkBB;
} Voice;

void func_800AD184(Voice *arg0, s32 arg1) {
    f32 v;
    f32 bend;

    v = arg0->unk2C;
    if (arg0->unkB8 != 0) {
        if (arg0->unkB8 >= arg0->unkAA) {
            v = arg0->unk4C + (v - arg0->unk4C) / (f32)arg0->unkB8 * (f32)arg0->unkAA;
        }
        arg0->unk50 = v;
    }
    v = v + (bend + arg0->unk24);
    if (v != arg0->unk28) {
        arg0->unk28 = v;
        v = func_800AD81C(v * (1.0 / 12.0));
        if (v > 2.0) {
            v = 2.0f;
            arg0->unkBB = 0;
        }
        func_800AFB50(D_800FC2F4 + arg1 * 0x1C, v);
    }
}
