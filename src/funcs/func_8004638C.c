/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x10];
} Unk8004638CEntry;

typedef struct {
    u8 pad0[0xA1C];
    u8 unkA1C[0xC18 - 0xA1C];
    Unk8004638CEntry entries[19];
    u8 padD94[0x10];
    s32 count;
} Unk8004638C;

extern void func_80045A70(void *, s32);

void func_8004638C(Unk8004638C *arg0, s32 arg1) {
    arg0->entries[arg0->count - 1].unk0 += arg1;
    func_80045A70(arg0->unkA1C, arg1);
}
