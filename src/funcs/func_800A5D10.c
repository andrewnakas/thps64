/* cflags: -O2 */
#include "common.h"

extern s32 func_800A5B58(s32);
extern s32 func_800A5EE8(void *, s32);

void func_800A5D10(s32 *a0, s32 *a1, s32 a2) {
    s32 t = a0[1] + func_800A5EE8(a0, a2);
    a1[0] = func_800A5B58(t);
    a1[1] = t;
}
