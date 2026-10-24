/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s16 x, y, z;
} SVec495B4;

typedef struct {
    s32 x, y, z;
} IVec495B4;

typedef struct Obj495B4 {
    u8 pad0[4];
    IVec495B4 pos;
    u8 pad10[0xC];
    struct Obj495B4 *next;
    u8 pad20[0x50 - 0x20];
    u16 unk50;
    u16 unk52;
    u8 pad54[0x84 - 0x54];
    u8 unk84[0x168 - 0x84];
    u8 unk168;
} Obj495B4;

void func_80046F58(IVec495B4 *, void *, s32 *);
void func_80047014(IVec495B4 *, IVec495B4 *, IVec495B4 *);
s32 func_80047D40(SVec495B4 *, s32, IVec495B4 *);

Obj495B4 *func_800495B4(SVec495B4 *out, s32 arg1, SVec495B4 *ref, s32 maxd, s32 limy, s32 limx, s32 arg6, u16 mask,
                        Obj495B4 *o) {
    SVec495B4 rot;
    IVec495B4 v1;
    IVec495B4 v2;
    Obj495B4 *found;
    s32 best;
    s32 d;
    s32 a;
    u16 f;
    IVec495B4 *pv;

    found = NULL;
    best = 1000000;
    while (1) {
        if (o == NULL) {
            break;
        }
        if (!(o->unk50 & mask) && !((f = o->unk52) & 0x40) && (f & 0x10) && o->unk168 == 0) {
            pv = &v1;
            func_80046F58(&v2, o->unk84, &arg6);
            func_80047014(pv, &o->pos, &v2);
            d = func_80047D40(&rot, arg1, &v1);
            if (d <= maxd) {
                a = rot.y - ref->y;
                if (a < -0x800) {
                    a += 0x1000;
                }
                if (a > 0x800) {
                    a -= 0x1000;
                }
                if (a < 0) {
                    a = -a;
                }
                if (maxd > 0) {
                    a += ((a * d) << 4) / maxd;
                }
                if (a <= limy) {
                    a = rot.x - ref->x;
                    if (a < -0x800) {
                        a += 0x1000;
                    }
                    if (a > 0x800) {
                        a -= 0x1000;
                    }
                    if (a < 0) {
                        a = -a;
                    }
                    if (maxd > 0) {
                        a += ((a * d) << 4) / maxd;
                    }
                    if (a <= limx && d < best) {
                        found = o;
                        best = d;
                        *out = rot;
                    }
                }
            }
        }
        o = o->next;
    }
    if (found == NULL) {
        *out = *ref;
    }
    return found;
}
