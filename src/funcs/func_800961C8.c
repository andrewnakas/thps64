/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x4];
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 pad16[0x2];
} Ent800961C8;

typedef struct {
    s8 unk0;
    u8 pad1[0x4];
    u8 unk5;
    u8 pad6[0x2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Ent800961C8 unk14[15];
} Obj800961C8;

extern void func_800960E8(Obj800961C8 *, s32);

Obj800961C8 *func_800961C8(Obj800961C8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 i;

    arg0->unk8 = arg1;
    arg0->unkC = arg2;
    arg0->unk0 = arg3;
    arg0->unk10 = arg6;
    arg0->unk5 = 0;
    for (i = 0; i < 15; i++) {
        arg0->unk14[i].unkF = 0xB6;
        arg0->unk14[i].unk10 = 0x84;
        arg0->unk14[i].unk11 = 0x24;
        arg0->unk14[i].unk12 = 0x7A;
        arg0->unk14[i].unk13 = 0x7A;
        arg0->unk14[i].unk14 = 0x7A;
        arg0->unk14[i].unk15 = 0x80;
        arg0->unk14[i].unk8 = arg4;
        arg0->unk14[i].unkA = arg5;
    }
    func_800960E8(arg0, 0);
    return arg0;
}
