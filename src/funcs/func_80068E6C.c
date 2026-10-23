#include "common.h"

extern u8 *D_800DC5C0;
void func_8009E334(void);

void func_80068E6C(u8 *arg0, s32 arg1) {
    u8 *p;
    if (D_800DC5C0 == arg0) {
        D_800DC5C0 = *(u8 **)(arg0 + 0x20);
    }
    p = *(u8 **)(arg0 + 0x1C);
    if (p != NULL) {
        *(u8 **)(p + 0x20) = *(u8 **)(arg0 + 0x20);
    }
    p = *(u8 **)(arg0 + 0x20);
    if (p != NULL) {
        *(u8 **)(p + 0x1C) = *(u8 **)(arg0 + 0x1C);
    }
    if (arg1 & 1) {
        func_8009E334();
    }
}
