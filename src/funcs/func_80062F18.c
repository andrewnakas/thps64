#include "common.h"

extern s32 D_800DAD70[];

s32 func_80062F18(s32 arg0) {
    if (arg0 == D_800DAD70[0]) {
        return 0;
    }
    if (arg0 == D_800DAD70[1]) {
        return 1;
    }
    return -1;
}
