/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    s16 unkE;
    u8 pad10[4];
    s16 unk14;
    s16 unk16;
} Box;

typedef struct {
    u8 pad0[0x18];
    Box **unk18;
    u8 pad1C[0x2C];
} Set;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[4];
    s32 unkC;
    u8 pad10[6];
    u16 unk16;
    u8 pad18[3];
    u8 unk1B;
} Obj;

void func_80069A9C(s32, s32, s32, s32, s32);
extern Set D_800DAF98[];

void func_8006A048(Obj *arg0, s32 arg1) {
    s32 x1;
    s32 z1;
    s32 x0;
    s32 z0;
    s32 x;
    s32 z;
    Box *b;

    b = D_800DAF98[arg0->unk1B].unk18[arg0->unk16];
    x = arg0->unk4 >> 12;
    z = arg0->unkC >> 12;
    x0 = x + b->unkE;
    x1 = x + b->unkC;
    z0 = z + b->unk16;
    z1 = z + b->unk14;
    func_80069A9C(x0, z0, x1, z0, arg1);
    func_80069A9C(x0, z0, x0, z1, arg1);
    func_80069A9C(x0, z1, x1, z1, arg1);
    func_80069A9C(x1, z0, x1, z1, arg1);
}
