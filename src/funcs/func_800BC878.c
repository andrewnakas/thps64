/* cflags: -O2 */
#include "common.h"

extern void func_800BC810(void *, void *, s32);

void func_800BC878(u8 *a0, s32 a1) {
    func_800BC810(a0, a0 + 0x1C8, a1);
}
