/* cflags: -O2 */
#include "common.h"

s32 func_800B1A10();                            /* extern */
extern u8 D_80021F08;

void *func_800B198C(void *arg0) {
    (*(u8 **)((u8 *)arg0 + 0x10)) = &D_80021F08;
    func_800B1A10();
    return arg0;
}
