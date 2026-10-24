#include "common.h"

u8 *func_800AB1DC(u8 *a0, u8 *a1) {
    a0[0xCA] = *a1;
    return a1 + 1;
}
