#include "common.h"

typedef struct Obj49814 {
    u8 pad0[0x4];
    s32 pos[3];
    u8 pad10[0x1C - 0x10];
    struct Obj49814 *next;
    u8 pad20[0x50 - 0x20];
    u16 flags50;
    u16 flags52;
    u8 pad54[0x168 - 0x54];
    u8 unk168;
} Obj49814;

s32 func_80047D40(s16 *, s32, s32 *);

Obj49814 *func_80049814(s32 arg0, s16 *arg1, Obj49814 *obj, s32 maxDist, s32 maxAng, u16 mask) {
    s16 ang[4];
    s32 t;
    Obj49814 *best;
    s32 dist;
    s32 d;
    u16 f;

    best = NULL;
loop:
    if (obj != NULL) {
        f = obj->flags52;
        if (!(f & 0x40)) {
            if (f & 0x10) {
                if (obj->unk168 == 0) {
                    dist = func_80047D40(ang, arg0, obj->pos);
                    if (dist < 400) {
                        return obj;
                    }
                    t = ang[1];
                    d = t - arg1[1];
                    if (d < -0x800) {
                        d += 0x1000;
                    }
                    if (d > 0x800) {
                        d -= 0x1000;
                    }
                    if (d < 0) {
                        d = -d;
                    }
                    if (d < maxAng && dist < maxDist && !(obj->flags50 & mask)) {
                        maxAng = d;
                        best = obj;
                    }
                }
            }
        }
        obj = obj->next;
        goto loop;
    }
    if (best != NULL) {
        return best;
    }
    return NULL;
}
