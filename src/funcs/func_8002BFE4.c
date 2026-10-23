#include "common.h"

extern char D_800D3668[];
extern s32 func_8000574C(char *);

void func_8002BFE4(void) {
    char *s;
    s32 p;
    s32 n;

    s = D_800D3668;
    n = func_8000574C(s); if (n < 13) { p = (s32)s; do { *(char *)(n + p) = 0x20; n++; } while (n < 13); }
}
