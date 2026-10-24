/* cflags: -O2 */
#include "common.h"

s32 func_80001EC0(u8 *, u8 *, s32); /* extern */
extern u8 D_800ECF54[];

void func_800B30E4(void) {
    func_80001EC0(D_800ECF54, D_800ECF54 + 0x18, 1);
}
