#include "common.h"

typedef struct {
    s16 x, y, z;
} Vec3s;

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    u16 unk0;
    u8 pad2[0x216];
    s32 unk218;
    s32 unk21C;
    s32 unk220;
    s32 unk224;
    f32 unk228;
    f32 unk22C;
    u8 pad230[0x46];
    u16 unk276;
    u16 unk278;
    u16 unk27A;
} Actor;

s32 func_8004B514(s32);
Actor *func_800965D0(s32, s32, void *, void *, s32, s32, void *, s32, s32);
extern u8 D_800D6188[];

void func_80096EE4(s32 arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7) {
    Vec3s pos;
    Vec3i rot;
    u8 sp40[0x10];
    u8 sp50[0x10];
    Actor *a;

    pos.x = arg0;
    pos.y = arg1;
    pos.z = arg2;
    pos.x = arg4;
    pos.y = arg5;
    pos.z = arg6;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    a = func_800965D0(func_8004B514(0x284), 0x12, sp40, sp50, arg3, arg7, D_800D6188, 0, 0xFFFF);
    a->unk278 = 0xA;
    a->unk276 = 0xA;
    a->unk27A = 0x50;
    a->unk0 |= 0x200;
    a->unk218 = arg0;
    a->unk21C = arg1;
    a->unk220 = arg4;
    a->unk224 = arg5;
    a->unk228 = arg3;
    a->unk22C = arg7;
}
