/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
} Ent;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
} Big;

extern Ent D_800DE9F4[];

s32 func_8002AFF4(void) {
    s32 i;
    Big *e;

    for (i = 0; i < 11; i++) {
        e = (Big *)&D_800DE9F4[i];
        if (e->unk18 == 1) {
            return 1;
        }
    }
    return 0;
}
