/* cflags: -O2 */
#include "common.h"

s32 func_800B36D8(s32, f32, s32); /* extern */
extern s32 D_800ECFB0;

void func_800B389C(s32 arg0) {
    s32 old;
    s32 i;

    old = D_800ECFB0;
    D_800ECFB0 = arg0;
    if (old != 0 && arg0 == 0) {
        for (i = 0; i < 4; i++) {
            func_800B36D8(i, -0.1f, 0);
        }
    }
}
