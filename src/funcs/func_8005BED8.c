#include "common.h"

typedef struct {
    u8 pad0[0x884];
    s16 m[3][3];
    u8 pad1[0x8D0 - 0x896];
    s32 o[3][3];
} Obj8005BED8;

void func_8005BED8(Obj8005BED8 *arg0) {
    s32 a0, a1, a2, b0, b1, b2, c0, c1, c2;

    a0 = arg0->m[0][2];
    a1 = arg0->m[1][2];
    a2 = arg0->m[2][2];
    arg0->o[0][0] = a0;
    arg0->o[0][1] = a1;
    arg0->o[0][2] = a2;
    b0 = arg0->m[0][0];
    b1 = arg0->m[1][0];
    b2 = arg0->m[2][0];
    arg0->o[1][0] = b0;
    arg0->o[1][1] = b1;
    arg0->o[1][2] = b2;
    c0 = arg0->m[0][1];
    c1 = arg0->m[1][1];
    c2 = arg0->m[2][1];
    arg0->o[2][0] = c0;
    arg0->o[2][1] = c1;
    arg0->o[2][2] = c2;
}
