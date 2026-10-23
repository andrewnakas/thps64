#include "common.h"

extern u8 D_800D3EB0[];
void func_8009B6C0(void *);
void func_800B2BAC(void *);
void func_800A5A2C(void *);

void func_80038F60(void) {
    u8 *p;

    p = D_800D3EB0;
    func_8009B6C0(p);
    func_800B2BAC(p + 0xC);
    func_800A5A2C(p + 0x18);
}
