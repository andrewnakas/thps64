#include "common.h"

s32 func_8004AEE0(void *arg0) {
    s32 r;

    r = 0;
    if ((*(u16 *)((u8 *)(arg0) + 0x52)) & 0x40) {
        r = 1;
    }
    return r;
}
