#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    u8 pad0[4];
    Vec3i unk4;
    u8 pad10[0x38];
    void *vtbl;
    u8 pad4C[0x38];
    Vec3i unk84;
    u8 pad90[0x25];
    u8 unkB5;
    u8 unkB6;
    u8 unkB7;
    u8 padB8[2];
    s16 unkBA;
    u8 padBC[0xA0];
    s16 unk15C;
    u8 pad15E[0xAE];
    u8 unk20C;
    u8 pad20D[7];
    s32 unk214;
    Vec3i unk218;
    s32 unk224;
    u8 pad228[8];
    s32 unk230;
    u8 pad234[4];
    s32 unk238;
    u8 pad23C[2];
    s16 unk23E;
    s16 unk240;
    s16 unk242;
} Ped;

void func_8004A08C(Ped *);
s32 func_80049D60(s32);
extern u8 D_8001E730[];

Ped *func_8008251C(Ped *arg0, s32 arg1, Vec3i *arg2, Vec3i *arg3) {
    func_8004A08C(arg0);
    arg0->vtbl = D_8001E730;
    arg0->unk214 = 0;
    arg0->unk238 = 0;
    arg0->unk230 = 0;
    arg0->unk20C = 100;
    arg0->unk218 = *arg2;
    arg0->unk4 = *arg2;
    arg0->unk84 = *arg3;
    arg0->unkB5 = 5;
    arg0->unkB6 = 5;
    arg0->unkB7 = 5;
    arg0->unk242 = func_80049D60(20) + 90;
    arg0->unk23E = 50;
    arg0->unk240 = 50;
    arg0->unk15C = 300;
    arg0->unkBA = 50;
    switch (arg1) {
    case 5:
        arg0->unk224 = 0x54636518;
        break;
    case 6:
        arg0->unk224 = 0xBA6D0434;
        break;
    case 7:
        arg0->unk224 = 0x2364558E;
        break;
    }
    return arg0;
}
