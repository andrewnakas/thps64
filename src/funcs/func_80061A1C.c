#include "common.h"
extern u8 *D_800D6184;
void func_8004B0BC(void *);
void func_80061A1C(s32 arg0) {
    u8 *p;
    for (p = D_800D6184; p != NULL; p = *(u8 **)(p + 0x1C)) {
        if (*(u16 *)(p + 0x15E) == arg0) {
            func_8004B0BC(p);
        }
    }
}
