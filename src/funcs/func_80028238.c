#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec80028238;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Tbl80028238;

typedef struct {
    u8 pad0[0x48];
    void *unk48;
    u8 pad4C[0x3E0 - 0x4C];
    s32 unk3E0;
    u8 pad3E4[0xF14 - 0x3E4];
    s8 unkF14;
    u8 padF15[0xF18 - 0xF15];
    u8 unkF18[0x1B28 - 0xF18];
    u8 unk1B28[0x2270 - 0x1B28];
    u8 unk2270[0x22D0 - 0x2270];
    u8 unk22D0[0x2368 - 0x22D0];
    s8 unk2368;
    u8 pad2369[3];
    Vec80028238 unk236C;
    Vec80028238 unk2378;
} Obj80028238;

void func_80024C90(void *);
void func_80026650(Obj80028238 *, s32, s32);
void func_8004B77C(Obj80028238 *);
void func_80084EE8(void *);
void func_800A3FB0(void *);
void func_800A5F10(void *);
extern s32 D_80017290;
extern Tbl80028238 D_800D46B0[];

Obj80028238 *func_80028238(Obj80028238 *arg0, s32 arg1, s32 arg2, s8 arg3) {
    Vec80028238 zero;
    s32 a1;

    func_8004B77C(arg0);
    arg0->unk48 = &D_80017290;
    func_80084EE8(arg0->unkF18);
    func_800A3FB0(arg0->unk1B28);
    func_800A5F10(arg0->unk2270);
    func_80024C90(arg0->unk22D0);
    arg0->unkF14 = arg3;
    arg0->unk3E0 = arg1;
    if (arg2 != 0) {
        a1 = D_800D46B0[arg1].b;
    } else {
        a1 = D_800D46B0[arg1].a;
    }
    func_80026650(arg0, a1, D_800D46B0[arg1].c);
    zero.z = 0;
    zero.y = 0;
    zero.x = 0;
    arg0->unk2378 = zero;
    arg0->unk236C = arg0->unk2378;
    arg0->unk2368 = 0;
    return arg0;
}
