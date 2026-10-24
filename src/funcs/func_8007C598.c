/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { u8 pad[0x10]; s16 v; u8 pad2[0x12]; } Ent24;

void func_8007C598(u8 *a0, s16 a1) {
    s32 i;
    for (i = 0; i < *(s32 *)(a0 + 0x4C); i++) {
        (*(Ent24 **)(a0 + 0x50))[i].v = a1;
    }
}
