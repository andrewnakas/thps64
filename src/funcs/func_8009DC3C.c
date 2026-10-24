/* cflags: -O2 */
#include "common.h"

void func_8009DC3C(u8 *arg0) {
    s32 i;
    s32 j;
    s32 off;
    f32 v;
    f32 *p;

    i = 0;
    while (1) {
        if (i >= 4) {
            break;
        }
        for (j = 0, off = i * 16; j < 4; j++, off += 4) {
            p = (f32 *)(arg0 + off);
            v = *p;
            if (v < -32767.0f) {
                v = -32767.0f;
            } else if (v > 32767.0f) {
                v = 32767.0f;
            }
            *p = v;
        }
        i++;
    }
}
