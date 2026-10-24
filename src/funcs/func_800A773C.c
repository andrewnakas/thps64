/* cflags: -O2 */
#include "common.h"

extern void func_800A7708(s32 *, s32);

void func_800A773C(s32 *a0, s32 a1, s32 a2) {
    a0[0] = a1;
    a0[1] = a2;
    func_800A7708(a0, a0[7]);
}
