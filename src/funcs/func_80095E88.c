/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[9];
    u8 unkD;
    u8 padE[0xA];
} Ent;

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0xE];
    Ent ents[1];
} Obj;

s32 func_80049034(s32, s32, s32);

void func_80095E88(Obj *arg0, s32 arg1) {
    s32 i;
    s32 idx;

    for (i = 0; i < arg0->unk5; i++) {
        if (func_80049034(arg1, arg0->ents[i].unk0, -1) != 0) {
            idx = i;
            goto found;
        }
    }
    idx = 0;
found:
    arg0->ents[idx].unkD = 0;
}
