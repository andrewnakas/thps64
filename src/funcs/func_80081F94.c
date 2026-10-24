/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} E78;

typedef struct {
    u8 pad0[0xC];
    u8 f[8];
} Row20;

typedef struct {
    u8 pad0[0x3E0];
    s32 unk3E0;
} G7A8;

extern E78 D_800D5C1C[];
extern Row20 D_800DE9F4[];
extern G7A8 *D_800DE7A8;

s32 func_80081F94(void) {
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 10; i++) {
        if (D_800D5C1C[i].unkC != 0) {
            if (D_800DE9F4[D_800DE7A8->unk3E0].f[i] & 0xE0) {
                n++;
            }
        }
    }
    return n == 3;
}
