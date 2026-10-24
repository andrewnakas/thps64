/* cflags: -O2 */
#include "common.h"

s32 func_800A5D5C(s32, s32);

void func_800A5E04(s32 arg0, s32 *arg1, s32 arg2) {
    s32 v;

    v = func_800A5D5C(arg0, arg2);
    arg1[1] = v;
    arg1[0] = v;
}
