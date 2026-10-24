#include "common.h"

void func_8007DA10(u8 *arg0) {
    u32 i = 0;
    s32 c;

    do {
        c = i < *(u32 *)(arg0 + 0x50);
        i++;
    } while (c);
}
