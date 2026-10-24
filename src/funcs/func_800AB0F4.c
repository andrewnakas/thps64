#include "common.h"

u8 *func_800AB0F4(u8 *arg0, u8 *arg1) {
    arg0[0xBD] = *arg1 >> 1;
    return arg1 + 1;
}
