/* cflags: -O2 */
#include "common.h"

extern void func_8009ECF8(void *, s32);
extern u8 D_800EA110[];

void func_800B73D4(s32 *a0) {
    s32 *p = a0 + 3;
    func_8009ECF8(D_800EA110, a0[3]);
    p[1] = 0;
    a0[3] = 0;
    a0[5] = 1;
}
