#include "common.h"

s16 func_80071FA4(void *arg0, u16 arg1);

s32 func_800658C0(void *arg0, u16 arg1) {
    if (arg1 == 0x2200) {
        return *(s32 *)((u8 *)arg0 + 0x338);
    }
    return func_80071FA4(arg0, arg1);
}
