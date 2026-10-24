#include "common.h"

u8 *func_800AB2DC(u8 *arg0, u8 *arg1) {
    arg0[0xBC] = *arg1;
    return arg1 + 1;
}
