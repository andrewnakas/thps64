/* cflags: -O2 */
#include "common.h"

extern void func_800B760C(void *, s32);

s32 *func_800B71C8(s32 *a0) {
    func_800B760C(a0 + 3, 0);
    a0[5] = 1;
    a0[2] = 0;
    a0[1] = 0;
    a0[0] = 0;
    return a0;
}
