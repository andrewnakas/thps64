/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0xC];
} Ent8006EB50;

extern Ent8006EB50 D_800DCAB4[];
extern s32 D_800DC958;
void func_8006E590(void);

void func_8006EB50(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_800DCAB4[i].unk14 != 0) {
            D_800DC958 = i;
            func_8006E590();
        }
    }
}
