/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)();
} VEnt_8004A89C;

typedef struct Obj_8004A89C {
    u16 flags;
    u16 pad2;
    u8 pos[0x1C - 4];
    struct Obj_8004A89C *next;
    u32 color;
    u8 pad24[0x30 - 0x24];
    struct Obj_8004A89C *prev;
    u32 color2;
    u8 pad38[0x40 - 0x38];
    u16 fade;
    s16 dr;
    s16 dg;
    s16 db;
    VEnt_8004A89C *vt;
    struct Obj_8004A89C **owner;
    u16 pad50;
    u16 flags52;
} Obj_8004A89C;

u32 func_80047C34(void *, void *);
void func_8004A544(Obj_8004A89C *);
void func_8004B0BC(Obj_8004A89C *);
extern Obj_8004A89C *D_800D6184;
extern u32 D_800D619C;
extern u8 *D_800D61A8;
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;

void func_8004A89C(Obj_8004A89C **arg0) {
    Obj_8004A89C *p;
    Obj_8004A89C *next;
    Obj_8004A89C *t;
    u32 c;
    u32 d;
    u32 d2;
    u16 f;
    s32 r, g, b;

    p = *arg0;
    if (p != NULL) {
        next = p->next;
    }
    while (1) {
        if (p == NULL) {
            break;
        }
        if (p->fade != 0) {
            p->flags |= 0x400;
            c = p->color;
            r = c & 0xFF;
            g = (c >> 8) & 0xFF;
            b = (c >> 16) & 0xFF;
            r += p->dr;
            g += p->dg;
            b += p->db;
            p->color = (b & 0xFF) << 16 | (g & 0xFF) << 8 | (r & 0xFF);
            if (--p->fade == 0) {
                if (p->color2 & 0x2000000) {
                    p->flags |= 0x400;
                } else {
                    p->flags &= ~0x400;
                }
                p->color = p->color2;
                p->color2 = 0;
            }
        }
        f = p->flags52;
        if (f & 0x40) {
            if (f & 0x80) {
                if (p != NULL) {
                    p->vt[1].fn((u8 *)p + p->vt[1].delta, 3);
                }
            } else {
                p->flags52 = f | 0x80;
            }
        } else {
            d = func_80047C34(D_800D61A8 + 4, p->pos);
            if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
                d2 = func_80047C34(*(u8 **)(D_800D61A8 + 0x1C) + 4, p->pos);
                if (d2 < d) {
                    d = d2;
                }
            }
            *(u32 *)((u8 *)p + 0x164) = d;
            if ((p->flags52 & 2) && D_800D619C < d) {
                p->vt[7].fn((u8 *)p + p->vt[7].delta);
                p->owner = arg0;
                if ((p->flags52 & 1) && arg0 != &D_800D6184) {
                    func_8004B0BC(p);
                }
                if (p->next != NULL) {
                    p->next->prev = p->prev;
                }
                if (p->prev != NULL) {
                    p->prev->next = p->next;
                }
                if (*arg0 == p) {
                    *arg0 = p->next;
                }
                t = D_800D6184;
                p->next = t;
                p->prev = NULL;
                D_800D6184 = p;
                if (t != NULL) {
                    t->prev = p;
                }
                p->flags52 |= 1;
            } else {
                func_8004A544(p);
                *(s32 *)((u8 *)p + 0x14C) = 0;
            }
        }
        p = next;
        if (next == NULL) {
            break;
        }
        next = next->next;
    }
}
