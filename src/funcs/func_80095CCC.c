#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x8];
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 padF[0x9];
} Ent80095CCC;

typedef struct {
    u8 pad0[0x5];
    u8 unk5;
    u8 pad6[0xE];
    Ent80095CCC unk14[1];
} Obj80095CCC;

extern s32 func_80049034(s32, s32, s32);

void func_80095CCC(Obj80095CCC *arg0, s32 arg1) {
    s32 i;
    s32 j;
    u8 *p;

    i = 0;
    if (arg0->unk5 != 0) {
        p = (u8 *)arg0;
        do {
            if (func_80049034(arg1, *(s32 *)(p + 0x14), -1) != 0) {
                j = i;
                goto found;
            }
            i++;
            p += 0x18;
        } while (i < arg0->unk5);
    }
    j = 0;
found:
    arg0->unk14[j].unkE = 0;
}
