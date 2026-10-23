#include "common.h"

void func_8003C838(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;
    u8 *q;
    s32 v;

    p = arg0 + (arg1 << 6);
    v = p[0x29C];
    if (v == 2) {
        q = arg0 + ((arg1 + 1) << 6);
        q[0x29C] = v;
        arg0[0x240]++;
    }
    p[0x29C] = arg2;
}
