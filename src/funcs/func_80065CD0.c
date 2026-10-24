/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 r, g, b;
    u8 pad3;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
} Cell65CD0;

typedef struct {
    s32 unk0;
    u8 pad4[0xE4 - 4];
    Cell65CD0 cells[20][8];
    u8 pad864[0x86A - 0x864];
    u8 unk86A[0xA10 - 0x86A];
} State65CD0;

typedef struct {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0x78 - 0x48];
} Track65CD0;

s32 func_80049D60(s32);
void func_80065E8C(void);
extern s32 D_800C0E24;
extern s32 D_800C0E28;
extern Track65CD0 D_800D5C1C[];
extern u8 *D_800DC390[];
extern State65CD0 D_800DE9F4;

void func_80065CD0(void) {
    u8 *p;
    u32 k;
    u8 **t;
    s32 n;
    s32 i;
    s32 j;

    p = (u8 *)&D_800DE9F4;
    for (k = 0; k < 0xA10; k++) {
        *p++ = 0;
    }
    D_800DE9F4.unk0 = 0x60299;
    n = 0;
    t = D_800DC390;
    while (*t != NULL) {
        t++;
        n++;
    }
    i = 0;
    while (1) {
        j = 0;
        if (i >= 20) {
            break;
        }
        while (1) {
            if (j >= 8) {
                break;
            }
            t = &D_800DC390[func_80049D60(n)];
            D_800DE9F4.cells[i][j].r = (*t)[0];
            D_800DE9F4.cells[i][j].g = (*t)[1];
            D_800DE9F4.cells[i][j].b = (*t)[2];
            D_800DE9F4.cells[i][j].unk8 = D_800D5C1C[i].unk44 + (7 - j) * 5000;
            D_800DE9F4.cells[i][j].unk4 = func_80049D60(10);
            j++;
        }
        i++;
    }
    D_800C0E28 = 0;
    D_800C0E24 = 0;
    {
        u8 *q = (u8 *)&D_800DE9F4;
        s32 m;

        for (m = 0; m < 2; m++) {
            q[m + 0x86A] = 1;
        }
    }
    func_80065E8C();
}
