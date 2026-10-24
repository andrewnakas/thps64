/* cflags: -O2 */
#include "common.h"

f32 func_800B4020(s32 arg0) {
    if (arg0 < 0) {
        if (arg0 < -70) {
            arg0 = -70;
        } else if (arg0 > -7) {
            arg0 = -7;
        }
        return (f32)(arg0 + 7) / 63.0f;
    }
    if (arg0 > 70) {
        arg0 = 70;
    } else if (arg0 < 7) {
        arg0 = 7;
    }
    return (f32)(arg0 - 7) / 63.0f;

}
