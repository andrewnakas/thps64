/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct State8007A284 {
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
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[0x1A];
    u8 unk59;
    u8 unk5A;
} State8007A284;

void func_8007A284(State8007A284 *arg0) {
    u8 temp_v0_4;
    u8 temp_v1;
    s32 frame;

    arg0->unk18 = (s32) (arg0->unk18 + arg0->unk24);
    arg0->unk1C = (s32) (arg0->unk1C + arg0->unk28);
    arg0->unk20 = (s32) (arg0->unk20 + arg0->unk2C);
    arg0->unk24 = (s32) (arg0->unk24 + arg0->unk30);
    arg0->unk28 = (s32) (arg0->unk28 + arg0->unk34);
    arg0->unk2C = (s32) (arg0->unk2C + arg0->unk38);
    arg0->unk24 -= arg0->unk24 >> arg0->unk3C;
    arg0->unk28 -= arg0->unk28 >> arg0->unk3D;
    arg0->unk2C -= arg0->unk2C >> arg0->unk3E;
    temp_v0_4 = arg0->unk5A + 1;
    arg0->unk5A = temp_v0_4;
    frame = (s32)((u32)temp_v0_4 << 24) >> 24;
    temp_v1 = arg0->unk59;
    if (frame >= (s32) temp_v1) {
        arg0->unk5A = (u8) (temp_v1 - 1);
    }
    arg0->unk8 = (u16) (arg0->unk8 + 1);
}
