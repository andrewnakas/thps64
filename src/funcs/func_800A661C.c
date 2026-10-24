#include "common.h"

void func_800A661C(u8 *arg0, s32 arg1) {
    s32 t = *(s32 *)(arg0 + 0x40);
    t += arg1;
    *(s32 *)(arg0 + 0x40) = t;
}
