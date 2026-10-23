#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[0x884 - 0x16];
    s16 unk884;
    s16 unk886;
    s16 unk888;
    s16 unk88A;
    s16 unk88C;
    s16 unk88E;
    s16 unk890;
    s16 unk892;
    s16 unk894;
    u8 pad896[0x8D0 - 0x896];
    s32 unk8D0;
    s32 unk8D4;
    s32 unk8D8;
    u8 pad8DC[0x8E8 - 0x8DC];
    s32 unk8E8;
    s32 unk8EC;
    s32 unk8F0;
} Obj8005EB20;

void func_80047530(s32 *, s32 *, s32);

void func_8005EB20(Obj8005EB20 *arg0) {
    s32 in[3];
    s32 out[3];
    s32 m;

    arg0->unk14 = 0;
    arg0->unk10 = 0;
    arg0->unk12 = (arg0->unk12 + 0x800) & 0xFFF;
    m = -0x1000;
    in[0] = m;
    in[1] = 0;
    in[2] = 0;
    func_80047530(out, in, arg0->unk12);
    arg0->unk884 = out[0];
    arg0->unk88A = out[1];
    arg0->unk890 = out[2];
    in[0] = 0;
    in[1] = 0;
    in[2] = m;
    func_80047530(out, in, arg0->unk12);
    arg0->unk888 = out[0];
    arg0->unk8D0 = arg0->unk888;
    arg0->unk88E = out[1];
    arg0->unk8D4 = arg0->unk88E;
    arg0->unk894 = out[2];
    arg0->unk8D8 = arg0->unk894;
    arg0->unk886 = 0;
    arg0->unk8E8 = 0;
    arg0->unk88C = m;
    arg0->unk8EC = m;
    arg0->unk892 = 0;
    arg0->unk8F0 = 0;
}
