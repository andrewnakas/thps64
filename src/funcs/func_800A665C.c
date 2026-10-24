/* cflags: -O2 */
#include "common.h"

extern u32 func_8000574C(u8 *);

void func_800A665C(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 n;

    n = (func_8000574C(arg1) > 31) ? func_8000574C(arg1) : 31;
    for (i = 0; i < n; i++) {
        (arg0 + i)[0x20] = arg1[i];
    }

}
