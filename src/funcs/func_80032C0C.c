/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x14];
    u16 v14;
    u8 pad16[6];
    u8 v1C;
    u8 pad1D[3];
} Ent32C0C;

typedef struct {
    u8 pad[0x40];
    Ent32C0C e[8];
    u8 pad2[0x14];
} Row32C0C;

typedef struct {
    u8 pad[8];
    u8 v8;
    u8 pad9[0x14 - 9];
} Tab32C0C;

void func_80039E60(s32, s32, s32);
void func_800B1A80(void *, s32);
extern u16 D_80019C44[];
extern u8 D_800D4770[];
extern u8 D_800D4778[];
extern Row32C0C D_800D4D80[];
extern Tab32C0C D_800DE9F4[];

void func_80032C0C(void *arg0, u8 *mode, u8 *arg2, u8 *arg3, s16 *dir, s16 *arg5, s16 *arg6, s32 *arg7,
                   u8 *arg8, void *arg9, void *arg10, u16 *arg11, u8 *arg12, u8 *arg13, void *arg14, u8 *arg15,
                   u8 *arg16, s16 *arg17, s16 *arg18, void *arg19, s16 *arg20) {
    switch (*mode) {
    case 0:
        *arg2 = *arg3;
        if (*dir == -1) {
            if (*arg3 != 0) {
                *arg6 = 0x8D;
                *arg5 = 0xB;
                (*arg3)--;
            } else {
                *arg6 = 0x8D;
                *arg5 = 0xB;
                *arg3 = 7;
            }
        } else if (*dir == 1) {
            if (*arg3 != 7) {
                *arg6 = 0x8D;
                *arg5 = 0x10F;
                (*arg3)++;
            } else {
                *arg6 = 0x8D;
                *arg5 = 0x10F;
                *arg3 = 0;
            }
        }
        *arg7 = D_800DE9F4[*arg8].v8 >= D_800D4D80[*arg8].e[*arg3].v1C;
        *arg20 = 1;
        func_80039E60(0x94, 0x2710, 0);
        func_800B1A80(arg10, *arg11);
        if (*arg7 != 0) {
            *arg11 = D_800D4D80[*arg8].e[*arg3].v14;
        } else {
            *arg11 = 0x40;
        }
        func_800B1A80(arg9, *arg11);
        break;
    case 1:
        if (*dir == -1) {
            if (*arg12 != 0) {
                (*arg12)--;
            } else {
                *arg12 = 2;
            }
        } else if (*dir == 1) {
            if (*arg12 != 2) {
                (*arg12)++;
            } else {
                *arg12 = 0;
            }
        }
        func_80039E60(0x96, 0x2710, 0);
        *arg13 = D_800D4770[*arg12];
        func_800B1A80(arg14, D_80019C44[*arg12]);
        break;
    case 2:
        *arg15 = *arg16;
        if (*dir == -1) {
            if (*arg16 != 0) {
                *arg17 = 0xDF;
                *arg18 = 0xB7;
                (*arg16)--;
            } else {
                *arg17 = 0xDF;
                *arg18 = 0xB7;
                *arg16 = 0xE;
            }
        } else if (*dir == 1) {
            if (*arg16 != 0xE) {
                *arg17 = 0xDF;
                *arg18 = 0x107;
                (*arg16)++;
            } else {
                *arg17 = 0xDF;
                *arg18 = 0x107;
                *arg16 = 0;
            }
        }
        func_80039E60(0x97, 0x2710, 0);
        func_800B1A80(arg10, D_800D4778[*arg15]);
        func_800B1A80(arg19, D_800D4778[*arg16]);
        break;
    }
}
