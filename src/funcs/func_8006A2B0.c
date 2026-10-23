#include "common.h"

extern void *D_800DC5E0;
void func_8006A1C0(void *, s32);

void func_8006A2B0(void) {
    u8 *p = D_800DC5E0;
    u8 *next;

    while (1) {
        if (p == NULL) {
            break;
        }
        next = *(u8 **)(p + 0xC);
        func_8006A1C0(p, 3);
        p = next;
    }
}
