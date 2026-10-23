/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct State800721DC {
    u16 unk0;
    u8 pad2[0x38];
    u16 unk3A;
    u8 pad3C[0xC];
    void * unk48;
    u8 pad4C[0x6];
    u16 unk52;
    u8 pad54[0x104];
    s32 unk158;
    u16 unk15C;
    u16 unk15E;
    u8 pad160[0x134];
    u8 unk294;
    u8 pad295[0xB];
    u16 unk2A0;
    u8 pad2A2[0x6];
    s32 unk2A8;
    u8 pad2AC[0x2C];
    s32 unk2D8;
    u8 pad2DC[0x18];
    u16 unk2F4;
    u8 pad2F6[0x12];
    s32 unk308;
    s32 unk30C;
    s32 unk310;
    u8 pad314[0x14];
    s32 unk328;
} State800721DC;

void func_8004AE80();                                  /* extern */
s32 func_8004B204(void *, s32);                     /* extern */
s32 func_8004B22C(void *, s32);                       /* extern */
void func_8004B30C(void *, void *);                       /* extern */
extern u8 D_8001D288;
extern u8 D_8001D2E0;
extern s32 D_800D61A0;
extern s32 D_800DDC50;
extern u8 D_800DDC60;

State800721DC *func_800721DC(State800721DC *arg0, s32 arg1, s16 arg2) {
    s32 temp_v0;

    func_8004AE80();
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
    arg0->unk48 = &D_8001D288;
    arg0->unk310 = (s32) D_800D61A0;
    temp_v0 = func_8004B204(arg0, func_8004B22C(arg0, arg1));
    arg0->unk328 = -1;
    arg0->unk2A8 = temp_v0;
    arg0->unk294 = 1;
    arg0->unk15E = arg2;
    arg0->unk0 = (u16) (arg0->unk0 | 1);
    arg0->unk52 = (u16) (arg0->unk52 & 0xFFEF);
    func_8004B30C(arg0, &D_800DDC60);
    arg0->unk15C = 0;
    arg0->unk3A = 0xCB;
    return arg0;
}
