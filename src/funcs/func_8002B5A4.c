#include "common.h"

extern u8 D_800D3130[];
void func_800A735C(void *, s32);

void func_8002B5A4(void) {
    u8 *p;

    p = D_800D3130;
    func_800A735C(p + 0x1AC, 2);
}
