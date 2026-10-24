/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0x10];
    u8 unk1C[0x3D0];
    u8 unk3EC[0x34];
    s32 unk420;
    u8 pad424[0x10];
    s32 unk434;
    u8 pad438[0xC];
    s32 unk444;
    s32 unk448;
    s32 unk44C;
} Menu;

s32 func_8000B470(void *, void *, s32);
s32 func_8000C900(void *, void *, s32);
void func_800A04D8(Menu *, s32);
void func_800A0E74(Menu *, s32, s32);
void func_800057E4(void *, char *, s32);
void func_800A3750(Menu *, void *, s32, s32, s32, s32 *, s32);
void func_800A0870(Menu *, s32, s32);
extern s32 D_800EA550;
extern char D_80020F48[];

s32 func_800A2090(Menu *arg0, void *arg1) {
    s32 r;

    r = func_8000B470(arg0->unk3EC, arg1, arg0->unk434);
    while (1) {
        if (r != 2) break;
        func_800A04D8(arg0, arg0->unk434);
        r = func_8000B470(arg0->unk3EC, arg1, arg0->unk434);
    }
    switch (r) {
    case 0:
        return 1;
    case 10:
        if (func_8000C900(arg0->unk3EC, arg1, arg0->unk434) != 0) {
            func_800A0E74(arg0, 1, D_800EA550);
            arg0->unk8 = 0x15;
            break;
        }
        func_800057E4(arg0->unk1C, D_80020F48, arg0->unk434 + 1);
        {
            s32 t = arg0->unk420;
            arg0->unk448 = D_800EA550;
            arg0->unk44C = t;
            arg0->unk444 = t;
        }
        func_800A3750(arg0, arg0->unk1C, arg0->unk434, 4, 0, &arg0->unk444, 0);
        return 0;
    default:
        func_800A0870(arg0, r, arg0->unk420);
        break;
    }
    return 0;
}
