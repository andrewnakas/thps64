#include "common.h"

s32 func_800AA834(u8 *arg0, u8 *arg1) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x2154);
    while (p != NULL) {
        if (p == arg1) {
            return 1;
        }
        p = *(u8 **)(p + 0x40);
    }
    return 0;
}
