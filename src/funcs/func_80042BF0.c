#include "common.h"

extern u8 D_8001A770[];
void func_800B19C0(void *, s32);
void func_8003C894(void *, s32);
void func_800394A8(void *, s32);

void func_80042BF0(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x2C) = D_8001A770;
    func_800B19C0(arg0 + 0x6CC, 2);
    func_800B19C0(arg0 + 0x6B8, 2);
    func_800B19C0(arg0 + 0x6A4, 2);
    func_8003C894(arg0 + 0x34, 2);
    func_800394A8(arg0, arg1);
}
