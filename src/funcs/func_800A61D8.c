/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
} View800A61D8;

extern s32 D_800F3294;
extern s32 D_800F3298;

void func_800A61D8(View800A61D8 *v, s16 x0, s16 x1, s16 y0, s16 y1) {
    v->x0 = x0;
    v->x1 = x1;
    v->y0 = y0;
    v->y1 = y1;
    if (v->x0 < 0) {
        v->x0 = 0;
    } else if (v->x0 > D_800F3294 - 1) {
        v->x0 = D_800F3294 - 1;
    }
    if (v->x1 < 0) {
        v->x1 = 0;
    } else if (v->x1 > D_800F3294 - 1) {
        v->x1 = D_800F3294 - 1;
    }
    if (v->y0 < 0) {
        v->y0 = 0;
    } else if (v->y0 > D_800F3298 - 1) {
        v->y0 = D_800F3298 - 1;
    }
    if (v->y1 < 0) {
        v->y1 = 0;
    } else if (v->y1 > D_800F3298 - 1) {
        v->y1 = D_800F3298 - 1;
    }
}
