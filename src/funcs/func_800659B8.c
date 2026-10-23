#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

s32 func_8004706C(void *);

void func_800659B8(u8 *a, V3 *b) {
    if (func_8004706C(a + 0x2FC)) {
        *(V3 *)(a + 0x2FC) = *b;
        *(s32 *)(a + 0x2A4) |= 1;
    }
}
