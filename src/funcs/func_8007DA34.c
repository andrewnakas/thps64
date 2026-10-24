/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} G8;

typedef struct {
    u8 pad0[0x48];
    G8 *unk48;
    G8 *unk4C;
    s32 unk50;
    u32 unk54;
} S;

void func_8007DA34(S *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    u32 v;
    u32 i;
    G8 *g;

    v = (0x3A << 24) | (arg4 << 16) | (arg3 << 8) | arg2;
    arg0->unk48[arg1].w1 = v;
    g = &arg0->unk4C[arg1];
    for (i = 0; i < arg0->unk54; i++) {
        g->w1 = v;
        g += arg0->unk50;
    }

}
