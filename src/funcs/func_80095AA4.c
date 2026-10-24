/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-strength-reduce */
#include "common.h"

typedef struct {
    u8 pad0[0x5];
    u8 unk5;
    u8 pad6[0x2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Head80095AA4;

s32 func_80049034(s32, s32, s32);

void func_80095AA4(Head80095AA4 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 i;
    u8 *e;

    *arg2 = arg0->unk8;
    *arg3 = arg0->unkC;
    i = 0;
    if (arg0->unk5 != 0) {
        e = (u8 *)arg0;
        do {
            if (e[0x21] != 0) {
                *arg3 += e[0x20];
                if (func_80049034(arg1, *(s32 *)(e + 0x14), -1) != 0) {
                    return;
                }
                *arg3 += arg0->unk10;
            }
            i++;
            e += 0x18;
        } while (i < arg0->unk5);
    }
}
