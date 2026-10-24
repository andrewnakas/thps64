/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x8];
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 padF[0x9];
} Ent80096134;

typedef struct {
    u8 pad0[0x5];
    u8 unk5;
    u8 pad6[0x6];
    s32 unkC;
    s32 unk10;
    Ent80096134 unk14[1];
} Obj80096134;

void func_80096134(Obj80096134 *arg0) {
    s32 cnt;
    s32 i;
    s32 sum;

    cnt = 0;
    sum = 0;
    for (i = 0; i < arg0->unk5; i++) {
        if (arg0->unk14[i].unkD != 0) {
            sum += arg0->unk14[i].unkC;
            cnt++;
        }
    }
    arg0->unkC = (0xF0 - ((cnt - 1) * arg0->unk10 + sum)) / 2;
}
