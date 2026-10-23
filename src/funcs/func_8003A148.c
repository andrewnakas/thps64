#include "common.h"

extern u8 D_800D3F34[];
void func_8003963C(void *arg0, s32 arg1, u8 arg2, u16 arg3, s32 arg4);

void func_8003A148(u8 arg0, u16 arg1) {
    void *p;

    p = D_800D3F34;
    func_8003963C(p, 1, arg0, arg1, 0);
}
