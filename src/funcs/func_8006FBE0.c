#include "common.h"

typedef struct {
    u8 pad0[4];
    u8 unk4[4];
    s32 unk8;
    u8 padC[0x3A - 0xC];
    s16 unk3A;
    u8 pad3C[0x48 - 0x3C];
    void *unk48;
    u8 pad4C[0x15E - 0x4C];
    s16 unk15E;
    s16 pad160;
    s16 unk162;
    u8 pad164[0x228 - 0x164];
    s32 unk228;
    u8 pad22C[0x2E0 - 0x22C];
    s16 unk2E0;
    s16 unk2E2;
    u8 pad2E4[0x314 - 0x2E4];
    s32 unk314;
} Obj6FBE0;

typedef struct {
    u16 unk0;
    u16 unk2;
} Info6FBE0;

void func_80072DFC(void);
void func_8004B468();
void func_8004B30C();
void func_8004AE2C(Obj6FBE0 *, s32, s32);
s32 func_8004B22C(Obj6FBE0 *, s32);
void func_8004B204(Obj6FBE0 *, s32);
Info6FBE0 *func_80061904(s32);
void func_800617B8(void *, s32);
void func_80033590(s32, Obj6FBE0 *, s32, s32, s32);
extern char D_8001CF84[];
extern char D_8001CF8C[];
extern char D_8001CF98[];
extern char D_8001CFA0[];
extern s32 D_8001CFC0;
extern s32 D_800DDC40;
extern s32 D_800DDC60;

Obj6FBE0 *func_8006FBE0(Obj6FBE0 *a0, s32 arg1, s32 a2, s32 arg3) {
    s32 id;
    Obj6FBE0 *arg0;
    s32 id3;
    s32 arg2;
    s32 snd;
    s32 v;
    char *s;

    arg0 = a0;
    id = arg1;
    arg2 = a2;
    id3 = arg3;
    func_80072DFC();
    arg0->unk48 = &D_8001CFC0;
    arg0->unk3A = id3;
    snd = -1;
    switch (id3) {
    case 0xD5:
        s = D_8001CF84;
        func_8004B468(arg0, s);
        snd = 0x63;
        break;
    case 0xD6:
        s = D_8001CF8C;
        func_8004B468(arg0, s);
        snd = 0x65;
        break;
    case 0xD7:
        s = D_8001CF98;
        func_8004B468(arg0, s);
        snd = 0x64;
        break;
    case 0xD8:
        s = D_8001CFA0;
        func_8004B468(arg0, s);
        snd = 0x66;
        break;
    }
    D_800DDC40 = 0x12C;
    s = (char *)&D_800DDC60;
    func_8004B30C(arg0, s);
    arg0->unk228 = 0x10000;
    func_8004AE2C(arg0, 0, 1);
    arg0->unk2E0 = 0x34;
    arg0->unk2E2 = 0x20;
    arg0->unk162 = 0x3C;
    do {
        func_8004B204(arg0, func_8004B22C(arg0, id));
    } while (0);
    arg0->unk15E = arg2;
    v = func_80061904(arg2)->unk2;
    arg0->unk314 = v;
    func_800617B8(arg0->unk4, v);
    arg0->unk8 += 0xFFF92000;
    func_80033590(0x2328A71C, arg0, -1, snd, 1);
    return arg0;
}
