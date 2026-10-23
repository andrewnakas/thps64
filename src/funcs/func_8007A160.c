#include "common.h"

typedef struct State8007A160 {
    u8 pad0[0x8];
    u16 unk8;
    u8 padA[0xE];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x10];
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 pad4F[0x5];
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 pad57[0x1];
    s32 unk58;
} State8007A160;

void func_8007A160(State8007A160 *arg0) {
    s32 x, y, z, limit;

    x = arg0->unk18 + arg0->unk24;
    y = arg0->unk1C + arg0->unk28;
    z = arg0->unk20 + arg0->unk2C;
    limit = arg0->unk58;
    if (limit != 0 && limit < y) {
        arg0->unk1C = limit;
    } else {
        arg0->unk18 = x;
        arg0->unk1C = y;
        arg0->unk20 = z;
        x = arg0->unk24 + arg0->unk30;
        y = arg0->unk28 + arg0->unk34;
        z = arg0->unk2C + arg0->unk38;
        x -= x >> 3;
        y -= y >> 3;
        z -= z >> 3;
        arg0->unk24 = x;
        arg0->unk28 = y;
        arg0->unk2C = z;
    }
    arg0->unk8++;
    arg0->unk4C -= arg0->unk54;
    arg0->unk4D -= arg0->unk55;
    arg0->unk4E -= arg0->unk56;
}
