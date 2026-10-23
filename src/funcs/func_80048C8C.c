#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec80048C8C;

typedef struct {
    u8 pad0[8];
    s16 off8;
    u8 padA[2];
    void (*fnC)(void *, s32);
    s16 off10;
    u8 pad12[2];
    void (*fn14)(void *);
} Vt80048C8C;

typedef struct Obj80048C8C {
    u8 pad0[4];
    Vec80048C8C pos;
    u8 pad10[0x1C - 0x10];
    struct Obj80048C8C *next;
    u8 pad20[0x48 - 0x20];
    Vt80048C8C *vt;
} Obj80048C8C;

s32 func_8004AEE0(Obj80048C8C *);

s32 func_80048C8C(Vec80048C8C *lo, Vec80048C8C *hi, Obj80048C8C *p, s32 arg3) {
    Vec80048C8C v;
    s32 n;
    Obj80048C8C *next;

    n = 0;
loop:
    if (p != NULL) {
        next = p->next;
        if (func_8004AEE0(p) != 0) {
            p = next;
            goto loop;
        }
        v = p->pos;
        if (v.x < lo->x || hi->x < v.x || v.z < lo->z || hi->z < v.z || v.y < lo->y || hi->y < v.y) {
            p = next;
            goto loop;
        }
        if (arg3 != 0) {
            p->vt->fn14((u8 *)p + p->vt->off10);
            n++;
        } else {
            p->vt->fnC((u8 *)p + p->vt->off8, 3);
            n++;
        }
        p = next;
        goto loop;
    }
    return n;
}
