/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 135/503 positional instructions agree (target499); scratchpad-load forms, saved registers and primitive scheduling differ. Unused frame-padding array removed. */
#include "common.h"

typedef struct {
    union {
        struct {
            s16 x;
            s16 y;
        } s;
        u32 w;
    } p;
    s32 nx;
    s32 ny;
    s32 z;
    s32 width;
    s32 unk14;
    s32 flag;
} Spad_8007AF68;

typedef struct {
    u8 pad0[0xC];
    u32 col;
    u16 unk10;
    u8 pad12[6];
    u32 unk18;
    u32 unk1C;
    u8 pad20[4];
} Elem_8007AF68;

typedef struct {
    u8 pad0[0x40];
    u16 unk40;
    u8 pad42[6];
    s32 unk48;
    s32 unk4C;
    Elem_8007AF68 *unk50;
} Obj_8007AF68;

typedef struct {
    u8 pad0[8];
    u16 unk8;
    u16 unkA;
} Inp_8007AF68;

typedef struct {
    u32 tag;
    u32 rgbc0;
    u32 xy0;
    u32 rgb1;
    u32 xy1;
    u32 rgb2;
    u32 xy2;
    u32 rgb3;
    u32 xy3;
} PolyG4_8007AF68;

typedef struct {
    u32 a;
    u32 b;
} Mode_8007AF68;

typedef struct {
    PolyG4_8007AF68 q0;
    PolyG4_8007AF68 q1;
    Mode_8007AF68 mode;
    PolyG4_8007AF68 q2;
} Prims_8007AF68;


extern Inp_8007AF68 *D_800D8434;
extern u8 *D_800D0F9C;
extern u8 *D_800D0FA8;
extern u32 D_800DE9A4;
extern Mode_8007AF68 D_800DE5E0;

#define SPAD ((Spad_8007AF68 *)0x1F800000)

#define ADDPRIM(ot, p) \
    ((u32 *)(p))[0] = (*(ot) >> 8 << 8) | ((u8 *)(p))[3]; \
    *(ot) = ((u8 *)(ot))[3] | ((u32)(p) << 8)

static inline void calc(Spad_8007AF68 *a, Spad_8007AF68 *b, s32 *px, s32 *py) {
    s32 dx;
    s32 dy;
    s32 len;
    s32 ax;
    s32 ay;
    s32 bx;
    s32 by;

    if (a->flag != 0 || b->flag != 0) {
        *py = 0;
        *px = 0;
    } else {
        ay = a->p.s.y;
        ax = a->p.s.x;
        by = b->p.s.y;
        bx = b->p.s.x;
        dy = (by - ay) * 320 / 512;
        dx = bx - ax;
        *px = dx;
        *py = -dy;
        if (dy < 0) {
            dy = -dy;
        }
        if (dx < 0) {
            dx = -dx;
        }
        if (dx < dy) {
            len = dy + dx / 2;
        } else {
            len = dx + dy / 2;
        }
        if (len >= 2) {
            *px = *px * 64 / len;
            *py = *py * 64 / len;
            *px = (*px << 9) / 320;
        } else {
            *py = 0;
            *px = 0;
        }
    }
}

