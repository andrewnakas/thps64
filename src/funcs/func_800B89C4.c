/* cflags: -O2 */
#include "common.h"

/* ceil(log2(x)) */
s32 func_800B89C4(s32 x) {
    s32 n = 0;
    s32 t = x;
    if (t == 0) {
        return 0;
    }
    while (x != 0) {
        x >>= 1;
        n++;
    }
    if (t == (1 << (n - 1))) {
        return n - 1;
    }
    return n;
}
