/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u8 unkC[8];
} Ent8006648C;

extern Ent8006648C D_800DE9F4[];
extern s32 D_800C0E20;
extern u8 *D_800DE7A8;

s32 func_8006648C(s32 arg0) {
    return (D_800DE9F4[*(s32 *)(D_800DE7A8 + 0x3E0)].unkC[D_800C0E20] >> arg0) & 1;
}
