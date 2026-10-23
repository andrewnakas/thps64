/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[9];
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC[8];
} Rec80066310;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x68];
} Ent80066310;

extern Ent80066310 D_800D5C1C[];
extern u8 *D_800DE7A8;
extern Rec80066310 D_800DE9F4[];

void func_80066310(s32 player, s32 bit) {
    u8 f;
    s32 n20;
    s32 n40;
    s32 n80;
    s32 i;

    D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unkC[player] |= 1 << bit;
    n20 = 0;
    n40 = 0;
    n80 = 0;
    for (i = 0; i < 10; i++) {
        if (D_800D5C1C[i].unkC == 0) {
            f = D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unkC[i];
            if (f & 0x20) {
                n20++;
            }
            if (f & 0x40) {
                n40++;
            }
            if (f & 0x80) {
                n80++;
            }
        }
    }
    D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unkB = n20;
    D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unkA = n40;
    D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unk9 = n80;
}
