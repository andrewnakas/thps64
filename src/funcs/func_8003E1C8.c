/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[0x14 - 9];
} Unk8003E1C8;

extern Unk8003E1C8 D_800DE9F4[];
extern s32 D_800D0FC0[];
extern s32 D_800D0FC8;

void func_8003E1C8(void) {
    s32 i;

    for (i = 0; i < 11; i++) {
        if (D_800DE9F4[i].unk8 == 0x1E) {
            D_800D0FC0[2] = 1;
            return;
        }
    }
    D_800D0FC8 = 0;
}
