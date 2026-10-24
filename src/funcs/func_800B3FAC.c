/* cflags: -O2 */
#include "common.h"

f32 func_800B3FAC(s32 arg0) {
    if (arg0 < 0) {
        if (arg0 < -0x44) {
            arg0 = -0x44;
        } else if (arg0 > -7) {
            arg0 = -7;
        }
        return (f32)(arg0 + 7) / 61.0f;
    }
    if (arg0 > 0x44) {
        arg0 = 0x44;
    } else if (arg0 < 7) {
        arg0 = 7;
    }
    return (f32)(arg0 - 7) / 61.0f;
}
