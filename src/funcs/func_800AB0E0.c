#include "common.h"

u8 *func_800AB0E0(u8 *arg0, u8 *arg1) {
    u8 v = *arg1;
    arg0[0xD2] = 0;
    arg0[0xD3] = v;
    return arg1 + 1;
}
