/* cflags: -O2 */
#include "common.h"

s32 func_800BC6E4(s32, void *, u8 *); /* extern */
void func_800BC9EC(void);

void func_800BC6AC(s32 arg0, u8 *arg1, s32 arg2) {
    *(s32 *)(arg1 + 0x88) = arg2;
    *(s32 *)(arg1 + 0x80) = 1;
    *(s32 *)(arg1 + 0x8C) = 0;
    func_800BC6E4(arg0, func_800BC9EC, arg1);
}
