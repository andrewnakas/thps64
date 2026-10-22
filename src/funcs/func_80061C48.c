#include "common.h"

s32 func_80061C48(u8 arg0, u8 *arg1) {
    s32 c;

    c = *arg1;
    while (c != 0xFF) {
        arg1++;
        if (c == arg0) {
            return 1;
        }
        c = *arg1;
    }
    return 0;
}
