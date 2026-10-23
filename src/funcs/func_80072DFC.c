#include "common.h"

typedef struct State80072DFC {
    u8 pad0[0x48];
    void *unk48;
    u8 pad4C[0x10C];
    s32 unk158;
    u16 unk15C;
    u16 unk15E;
    u8 pad160[0x140];
    u16 unk2A0;
    u8 pad2A2[0x36];
    s32 unk2D8;
    u8 pad2DC[0x18];
    u16 unk2F4;
    u8 pad2F6[0x12];
    s32 unk308;
    s32 unk30C;
} State80072DFC;

void func_8004AE80(void *);
extern u8 D_8001D2E0;
extern s32 D_800DDC50;

void *func_80072DFC(State80072DFC *arg0) {
    func_8004AE80(arg0);
    arg0->unk48 = &D_8001D2E0;
    D_800DDC50 += 1;
    arg0->unk15E = 0xFFFF;
    arg0->unk15C = 0x80;
    arg0->unk2F4 = 0;
    arg0->unk2A0 = 0x20;
    arg0->unk158 = 0x40;
    arg0->unk2D8 = 0;
    arg0->unk308 = 0;
    arg0->unk30C = -1;
    return arg0;
}
