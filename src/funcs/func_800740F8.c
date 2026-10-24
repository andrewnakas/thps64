#include "common.h"

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Quad4 { s32 x, y, z, w; } Quad4;


typedef struct ObjectA {
    s32 unk0, unk4, unk8, unkC;
    u8 pad10[0x81C];
    s32 unk82C;
    u8 pad830[0x134];
    void *unk964;
} ObjectA;

typedef struct State800740F8 {
    u8 pad0[0x208];
    u16 unk208;
    u8 pad20A[0x2AA];
    ObjectA * unk4B4;
    u8 pad4B8[0x8];
    s32 unk4C0;
    s32 unk4C4;
    s32 unk4C8;
    u8 pad4CC[0x4];
    s32 unk4D0;
    s32 unk4D4;
    s32 unk4D8;
    u8 pad4DC[0x78];
    s32 unk554;
    s32 unk558;
    s32 unk55C;
    s32 unk560;
    s32 unk564;
    s32 unk568;
    s32 unk56C;
    s32 unk570;
    s32 unk574;
    s32 unk578;
    s32 unk57C;
    s32 unk580;
    u8 pad584[0x10];
    s32 unk594;
    s32 unk598;
    s32 unk59C;
    s32 unk5A0;
    s32 unk5A4;
    u8 pad5A8[0xC4];
    s32 unk66C;
    s32 unk670;
    s32 unk674;
    s32 unk678;
    s32 unk67C;
    s32 unk680;
    u8 pad684[0x40];
    s32 unk6C4;
    s32 unk6C8;
    s32 unk6CC;
} State800740F8;

void func_800226A0(void *, void *, void *);                 /* extern */
void func_80046D54(void *, void *, s32 *);              /* extern */
void func_80073EA0(void *);                            /* extern */
void func_80077584(void *);                            /* extern */
extern s32 D_800DE148;

void func_800740F8(State800740F8 *arg0) {
    Vec3 start, transformed, shifted;
    s32 sp40;
    ObjectA *temp_v0;
    ObjectA *target;

    target = arg0->unk4B4;
    start.x = 0;
    start.y = 0;
    start.z = -0x1000;
    func_800226A0((u8 *)target + 0x884, &start, &transformed);
    arg0->unk6C4 = transformed.x;
    arg0->unk6C8 = transformed.y;
    arg0->unk6CC = transformed.z;
    sp40 = 0xC;
    func_80046D54(&shifted, (u8 *)arg0 + 0x6C4, &sp40);
    *(Vec3 *)&arg0->unk678 = shifted;
    *(Vec3 *)&arg0->unk66C = *(Vec3 *)&arg0->unk678;
    temp_v0 = arg0->unk4B4;
    *(Vec3 *)&arg0->unk4D0 = *(Vec3 *)&temp_v0->unk4;
    *(Vec3 *)&arg0->unk4C0 = *(Vec3 *)&arg0->unk4D0;
    D_800DE148 = (s32) arg0->unk208;
    func_80077584(arg0);
    *(Quad4 *)&arg0->unk554 = *(Quad4 *)&arg0->unk564;
    *(Quad4 *)&arg0->unk574 = *(Quad4 *)&arg0->unk554;
    *(Quad4 *)&arg0->unk594 = *(Quad4 *)&arg0->unk574;
    arg0->unk5A4 = 1;
    func_80073EA0(arg0);
}
