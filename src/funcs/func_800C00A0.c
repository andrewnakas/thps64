/* cflags: -O2 */
#include "common.h"

s32 func_80001A30(s32, s32);                          /* extern */
s32 func_800BD9F4();                                /* extern */

s32 func_800C00A0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_800BD9F4();
    func_80001A30(arg0, temp_v0);
    return temp_v0;
}
