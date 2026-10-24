/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x68];
} E78;

typedef struct {
    u8 pad0[0xC];
    u8 b[8];
} E14;

extern E78 D_800D5C1C[];
extern u8 *D_800DE7A8;
extern E14 D_800DE9F4[];

s32 func_80081F24(void) {
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < 10; i++) {
        if (D_800D5C1C[i].unkC != 0 && (D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].b[i] & 0x20)) {
            n++;
        }
    }
    return n == 3;
}
