#include "common.h"

typedef struct {
    u8 pad0[0x84];
    s32 unk84;
    u8 pad88[0x208 - 0x88];
    s32 unk208;
    u8 pad20C[0x21E - 0x20C];
    u16 unk21E;
    u8 pad220[0x884 - 0x220];
    s16 m[3][3];
    u8 pad1[0x8D0 - 0x896];
    s32 o[3][3];
} Obj8004BD2C;

s32 func_80022E54(void *, void *);

void func_8004BD2C(Obj8004BD2C *arg0) {
    if (arg0->unk21E != 0x22 && func_80022E54(arg0->o, &arg0->unk84) > 0x5000) {
        arg0->o[0][0] = arg0->m[0][2] = -arg0->o[0][0];
        arg0->o[0][1] = arg0->m[1][2] = -arg0->o[0][1];
        arg0->o[0][2] = arg0->m[2][2] = -arg0->o[0][2];
        arg0->o[1][0] = arg0->m[0][0] = -arg0->o[1][0];
        arg0->o[1][1] = arg0->m[1][0] = -arg0->o[1][1];
        arg0->o[1][2] = arg0->m[2][0] = -arg0->o[1][2];
        arg0->unk208 ^= 2;
    }
}
