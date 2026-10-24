/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 D_800FBCCC;
extern s32 D_800FBCD0;
extern s32 D_800FBCD4;

s32 func_800794F4(s32 arg0) {
    s32 v;

    v = D_800FBCCC * D_800FBCD0 + D_800FBCD4;
    D_800FBCCC = v;
    D_800FBCD0 ^= v;
    D_800FBCD0 += v >> 4;
    D_800FBCD4 += 0xEFEFEFF0;
    D_800FBCD4 += v >> 3;
    return ((v & 0xFFFF) * arg0) >> 16;
}
