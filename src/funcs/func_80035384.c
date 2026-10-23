/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 id;
    u8 pad[0x54];
} Entry58;

void func_80037DC8(Entry58 *, s32);
extern s32 D_800D36D0;
extern Entry58 D_800FA140[];

s32 func_80035384(s32 arg0) {
    s32 i;
    s32 n;

    for (i = 0; i < D_800D36D0; i++) {
        if (D_800FA140[i].id == arg0) {
            return i;
        }
    }
    n = D_800D36D0;
    if (arg0 != -1) {
        Entry58 *q = D_800FA140;
        func_80037DC8(&q[D_800D36D0++], arg0);
    }
    return n;
}