void func_8007AF68(Obj_8007AF68 *o) {
    s32 i;
    s32 n;
    s32 *px;
    s32 *py;
    Spad_8007AF68 *s;
    Spad_8007AF68 *cur;
    Spad_8007AF68 *prev;
    Inp_8007AF68 *d;
    Elem_8007AF68 *e;
    Elem_8007AF68 *ec;
    Elem_8007AF68 *ep;
    s32 v[2];
    s32 w[2];
    u32 xy0;
    u32 xy1;
    u32 nxy0;
    u32 nxy1;
    s32 ox;
    s32 oy;
    s32 t;
    u32 lim;
    s32 x;
    s32 y;
    u32 *ot;
    Prims_8007AF68 *p;
    PolyG4_8007AF68 *p1;
    Mode_8007AF68 *dm;

    e = o->unk50;
    i = 0;
    n = 1;
    d = D_800D8434;
    s = SPAD;
    while (1) {
        if (i >= o->unk4C) {
            break;
        }
        s->z = n;
        if (n < d->unk8 || d->unkA == 0) {
            s->flag = n;
        } else {
            s->flag = 0;
            s->width = e->unk10 * 400 / s->z;
        }
        s++;
        e++;
        i++;
    }
    s = SPAD;
    px = &v[0];
    py = &v[1];
    calc(s, s + 1, px, py);
    s->nx = v[0];
    s->ny = v[1];
    s++;
    i = 1;
    while (1) {
        if (i >= o->unk4C - 1) {
            break;
        }
        px = &w[0];
        py = &w[1];
        calc(s, s + 1, px, py);
        s->nx = (w[0] + v[0]) / 2;
        s->ny = (w[1] + v[1]) / 2;
        v[0] = w[0];
        v[1] = w[1];
        s++;
        i++;
    }
    s->nx = v[0];
    s->ny = v[1];

    e = o->unk50;
    y = SPAD[0].p.s.y;
    x = SPAD[0].p.s.x;
    t = SPAD[0].nx * SPAD[0].width;
    oy = t >> 6;
    t = SPAD[0].ny * SPAD[0].width;
    ox = t >> 6;
    xy0 = ((x + ox) << 16) | ((y + oy) & 0xFFFF);
    xy1 = ((x - ox) << 16) | ((y - oy) & 0xFFFF);
    cur = &SPAD[1];
    prev = &SPAD[0];
    ec = e + 1;
    ep = e;
    i = 1;
    while (1) {
        if (i >= o->unk4C) {
            break;
        }
        if ((cur->nx | cur->ny) != 0 && (prev->nx | prev->ny) != 0) {
            ot = (u32 *)(*(u8 **)(D_800D0F9C + 0x808C) + ((cur->z - o->unk40) & 0x3FFC));
            y = cur->p.s.y;
            x = cur->p.s.x;
            t = cur->nx * cur->width;
            oy = t >> 6;
            t = cur->ny * cur->width;
            ox = t >> 6;
            nxy0 = ((x + ox) << 16) | ((y + oy) & 0xFFFF);
            nxy1 = ((x - ox) << 16) | ((y - oy) & 0xFFFF);
            p = (Prims_8007AF68 *)D_800D0FA8;
            p1 = &p->q1;
            dm = &p->mode;
            lim = D_800DE9A4;
            if (lim < (u32)&p->q2) {
                break;
            }
            D_800D0FA8 = (u8 *)&p->q2;
            *dm = D_800DE5E0;
            if (o->unk48 >= 3) {
                if (lim < (u32)(p + 1)) {
                    break;
                }
                D_800D0FA8 = (u8 *)(p + 1);
                p->q2.tag = 0x8000000;
                p->q2.rgbc0 = 0x3A000000;
                p->q2.rgb1 = 0;
                p->q2.rgb3 = ep->col;
                p->q2.rgb2 = ec->col;
                p->q2.xy1 = ep->unk1C;
                p->q2.xy0 = ec->unk1C;
                p->q2.xy3 = prev->p.w;
                p->q2.xy2 = cur->p.w;
                ADDPRIM(ot, &p->q2);
            }
            p1->tag = 0x8000000;
            p->q0.tag = 0x8000000;
            p1->rgbc0 = 0x3A000000;
            p->q0.rgbc0 = 0x3A000000;
            p->q0.rgb1 = 0;
            p->q0.rgb3 = ep->col;
            p->q0.rgb2 = ec->col;
            p->q0.xy0 = nxy0;
            p->q0.xy1 = xy0;
            p->q0.xy2 = cur->p.w;
            p->q0.xy3 = prev->p.w;
            ADDPRIM(ot, p);
            p1->rgb1 = 0;
            p1->rgb3 = ep->col;
            p1->rgb2 = ec->col;
            p1->xy0 = nxy1;
            p1->xy1 = xy1;
            p1->xy2 = cur->p.w;
            p1->xy3 = prev->p.w;
            ADDPRIM(ot, p1);
            ADDPRIM(ot, dm);
            xy0 = nxy0;
            xy1 = nxy1;
        }
        prev++;
        cur++;
        ep++;
        ec++;
        i++;
    }
    if (o->unk48 != 0) {
        e = o->unk50;
        s = SPAD;
        for (i = 0; i < o->unk4C; i++) {
            if (o->unk48 == 1) {
                e->unk18 = s->p.w;
                e->unk1C = s->p.w;
            } else {
                e->unk1C = e->unk18;
                e->unk18 = s->p.w;
            }
            e++;
            s++;
        }
        o->unk48++;
    }
}
