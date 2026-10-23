#include "common.h"

s32 *func_800470E0(s32 *arg0, u8 *arg1) {
    arg0[0] -= arg0[0] >> arg1[0];
    arg0[1] -= arg0[1] >> arg1[1];
    arg0[2] -= arg0[2] >> arg1[2];
    return arg0;
}
