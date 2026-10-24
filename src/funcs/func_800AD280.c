/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    s32 unk3C;
    s32 unk40;
    u8 pad44[0x10];
    s32 unk54;
    u8 pad58[0x42];
    u16 unk9A;
    u8 pad9C[0x16];
    u16 unkB2;
    u16 unkB4;
    u8 padB6[9];
    u8 unkBF;
    u8 unkC0;
    u8 padC1[2];
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
} Obj;

extern s32 D_800ECC24;

void func_800AD280(Obj *arg0) {
    if (arg0->unk9A != 0x7FFF) {
        if (arg0->unkB2 != 0) {
            arg0->unk54 = arg0->unk40 + (arg0->unkB2 << 8);
        } else {
            arg0->unk54 = arg0->unk3C - (arg0->unkB4 << 8);
        }
    } else {
        arg0->unk54 = 0x7FFFFFFF;
    }
    arg0->unkC3 = 1;
    arg0->unkC4 = arg0->unkC0;
    arg0->unkC5 = arg0->unkBF;
    D_800ECC24 = arg0->unkC5;
}
