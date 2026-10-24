/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
typedef struct { u16 v[4]; u8 pad[0x10]; } E8009609C;
typedef struct { u8 pad[2]; u8 sel; u8 pad2[0x15]; E8009609C e[15]; } S8009609C;

void func_8009609C(S8009609C *a) {
    s32 i;
    
    a->sel = 0;
    for (i = 0; i < 15; i++) {
        ((u16 *)a)[i * 12 + 13] = (i == a->sel) ? a->e[i].v[2] : a->e[i].v[3]; a->e[i].v[0] = a->e[i].v[1];
    }
}
