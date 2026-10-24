/* cflags: -O2 */
#include "common.h"

void func_800A5A2C(s32 *);
s32 func_800A5B58(s32);

s32 func_800A59E0(s32 *arg0, s32 arg1) {
    func_800A5A2C(arg0);
    arg0[2] = func_800A5B58(arg1);
    arg0[0] = arg0[2];
    arg0[1] = arg1;
    return arg0[2] != 0;
}
