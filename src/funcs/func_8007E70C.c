#include "common.h"

void func_8007DC7C(u8 *, s32);
void func_8007E5FC(u8 *);
extern u8 D_8001E2C0[];

void func_8007E70C(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x44) = D_8001E2C0;
    func_8007DC7C(arg0, 0);
    if (arg1 & 1) {
        func_8007E5FC(arg0);
    }
}
