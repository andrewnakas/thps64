#include "common.h"

s32 func_800A7284(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x7C) != 0) {
        return *(s32 *)(arg0 + 0x7C) + 100;
    }
    return 0;
}
