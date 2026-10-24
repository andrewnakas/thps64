#include "common.h"

f32 (*func_8009CAD0(f32 (*arg0)[4]))[4] {
    s32 i, j;
    f32 *p;

    i = 0;
    while (1) {
        if (i >= 4) break;
        p = arg0[i];
        for (j = 0; j < 4; j++) {
            if (j == i) {
                *p = 1.0f;
            } else {
                *p = 0.0f;
            }
            p++;
        }
        i++;
    }
    return arg0;
}
