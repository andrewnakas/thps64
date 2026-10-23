/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x5C0];
    s32 x5C0;
    u8 pad5C4[0x14];
    s16 x5D8[29][10];
    u8 pad81C[0xC];
    s16 x828[10];
} S8002EAA0;

s32 func_8002EAA0(S8002EAA0 *a0) {
    s32 i;
    for (i = 0; a0->x5D8[a0->x5C0][i] != -10; i++) {
        if (a0->x5D8[a0->x5C0][i] != a0->x828[i]) {
            return 0;
        }
    }
    return 1;
}
