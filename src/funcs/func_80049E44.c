#include "common.h"

extern s32 D_800D4668;
void func_8003A0FC(s32, s32);

void func_80049E44(void) {
    if (D_800D4668 != 0) {
        if (--D_800D4668 == 0) {
            func_8003A0FC(0x20, 0x20);
        }
    }
}
