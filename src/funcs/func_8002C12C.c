#include "common.h"

void func_800A72C0(void *);
void func_800A73EC(void *, s32);

u8 *func_8002C12C(u8 *arg0) {
    func_800A72C0(arg0);
    func_800A73EC(arg0, 0x4C6);
    *(s32 *)(arg0 + 0x240) = 1;
    return arg0;
}
