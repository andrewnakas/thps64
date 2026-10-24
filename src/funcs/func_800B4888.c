/* cflags: -O2 */
#include "common.h"

s32 func_800B46EC();                                /* extern */
s32 func_800B4818(s32, s32);                          /* extern */

void func_800B4888(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_800B46EC();
    if (temp_v0 != 0) {
        func_800B4818(arg0, temp_v0);
    }
}
