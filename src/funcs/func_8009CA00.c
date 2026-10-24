/* cflags: -O2 */
#include "common.h"

f32 *func_8009CA00(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;
    s32 j;
    f32 (*o)[4] = (f32 (*)[4])arg0;
    f32 (*a)[4] = (f32 (*)[4])arg1;

    i = 0;
    while (1) {
        j = 0;
        if (i >= 4) break;
        for (; j < 4; j++) {
            *(f32 *)((u8 *)arg0 + (i * 16 + j * 4)) = a[i][0] * arg2[j] + a[i][1] * arg2[j + 4] + a[i][2] * arg2[j + 8] + a[i][3] * arg2[j + 12];
        }
        i++;
    }
    return arg0;
}
