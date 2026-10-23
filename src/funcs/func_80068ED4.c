#include "common.h"

extern void *D_800DC5C0;
extern void func_80068E6C(void *, s32);

void func_80068ED4(void) {
    void *p;
    void *next;

    p = D_800DC5C0;
    while (1) {
        if (p == 0) {
            break;
        }
        next = *(void **)((u8 *)p + 0x20);
        func_80068E6C(p, 3);
        p = next;
    }
}
