#include "common.h"

extern s32 D_800D0FCC;

s32 func_8005BF24(s32 arg0) {
    if (arg0 == 0x24A952BB) {
        D_800D0FCC = 1;
    }
    return 0;
}
