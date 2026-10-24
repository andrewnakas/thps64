/* cflags: -O2 */
#include "common.h"

extern void func_800BC6E4(void *, void *, s32);
extern void func_800BC878(u8 *, s32);

void func_800BD4C8(void *a0, s32 a1) {
    func_800BC6E4(a0, func_800BC878, a1);
}
