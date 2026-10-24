#include "common.h"

s32 func_800C01C8(void);
void func_800C019C(void);

void func_800C01D8(void) {
    if (func_800C01C8() == 0) {
        func_800C019C();
    }
}
