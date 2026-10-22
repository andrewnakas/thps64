#include "common.h"

typedef struct {
    u8 pad0[0x208];
    s32 unk208;
    u8 pad20C[0x3E8 - 0x20C];
    s32 unk3E8;
    s32 unk3EC;
    u8 pad3F0[0x884 - 0x3F0];
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
    s32 unk8DC;
    s32 unk8E0;
    s32 unk8E4;
} Obj8004D2D4;

void func_8004D2D4(Obj8004D2D4 *arg0) {
    if (arg0->unk3E8 != 0) {
        arg0->unk208 ^= 2;
        arg0->unk3E8 = 0;
    }
    if (arg0->unk3EC != 0) {
        arg0->unk8D0 = arg0->unk888 = -arg0->unk8D0;
        arg0->unk8D4 = arg0->unk88E = -arg0->unk8D4;
        arg0->unk8D8 = arg0->unk894 = -arg0->unk8D8;
        arg0->unk8DC = arg0->unk884 = -arg0->unk8DC;
        arg0->unk8E0 = arg0->unk88A = -arg0->unk8E0;
        arg0->unk8E4 = arg0->unk890 = -arg0->unk8E4;
        arg0->unk3EC = 0;
    }
}
