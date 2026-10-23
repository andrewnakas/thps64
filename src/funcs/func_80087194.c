#include "common.h"

void func_80087194(s32 arg0, s32 arg1) {
    arg0 += arg1 * 4;
    *(s32 *) (arg0 + 0xA0) = 1;
}
