#include "common.h"
s32 func_80084BD4(void *, s32);
void func_8009B650(s32, s32);
extern s32 D_800F566C[];
void func_80084B88(s32 arg0) {
    s32 *ptr = D_800F566C;
    s32 addr;
    s32 offset = func_80084BD4(ptr, 1);

    addr = ptr[1];
    func_8009B650(arg0, addr + offset);
}
