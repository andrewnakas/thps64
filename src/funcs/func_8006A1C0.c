#include "common.h"

extern u8 *D_800DC5E0;
void func_8009E334(void);

void func_8006A1C0(u8 *arg0, s32 arg1) {
    u8 *prev = NULL;
    u8 *p = D_800DC5E0;
    while (p != arg0) {
        prev = p;
        p = *(u8 **)(p + 0xC);
    }
    if (prev != NULL) {
        *(u8 **)(prev + 0xC) = *(u8 **)(arg0 + 0xC);
    } else {
        D_800DC5E0 = *(u8 **)(arg0 + 0xC);
    }
    if (arg1 & 1) {
        func_8009E334();
    }
}
