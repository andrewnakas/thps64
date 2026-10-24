#include "common.h"

typedef struct { u8 pad[0x14]; s32 v; } E80095B60;
void func_80049034(s32, s32, s32);

void func_80095B60(u8 *arg0, s32 arg1) {
    E80095B60 *p = (E80095B60 *)arg0;
    p += arg0[2];
    func_80049034(arg1, p->v, -1);
}
