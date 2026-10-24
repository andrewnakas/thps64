/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 padF[5];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 pad17[0xD];
} Vtx24;

typedef struct {
    u8 pad0[0x64];
    s32 unk64;
    Vtx24 *unk68;
} Obj;

void func_8007C480(Obj *arg0, u8 r, u8 g, u8 b, u8 r2, u8 g2, u8 b2) {
    s32 i;

    for (i = 0; i < arg0->unk64; i++) {
        arg0->unk68[i].unkC = r;
        arg0->unk68[i].unkD = g;
        arg0->unk68[i].unkE = b;
        arg0->unk68[i].unk14 = r2;
        arg0->unk68[i].unk15 = g2;
        arg0->unk68[i].unk16 = b2;
    }
}
