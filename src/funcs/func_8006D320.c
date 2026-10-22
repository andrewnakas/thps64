#include "common.h"

typedef struct {
    s32 type;
    s32 val;
} Ev;

extern s32 D_800DC618;
extern Ev D_800DC82C[];
extern s32 D_800DC920;
extern s32 D_800E9038;

void func_8006D320(s32 arg0) {
    s32 *idx;
    Ev *base;
    s32 t;

    if (D_800DC618 == 1 && D_800E9038 == 0) {
        t = 2;
        base = D_800DC82C;
        idx = &D_800DC920;
        base[*idx].type = t;
        base[*idx].val = arg0;
        *idx = (*idx + 1) % 30;
    }
}
