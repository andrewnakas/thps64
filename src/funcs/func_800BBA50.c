/* cflags: -O2 */
#include "common.h"

extern s32 D_800FC840;
extern s32 D_800FC844;

s32 func_800BBA50(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 f;

    f = ((arg0 * arg1 + arg2) - 1.0) / arg2;
    D_800FC840 = ((s32)f / 184 + 1) * 184;
    if (D_800FC840 - f < arg3) {
        D_800FC840 += 184;
    }
    D_800FC844 = D_800FC840 - 184;
    return D_800FC840;
}
