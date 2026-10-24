/* cflags: -O2 */
#include "common.h"

s32 func_8009ECF8(u8 *, s32);              /* extern */
extern u8 D_800EA110;

void func_800A1E70(void *arg0) {
    func_8009ECF8(&D_800EA110, (*(s32 *)((u8 *)arg0 + 0x4EC)));
    (*(s32 *)((u8 *)arg0 + 0x4EC)) = 0;
}
