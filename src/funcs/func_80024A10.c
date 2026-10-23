#include "common.h"

void func_800A735C(void *, s32);
void func_800394A8(void *, s32);

void func_80024A10(u8 *arg0, s32 arg1) {
    func_800A735C(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
