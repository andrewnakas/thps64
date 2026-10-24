/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
    s32 unk14[3];
} T8006F3F0;

typedef struct {
    s32 x, y, z;
} V8006F3F0;

extern s32 D_800DDA28;
extern T8006F3F0 *D_800DDA2C;
extern char *D_800DDC30;

void func_8006F3F0(V8006F3F0 *arg0, s32 n, u8 arg2, u8 arg3, u8 arg4, s32 arg5) {
    s32 started;
    s32 div;
    s32 q;
    s32 arg1;

    D_800DDA2C->unk0 = 0;
    *(V8006F3F0 *)D_800DDA2C->unk14 = *arg0;
    D_800DDA2C->unk10 = 1;
    D_800DDA2C->unk11 = arg5;
    D_800DDA2C->unk8 = D_800DDC30;
    D_800DDA2C->unkC = D_800DDA28 | (arg4 << 16) | (arg3 << 8) | arg2;
    arg1 = n;
    if (arg1 < 0) {
        arg1 = -arg1;
        *D_800DDC30++ = '-';
    }
    started = 0;
    div = 1000000000;
    while (1) {
        if (div <= 0) {
            break;
        }
        if (arg1 >= div) {
            q = arg1 / div;
            *D_800DDC30++ = q + '0';
            arg1 -= q * div;
            started = 1;
        } else if (started != 0 || div == 1) {
            *D_800DDC30++ = '0';
        }
        div /= 10;
    }
    *D_800DDC30++ = 0;
    D_800DDA2C++;
    D_800DDA2C->unk0 = 1;
}
