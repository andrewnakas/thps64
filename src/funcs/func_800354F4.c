#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Entry_800354F4;

extern s32 D_800D36F0;
extern Entry_800354F4 D_800FA3D0[];

void func_800354F4(s32 arg0) {
    Entry_800354F4 *base;
    Entry_800354F4 *e;
    s32 n;

    n = D_800D36F0;
    if (n < 48) {
        base = D_800FA3D0;
        e = &base[n];
        D_800D36F0 = n + 1;
        e->b = arg0;
        e->a = 0;
    }
}
