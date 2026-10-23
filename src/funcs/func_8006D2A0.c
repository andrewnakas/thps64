#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Ent8;

extern s32 D_800DC618;
extern s32 D_800E9038;
extern Ent8 D_800DC82C[];
extern s32 D_800DC920;

void func_8006D2A0(s32 a0) {
    if (D_800DC618 == 1 && D_800E9038 == 0) {
        D_800DC82C[D_800DC920].a = D_800DC618;
        D_800DC82C[D_800DC920].b = a0;
        D_800DC920 = (D_800DC920 + 1) % 30;
    }
}
