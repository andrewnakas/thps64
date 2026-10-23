#include "common.h"

void func_80049014(u8 *src, u8 *dst) {
    do {
        *dst = *src;
        src++;
        dst++;
    } while (src[-1] != 0);
}
