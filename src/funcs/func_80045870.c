#include "common.h"

typedef struct { u8 pad[0x38]; s32 x38; u8 pad2[0x78 - 0x3C]; } S5C1C;
extern s32 D_800D60DC;
extern s32 D_800C0E20;
extern s32 D_800DDCA0;
extern s32 D_800DDCA4;
extern s32 D_800DDCA8;
extern s32 D_800DDCAC;
extern s32 D_800DDCB0;
extern char D_800DC9FC[];
extern char D_800FA910[];
extern S5C1C D_800D5C1C[];
void func_80066224(s32, s32);
void func_80039E60(s32, s32, s32);
void func_800057E4(char *, s32, s32);
void func_8006EE1C(s32, char *, s32, s32, s32);

void func_80045870(u32 arg0) {
    char *buf;
    char *t;
    s32 *sp;
    D_800D60DC = 0x28;
    func_80066224(D_800C0E20, arg0);
    switch (arg0) {
    case 2:
        func_8006EE1C(D_800DDCA0, D_800DC9FC, 1, 0, 0);
        break;
    case 0:
        func_80039E60(0x13, 0x2710, 0);
        func_8006EE1C(D_800DDCA4, D_800DC9FC, 1, 0, 0);
        break;
    case 4:
        func_80039E60(0x13, 0x2710, 0);
        func_8006EE1C(D_800DDCA8, D_800DC9FC, 1, 0, 0);
        break;
    case 1:
        func_80039E60(0x13, 0x2710, 0);
        buf = D_800FA910;
        func_800057E4(buf, D_800DDCAC, D_800D5C1C[D_800C0E20].x38);
        t = D_800DC9FC;
        func_8006EE1C((s32)buf, t, 1, 0, 0);
        break;
    case 3:
        func_80039E60(0x9F, 0x2710, 0);
        sp = &D_800DDCB0;
        t = D_800DC9FC;
        func_8006EE1C(*sp, t, 1, 0, 0);
        break;
    }
}
