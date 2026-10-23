/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x36];
    s16 unk36;
    s16 unk38;
    u8 pad3A[2];
    s32 unk3C;
    u8 pad40[0x27];
    u8 unk67;
    u8 pad68[0x390 - 0x68];
    u8 unk390[1];
} Obj;

void func_80039E60(s32, s32, s32);
void func_800B1A80(void *, u8);
extern u8 D_800D47C8[];

void func_8003FC04(Obj *arg0) {
    func_80039E60(0x90, 0x2710, 0);
    switch (arg0->unk3C) {
    case 1:
        if (arg0->unk67 == 0) {
            arg0->unk67 = 1;
            arg0->unk36 = 0x8B;
            func_800B1A80(arg0->unk390, D_800D47C8[arg0->unk67]);
        } else if (arg0->unk67 == 1) {
            arg0->unk67 = 2;
            arg0->unk36 = 0x8B;
            arg0->unk38 = 0x127;
            func_800B1A80(arg0->unk390, D_800D47C8[arg0->unk67]);
        } else {
            arg0->unk67 = 0;
            arg0->unk38 = 0x127;
            func_800B1A80(arg0->unk390, D_800D47C8[arg0->unk67]);
        }
        break;
    case 2:
        if (arg0->unk67 == 0) {
            arg0->unk67 = 2;
            arg0->unk36 = 0x8B;
            func_800B1A80(arg0->unk390, D_800D47C8[arg0->unk67]);
        } else if (arg0->unk67 == 1) {
            arg0->unk67 = 0;
            arg0->unk36 = 0x8B;
            arg0->unk38 = 0x127;
            func_800B1A80(arg0->unk390, D_800D47C8[arg0->unk67]);
        } else {
            arg0->unk67 = 1;
            arg0->unk38 = 0x127;
            func_800B1A80(arg0->unk390, D_800D47C8[arg0->unk67]);
        }
        break;
    }
}
