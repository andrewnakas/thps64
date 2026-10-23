/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9[0x17];
} Elem80032FBC;

typedef struct {
    u8 pad0[0x54];
    Elem80032FBC e[8];
} Row80032FBC;

typedef struct {
    u8 pad0[8];
    u8 x8;
    u8 pad9[0xB];
} Tbl80032FBC;

typedef struct {
    u8 pad0[0x3C];
    u8 unk3C;
    u8 pad3D;
    u8 unk3E;
    u8 pad3F[0x4C - 0x3F];
    s32 unk4C;
    u8 pad50[0x4D8 - 0x50];
    u8 unk4D8[0x642 - 0x4D8];
    s16 unk642;
    u8 pad644[2];
    s16 unk646;
} Obj80032FBC;

void func_800057E4(void *, char *, ...);
extern char D_80019BA0[];
extern char D_80019BB0[];
extern Row80032FBC D_800D4D80[];
extern Tbl80032FBC D_800DE9F4[];

void func_80032FBC(Obj80032FBC *arg0) {
    if (arg0->unk642 == 0x87 && arg0->unk646 == 2) {
        arg0->unk646 = 0;
        return;
    }
    if (arg0->unk642 < -0x28) {
        if (arg0->unk646 == 1) {
            if (arg0->unk4C == 0) {
                func_800057E4(arg0->unk4D8, D_80019BA0,
                              D_800D4D80[arg0->unk3C].e[arg0->unk3E].x8 - D_800DE9F4[arg0->unk3C].x8);
            } else {
                func_800057E4(arg0->unk4D8, D_80019BB0, D_800D4D80[arg0->unk3C].e[arg0->unk3E].x4);
            }
            arg0->unk646 = 2;
            return;
        }
    } else if (arg0->unk646 == 1) {
        arg0->unk642 -= 0x28;
        return;
    }
    if (arg0->unk646 == 2) {
        arg0->unk642 += 0x28;
    }
}
