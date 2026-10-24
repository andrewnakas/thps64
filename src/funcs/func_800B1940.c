/* cflags: -O2 */
#include "common.h"

s32 func_800B1A10(void *); /* extern */
s32 func_800B1A80(void *, s32); /* extern */
extern u8 D_80021F08;

void *func_800B1940(void *arg0, s32 arg1) {
    *(u8 **)((u8 *)arg0 + 0x10) = &D_80021F08;
    func_800B1A10(arg0);
    func_800B1A80(arg0, arg1);
    return arg0;
}
