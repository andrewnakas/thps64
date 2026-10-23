#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Pair_6D3A4;

extern Pair_6D3A4 D_800DC82C[];
extern s32 D_800DC91C;

void func_8006D3A4(s32 *arg0, s32 *arg1) {
    *arg0 = D_800DC82C[D_800DC91C].a;
    *arg1 = D_800DC82C[D_800DC91C].b;
    D_800DC91C = (D_800DC91C + 1) % 30;
}
