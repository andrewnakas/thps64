/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { u8 pad[0x10]; s16 a; s16 b; u8 pad2[0x10]; } Ent24;

void func_8007C43C(u8 *a0, s16 a1, s16 a2) {
    s32 i;
    for (i = 0; i < *(s32 *)(a0 + 0x64); i++) {
        (*(Ent24 **)(a0 + 0x68))[i].a = a1;
        (*(Ent24 **)(a0 + 0x68))[i].b = a2;
    }
}
