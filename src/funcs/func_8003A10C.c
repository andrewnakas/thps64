#include "common.h"

extern u8 D_800EA9C0[];
extern u8 D_800D3F34;
void func_800AA864(void *);
void func_800A9588(void *, s32);

void func_8003A10C(void) {
    u8 *p = D_800EA9C0;
    func_800AA864(p);
    func_800A9588(p, D_800D3F34);
}
