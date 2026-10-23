#include "common.h"

extern u8 D_800FA350[];
void *func_80038F9C(void *, s32);

void *func_80035250(s32 arg0) {
    void *p;
    u16 *q;
    u32 m;
    u16 f;

    p = func_80038F9C(D_800FA350, arg0);
    if (p != 0) {
        m = 0x1061;
        q = *(u16 **)((u8 *)p + 4);
        f = *q;
        if ((f & m) != m) {
            *q = f | m;
            return p;
        }
    }
    return 0;
}
