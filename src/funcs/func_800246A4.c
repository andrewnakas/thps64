#include "common.h"

extern u8 D_80021F60[];
void func_800B3A90(void *);
void func_8009FF4C(void *, s32);

void func_800246A4(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x1C4) = D_80021F60;
    func_800B3A90(arg0);
    func_8009FF4C(arg0, arg1);
}
