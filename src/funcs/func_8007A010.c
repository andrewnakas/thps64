/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Vec7A010 { s32 unk0, unk4, unk8; } Vec7A010;
typedef struct Bytes7A010 { u8 unk0, unk1, unk2; } Bytes7A010;

typedef struct State8007A010 {
    u8 pad0[0xA];
    u16 unkA;
    u8 padC[0xC];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 pad24[0x10];
    s32 unk34;
    u8 pad38[0x4];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[0x5];
    void * unk44;
    s32 unk48;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 unk4F;
    s32 unk50;
    u8 unk54;
    u8 unk55;
    u8 unk56;
} State8007A010;

s32 func_80049D60(s32);
void func_80079F04(void *, s32);
extern u8 D_8001E260;
extern u8 D_8001E388;
extern s32 D_800DE520;
extern s32 D_800DE55C;
extern s32 D_800DE560;
extern Bytes7A010 D_800DE564;
extern Bytes7A010 D_800DE568;

void *func_8007A010(State8007A010 *arg0, Vec7A010 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_v1;

    arg0->unk44 = &D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520 += 1;
    arg0->unk44 = &D_8001E260;
    temp_v1 = D_800DE55C & 0xF;
    if (temp_v1 == 1) {
        arg0->unk4F = 0x68U;
        arg0->unk48 = 0x02000000;
        arg0->unk50 = temp_v1;
    } else {
        arg0->unk4F = 0x60U;
        arg0->unk48 = 0x03000000;
        arg0->unk50 = (s32) D_800DE55C;
    }
    arg0->unk4C = (u8) D_800DE564.unk0;
    arg0->unk4D = (u8) D_800DE564.unk1;
    arg0->unk4E = (u8) D_800DE564.unk2;
    arg0->unk54 = (u8) D_800DE568.unk0;
    arg0->unk55 = (u8) D_800DE568.unk1;
    arg0->unk56 = (u8) D_800DE568.unk2;
    *(Vec7A010 *)&arg0->unk18 = *arg1;
    func_80079F04((u8 *)arg0 + 0x24, arg2);
    arg0->unk34 = arg3;
    arg0->unk3C = 3;
    arg0->unk3D = 3;
    arg0->unk3E = 3;
    arg0->unkA = func_80049D60(arg4);
    if (D_800DE560 != 0) {
        arg0->unk4F = (u8) (arg0->unk4F | 2);
    }
    return arg0;
}
