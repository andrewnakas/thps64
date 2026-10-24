#include "common.h"

s32 func_800AC338(s32);                               /* extern */
s32 func_800AE1A0();                                /* extern */

s32 func_800AB75C(void) {
    s32 temp_v0;

    temp_v0 = func_800AE1A0();
    func_800AC338(temp_v0);
    return temp_v0;
}
