/* cflags: -Wa,-no-m4100 */
#include "common.h"

extern s32 D_800DE994;

s32 func_8005C954(s32 arg0, s32 arg1, s32 arg2) {
    s32 d;
    s32 r;
    s32 w;
    s32 m;

    d = arg1 - arg0;
    r = D_800DE994 / (60 / arg2);
    w = d * 2;
    m = r % w;
    if (d < m) {
        m = w - m;
    }
    return arg0 + m;
}
