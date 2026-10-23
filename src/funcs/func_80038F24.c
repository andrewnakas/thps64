#include "common.h"

extern u8 D_800D3EB0[];
void func_8003934C(void *, s32);
void func_800B2860(void *);

void func_80038F24(void) {
    u8 *p = D_800D3EB0;
    func_8003934C(p, 0);
    func_800B2860(p + 0xC);
    *(s32 *)(p + 8) = 0;
}
