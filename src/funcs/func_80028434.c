#include "common.h"

void func_80084E24(void *, s32);
void func_80084DBC(void *, s32);

void func_80028434(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;

    p = arg0 + 0xF18;
    *(u8 **)(arg0 + 0x1B18) = arg0;
    func_80084E24(p, arg1);
    func_80084DBC(p, arg2);
    *(s32 *)(arg0 + 0x224C) = arg1;
}
