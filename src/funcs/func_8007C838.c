/* cflags: -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    u8 pad0[0x48];
    s16 unk48;
    u8 pad4A[2];
    s32 color;
} Elem_8007C838;

typedef struct {
    u8 pad0[0x44];
    s32 *vt;
    s32 count;
    u8 pad4C[0x10];
    Elem_8007C838 **elems;
} Obj_8007C838;

void func_8007A9E8(Obj_8007C838 *, s32, s32, s32, s32 *, s32 *, s32, s32);
extern s32 D_8001E0EC;
extern s32 D_8001E140;

Obj_8007C838 *func_8007C838(Obj_8007C838 *o, s32 arg1, s32 arg2, s32 r0, s32 g0, s32 b0) {
    s32 dr, dg, db;
    s32 i;
    s32 k;
    s32 j;
    Elem_8007C838 **e;
    Elem_8007C838 **base;
    s32 cr, cg, cb;
    s32 r, g, b;

    func_8007A9E8(o, arg1, arg2, 2, &D_8001E0EC, &D_8001E0EC, 0x190, 1);
    o->vt = &D_8001E140;
    r = r0;
    g = g0;
    b = b0;
    dr = r / o->count;
    dg = g / o->count;
    db = b / o->count;
    i = 0;
    while (1) {
        if (i >= o->count) break;
        j = i + 1;
        k = o->count - j;
        base = o->elems;
        e = (Elem_8007C838 **)(i * 4 + (s32)base);
        cr = r - k * dr;
        cg = g - k * dg;
        cb = b - k * db;
        (*e)->color = ((*e)->color & 0xFF000000) | ((cb & 0xFF) << 16) | ((cg & 0xFF) << 8) | (cr & 0xFF);
        o->elems[i]->unk48 = 8;
        i = j;
    }
    return o;
}
