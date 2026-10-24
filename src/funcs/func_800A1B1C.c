/* cflags: -O2 */
#include "common.h"

s32 func_800A180C(u8 *, s32); /* extern */
s32 func_800A1E70(u8 *); /* extern */
extern s32 D_800EA550;

void func_800A1B1C(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) = 0x1E;
    if (*(s32 *)(arg0 + 0x18) == 0) {
        *(s32 *)(arg0 + 0x47C) = 1;
        func_800A180C(arg0, 0);
        return;
    }
    D_800EA550 = *(s32 *)(arg0 + 0x424);
    func_800A1E70(arg0);
}
