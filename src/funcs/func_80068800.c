/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef union {
    struct {
        s32 x, y, z, w;
    } v;
    struct {
        s16 a, b, c, d;
    } h;
} U80068800;

typedef struct N80068800 {
    s32 id;
    s32 min[3];
    s32 max[3];
    struct N80068800 *next;
    struct N80068800 *prev;
    s32 unk24;
} N80068800;

U80068800 *func_800617B8(U80068800 *, s32);
u16 *func_80061904(s32);
extern s16 **D_800DACB0;
extern N80068800 *D_800DC5C0;

N80068800 *func_80068800(N80068800 *arg0, s32 arg1) {
    U80068800 tmp;
    U80068800 r;
    s16 t;
    u16 *p;

    if (D_800DC5C0 != NULL) {
        D_800DC5C0->next = arg0;
    }
    arg0->prev = D_800DC5C0;
    arg0->next = NULL;
    D_800DC5C0 = arg0;
    func_80061904(arg1);
    arg0->id = arg1;
    t = func_800617B8(&tmp, arg1)->h.d;
    if (t == -1) {
        arg0->unk24 = 0;
    } else {
        arg0->unk24 = t;
    }
    arg0->min[0] = arg0->min[1] = arg0->min[2] = 0x7FFFFFFF;
    arg0->max[0] = arg0->max[1] = arg0->max[2] = 0x80000000;
    arg1 = arg0->id;
loop:
    {
        func_800617B8(&r, arg1);
        if (r.v.x < arg0->min[0]) {
            arg0->min[0] = r.v.x;
        }
        if (r.v.y < arg0->min[1]) {
            arg0->min[1] = r.v.y;
        }
        if (r.v.z < arg0->min[2]) {
            arg0->min[2] = r.v.z;
        }
        if (r.v.x > arg0->max[0]) {
            arg0->max[0] = r.v.x;
        }
        if (r.v.y > arg0->max[1]) {
            arg0->max[1] = r.v.y;
        }
        if (r.v.z > arg0->max[2]) {
            arg0->max[2] = r.v.z;
        }
        p = func_80061904(arg1);
        if (p[0] != 0) {
            s32 n;
            u16 m;
            if (p[-1] == 11) {
                m = p[1];
                if (*D_800DACB0[m] != 10) {
                    n = p[2];
                } else {
                    n = m;
                }
            } else {
                n = p[1];
            }
            arg1 = (u16)n;
            goto loop;
        }
    }
    return arg0;
}
