#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Pair8006D434;

extern Pair8006D434 D_800DC82C[];
extern s32 D_800DC920;

void func_8006D434(s32 a0, s32 a1) {
    Pair8006D434 *base;
    Pair8006D434 *p;

    base = D_800DC82C;
    p = &base[D_800DC920];
    p->a = a0;
    p->b = a1;
    D_800DC920 = (D_800DC920 + 1) % 30;
}
