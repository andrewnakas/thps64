/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
    u8 unkC[8];
} T9F4;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x68];
} T5C1C;

typedef struct {
    u8 pad0[0x3E0];
    s32 unk3E0;
    u8 pad3E4[0x9F0 - 0x3E4];
    s32 unk9F0;
} T7A8;

extern T5C1C D_800D5C1C[];
extern T7A8 *D_800DE7A8;
extern T9F4 D_800DE9F4[];

void func_80066224(s32 arg0, s32 arg1) {
    s32 count;
    s32 i;
    s32 j;

    D_800DE9F4[D_800DE7A8->unk3E0].unkC[arg0] |= 1 << arg1;
    count = 0;
    j = 0;
    while (1) {
        i = 0;
        if (!(j < 10)) {
            break;
        }
        do {
            if (D_800D5C1C[j].unkC == 0 && ((D_800DE9F4[D_800DE7A8->unk3E0].unkC[j] >> i) & 1)) {
                count++;
            }
            i++;
        } while (i < 5);
        j++;
    }
    D_800DE9F4[D_800DE7A8->unk3E0].unk8 = count;
    D_800DE7A8->unk9F0++;
}
