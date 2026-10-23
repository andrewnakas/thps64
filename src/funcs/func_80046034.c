#include "common.h"

s32 func_80049D60(s32 arg0);
void func_8006EC84(void *arg0);

void func_80046034(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x1AC) = func_80049D60(4) + 1;
    func_8006EC84((u8 *)arg0 + 0x1B0);
}
