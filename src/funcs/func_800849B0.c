#include "common.h"
s32 func_800849FC(void *, s32);
void func_8009B650(s32, s32);
extern s32 D_800F566C[];
void func_800849B0(s32 arg0) {
    s32 *ptr = D_800F566C;
    s32 addr;
    s32 offset = func_800849FC(ptr, 0);

    addr = ptr[1];
    func_8009B650(arg0, addr + offset);
}
