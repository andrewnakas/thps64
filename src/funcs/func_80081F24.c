/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
#include "types/tables.h"
#include "types/object.h"

typedef struct {
    u8 pad0[0xC];
    u8 b[8];
} E14;

extern E14 D_800DE9F4[];

s32 func_80081F24(void) {
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < 10; i++) {
        if (D_800D5C1C[i].unkC != 0 && (D_800DE9F4[D_800DE7A8->unk3E0].b[i] & 0x20)) {
            n++;
        }
    }
    return n == 3;
}
