#include "common.h"

extern void func_8004B13C(void *, void *);

void func_80061A70(void **arg0, s32 arg1) {
    u8 *p;

    for (p = *arg0; p != NULL; p = *(u8 **)(p + 0x1C)) {
        if (*(u16 *)(p + 0x15E) == arg1) {
            func_8004B13C(p, arg0);
        }
    }
}
