#include "common.h"

s16 *func_80046AF0(s16 *arg0, s32 *arg1) {
    arg0[0] = arg0[0] / *arg1;
    arg0[1] = arg0[1] / *arg1;
    arg0[2] = arg0[2] / *arg1;
    return arg0;
}
