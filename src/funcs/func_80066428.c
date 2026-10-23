/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0xC];
    u8 unkC[8];
} Entry66428;

extern Entry66428 D_800DE9F4[];
extern s32 D_800C0E20;
extern u8 *D_800DE7A8;

s32 func_80066428(void) {
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 5; i++) {
        if ((D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unkC[D_800C0E20] >> i) & 1) {
            n++;
        }
    }
    return n;
}
