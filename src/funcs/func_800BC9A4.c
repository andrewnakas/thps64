/* cflags: -O2 */
#include "common.h"

s32 func_800BD05C(s32); /* extern */
s32 func_800BD680(s32, s32); /* extern */

void func_800BC9A4(s32 arg0, s32 arg1) {
    func_800BD680(arg0 + 0x208, arg1);
    func_800BD680(arg0 + 0x224, arg1);
    func_800BD05C(arg0);
}
