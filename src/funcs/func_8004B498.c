#include "common.h"

extern u8 D_8001B4A0[];
void func_8005EA48(void *arg0);

void func_8004B498(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x48) = D_8001B4A0;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
