#include "common.h"

extern u8 D_800FC370;

s32 func_800B38F4(s32 arg0) {
    return D_800FC370 & (1 << arg0);
}
