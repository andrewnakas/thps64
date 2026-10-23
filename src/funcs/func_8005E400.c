#include "common.h"

extern u8 D_800FA990[];
void func_800A415C(void *, s32);

void func_8005E400(void) {
    u8 *base;
    u8 *p;
    u8 *end;

    base = D_800FA990;
    if (base != 0) {
        p = base + 0xDC0;
        if (base != p) {
            end = base;
            do {
                p -= 0x6E0;
                func_800A415C(p, 2);
            } while (p != end);
        }
    }
}
