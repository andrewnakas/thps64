#include "common.h"

extern u8 D_800D0FE3;
extern u8 D_800EA9C0[];
extern u8 D_800D3F34[];
void func_800A8EF0(void *, s32);

void func_8003A268(void) {
    u8 *p;

    if (D_800D0FE3 != 8) {
        func_800A8EF0(D_800EA9C0, 0);
    }
    p = D_800D3F34;
    p[0x14] = 0;
    p[0x58] = 0;
    p[0x9C] = 0;
}
