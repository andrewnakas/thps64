#include "common.h"

void func_800394A8(void *, s32);
void func_8003C894(void *, s32);
void func_800B19C0(void *, s32);
extern u8 D_80017410[];

void func_800295E4(u8 *arg0, s32 arg1) {
    *(void **) (arg0 + 0x2C) = D_80017410;
    func_800B19C0(arg0 + 0x6D0, 2);
    func_800B19C0(arg0 + 0x6BC, 2);
    func_800B19C0(arg0 + 0x6A8, 2);
    func_8003C894(arg0 + 0x38, 2);
    func_800394A8(arg0, arg1);
}
