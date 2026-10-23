#include "common.h"

extern u8 D_800EA110[];
s32 func_8009FEC4(s32);
void func_8009ECF8(void *, s32);

void func_8005EA48(s32 arg0) {
    if (arg0 == 0 || func_8009FEC4(arg0) != 0) {
        func_8009ECF8(D_800EA110, arg0);
    }
}
