#include "common.h"
extern u8 D_800FA990[];
void func_800A3FB0(void *);
void func_8005E3B0(void) {
    u8 *p;
    s32 i;
    p = D_800FA990;
    for (i = 1; i != -1; i--) {
        func_800A3FB0(p);
        p += 0x6E0;
    }
}
