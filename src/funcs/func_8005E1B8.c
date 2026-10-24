/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 pad18;
    s16 unk1C;
    s16 unk1E;
    s32 *ptrs[20][20];
} Entry5E1B8;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    u8 pad20[0x28];
} Slot5E1B8;

extern Entry5E1B8 D_800D7720[];
extern s32 D_800DAD70[];
extern Slot5E1B8 D_800DAF98[];

void func_8005E1B8(s32 arg0, s32 *arg1) {
    s32 i;
    s32 j;
    s32 n;
    s32 base;
    s32 t;

    D_800D7720[arg0].unk4 = *arg1++;
    D_800D7720[arg0].unk8 = *arg1++;
    D_800D7720[arg0].unkC = *arg1++;
    D_800D7720[arg0].unk10 = *arg1++;
    D_800D7720[arg0].unk1C = *arg1++;
    D_800D7720[arg0].unk1E = *arg1++;
    D_800D7720[arg0].unk0 = 1;
    D_800D7720[arg0].unk14 = (D_800D7720[arg0].unkC - D_800D7720[arg0].unk4) / D_800D7720[arg0].unk1C;
    i = 0;
    while (1) {
        if (i >= D_800D7720[arg0].unk1E) {
            break;
        }
        j = 0;
        while (1) {
            if (j >= D_800D7720[arg0].unk1C) {
                break;
            }
            arg1 += 2;
            n = *arg1++;
            D_800D7720[arg0].ptrs[j][i] = arg1;
            base = D_800DAF98[D_800DAD70[arg0]].unk1C;
            while (n-- > 0) {
                t = *arg1 * 0x24 + 0xC;
                *arg1 = base + t;
                arg1++;
            }
            arg1++;
            j++;
        }
        i++;
    }
}
