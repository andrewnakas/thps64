/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9[0x17];
} Elem80033100;

typedef struct {
    u8 pad0[0x54];
    Elem80033100 e[8];
} Row80033100;

typedef struct {
    u8 pad0[8];
    u8 x8;
    u8 pad9[0xB];
} Tbl80033100;

typedef struct {
    u8 pad0[0x3D];
    u8 unk3D;
    u8 pad3E;
    u8 unk3F;
    u8 pad40[0x50 - 0x40];
    s32 unk50;
    u8 pad54[0x4E8 - 0x54];
    u8 unk4E8[0x644 - 0x4E8];
    s16 unk644;
    u8 pad646[2];
    s16 unk648;
} Obj80033100;

void func_800057E4(void *, char *, ...);
extern char D_80019BA0[];
extern char D_80019BB0[];
extern Row80033100 D_800D4D80[];
extern Tbl80033100 D_800DE9F4[];

void func_80033100(Obj80033100 *arg0) {
    if (arg0->unk644 == 0x18B && arg0->unk648 == 2) {
        arg0->unk648 = 0;
        return;
    }
    if (arg0->unk644 >= 0x227) {
        if (arg0->unk648 == 1) {
            if (arg0->unk50 == 0) {
                func_800057E4(arg0->unk4E8, D_80019BA0,
                              D_800D4D80[arg0->unk3D].e[arg0->unk3F].x8 - D_800DE9F4[arg0->unk3D].x8);
            } else {
                func_800057E4(arg0->unk4E8, D_80019BB0, D_800D4D80[arg0->unk3D].e[arg0->unk3F].x4);
            }
            arg0->unk648 = 2;
            return;
        }
    } else if (arg0->unk648 == 1) {
        arg0->unk644 += 0x32;
        return;
    }
    if (arg0->unk648 == 2) {
        arg0->unk644 -= 0x32;
    }
}
