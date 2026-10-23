#include "common.h"

s32 func_8005C194(s32 arg0, s32 arg1) {
    while ((arg0 & 0xF) == arg1) {
        arg0 >>= 4;
    }
    while (((arg0 & 0xF0) >> 4) == arg1) {
        arg0 = ((arg0 >> 8) << 4) + (arg0 & 0xF);
    }
    while (((arg0 & 0xF00) >> 8) == arg1) {
        arg0 = ((arg0 >> 12) << 8) + (arg0 & 0xFF);
    }
    return arg0;
}
