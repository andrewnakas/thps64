#include "common.h"

u8 *func_800619F8(u8 *arg0) {
    while (*arg0 != 0) {
        arg0++;
    }
    arg0++;
    return arg0 + ((s32) arg0 & 1);
}
