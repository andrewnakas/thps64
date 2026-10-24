/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 x0;
    s16 y0;
    s16 z0;
    s16 w0;
    s16 x1;
    s16 y1;
    s16 z1;
    s16 w1;
} Vp800A62C4;

typedef struct {
    Vp800A62C4 *vp;
    u8 pad4[3];
    u8 idx;
    s32 frame;
    u16 left;
    u16 right;
    u16 bottom;
    u16 top;
    u16 x0;
    u16 x1;
    u16 y0;
    u16 y1;
} Obj800A62C4;

extern void func_800A61D8(Obj800A62C4 *, s32, s32, s32, s32);
typedef union {
    s32 w;
    struct {
        s16 hi;
        u16 lo;
    } h;
} Dim800A62C4;

extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F5664;

void func_800A62C4(Obj800A62C4 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Vp800A62C4 *vp;
    s32 t;
    u16 *hp;

    func_800A61D8(arg0, arg1, arg2, arg3, arg4);
    arg0->left = arg0->x0;
    if ((s16)arg0->left < 0) {
        arg0->left = 0;
    }
    arg0->right = arg0->x1;
    if ((s16)arg0->right > D_800F3294 - 1) {
        arg0->right = ((u16 *)&D_800F3294)[1] - 1;
    }
    arg0->top = arg0->y0;
    if ((s16)arg0->top < 0) {
        arg0->top = 0;
    }
    arg0->bottom = arg0->y1;
    if ((s16)arg0->bottom > D_800F3298 - 1) {
        arg0->bottom = ((u16 *)&D_800F3298)[1] - 1;
    }
    if (arg0->frame != D_800F5664) {
        arg0->idx ^= 1;
        arg0->frame = D_800F5664;
    }
    vp = &arg0->vp[arg0->idx];
    vp->x0 = (arg0->right - arg0->left) * 2;
    hp = &((u16 *)&D_800F3298)[1];
    vp->y0 = (arg0->bottom - arg0->top) * 2;
    vp->z0 = 0x1FF;
    vp->w0 = 0;
    vp->x1 = (arg0->left + (((s16)arg0->right - (s16)arg0->left) >> 1)) * 4;
    t = arg0->top + (((s16)arg0->bottom - (s16)arg0->top) >> 1);
    vp->y1 = (*hp - t) * 4;
    vp->z1 = 0x1FF;
    vp->w1 = 0;
}
