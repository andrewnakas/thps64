#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x8];
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 padF[0x9];
} Ent80095FAC;

typedef struct {
    u8 pad0[0x5];
    u8 unk5;
    u8 pad6[0xE];
    Ent80095FAC unk14[1];
} Obj80095FAC;

void func_80095FAC(Obj80095FAC *arg0, s32 arg1) {
    arg0->unk14[arg0->unk5].unk0 = arg1;
    arg0->unk14[arg0->unk5].unkD = 1;
    arg0->unk14[arg0->unk5].unkE = 1;
    arg0->unk14[arg0->unk5].unkC = 0;
    arg0->unk5++;
}
