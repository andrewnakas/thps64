/* cflags: -O2 */
#include "common.h"

s32 func_800BC244(u8 *arg0) {
    s32 max;
    s32 sum;
    s32 i;
    s32 v;

    max = *(s32 *)(arg0 + 0x22C4);
    sum = max;
    for (i = 1; i < 4; i++) {
        v = *(s32 *)(arg0 + 0x22C4 + i * 4);
        if (max < v) {
            max = v;
        }
        sum += v;
    }
    return (sum - max + 2) / 3;
}
