#include "common.h"

extern void func_80039E60(s32, s32, s32);

void func_8003A2E4(s32 arg0) {
    if (arg0 >= 2000) {
        func_80039E60(0x30, 10000, 0);
    }
}
