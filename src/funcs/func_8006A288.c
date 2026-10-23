#include "common.h"

extern u16 **D_800DACB0;

s32 func_8006A288(u16 arg0) {
    return *D_800DACB0[arg0] == 0xE;
}
