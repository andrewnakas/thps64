/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { u8 pad[0xC]; u8 r; u8 g; u8 b; u8 pad2[0x15]; } E8007C5D0;
typedef struct { u8 pad[0x4C]; s32 n; E8007C5D0 *e; } S8007C5D0;

void func_8007C5D0(S8007C5D0 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < arg0->n; i++) {
        arg0->e[i].r = arg1;
        arg0->e[i].g = arg2;
        arg0->e[i].b = arg3;
    }
}
