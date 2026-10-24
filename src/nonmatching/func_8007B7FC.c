/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 33/792 positional instructions; target 782. Aligned region
 * comparison pairs 305/782 equally. Frame/spills, induction variables, normal
 * setup and primitive-store scheduling differ after two focused attempts.
 * Started from the owner's Claude Z3 draft (func_8007B7FC_nearly.c).
 * Codex audited B830..B938 width/gates, B938..BAD8 normal fallback,
 * BAD8..BCF4 edge/segment gates, BCF4..BF2C all three sine paths,
 * BF2C..C078 buffer/twins/first OT link, C078..C2B8 every quad field,
 * C2B8..C400 the six remaining links and both loop continuations.
 * Big-endian byte +3 is the low byte: tags/codes/UV height retain that rule.
 * Products/packed XY/scroll/phase arithmetic explicitly retain 32-bit wrap.
 */
#include "common.h"

/* Scratchpad record per strip point (0x1C bytes at 0x1F800000). */
typedef struct {
    union {
        struct {
            s16 x;
            s16 y;
        } s;
        u32 w;
    } p;     /* 0x00 screen xy */
    s32 nx;  /* 0x04 normal (x) */
    s32 ny;  /* 0x08 normal (y) */
    s32 z;   /* 0x0C */
    s32 w0;  /* 0x10 half width, left side */
    s32 w1;  /* 0x14 half width, right side */
    s32 off; /* 0x18 point not drawable */
} Spad_8007B7FC;

typedef struct {
    u8 pad0[0xC];
    u32 colA;  /* 0x0C */
    u16 w0;    /* 0x10 */
    u16 w1;    /* 0x12 */
    u32 colB;  /* 0x14 */
    u8 pad18[0xC];
} Elem_8007B7FC;

typedef struct {
    u8 u;
    u8 v;
    u16 clut;
    u8 pad4[2];
    u16 tpage;
} Tex_8007B7FC;

typedef struct {
    u8 pad0[0x4C];
    Tex_8007B7FC *tex;   /* 0x4C */
    u8 hidden;           /* 0x50 */
    u8 pad51[3];
    s32 uScroll;         /* 0x54 */
    s32 vScroll;         /* 0x58 */
    s32 vStep;           /* 0x5C (low byte also the texture height) */
    s32 wobble;          /* 0x60 */
    s32 count;           /* 0x64 */
    Elem_8007B7FC *elems; /* 0x68 */
} Obj_8007B7FC;

typedef struct {
    u8 pad0[8];
    u16 unk8;
    u16 unkA;
} Inp_8007B7FC;

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect_8007B7FC;

/* Thirteen-word quad; the code byte is rgb0 byte +3 (target big endian). */
typedef struct {
    u32 tag;
    u32 rgb0;
    u32 xy0;
    u8 u0, v0;
    u16 clut;
    u32 rgb1;
    u32 xy1;
    u8 u1, v1;
    u16 tpage;
    u32 rgb2;
    u32 xy2;
    u8 u2, v2;
    u16 pad26;
    u32 rgb3;
    u32 xy3;
    u8 u3, v3;
    u16 pad32;
} PolyGT4_8007B7FC;

typedef struct {
    u32 tag;
    u32 code[2];
} DrTwin_8007B7FC;

typedef struct {
    u32 a;
    u32 b;
} Mode_8007B7FC;

typedef struct {
    PolyGT4_8007B7FC q[4];
    DrTwin_8007B7FC twin;   /* 0xD0: texture window for the strip */
    DrTwin_8007B7FC untwin; /* 0xDC: texture window reset */
    Mode_8007B7FC mode;     /* 0xE8 */
} Prims_8007B7FC;

f32 func_80001CA0(f32);
extern Inp_8007B7FC *D_800D8434;
extern u8 *D_800D0F9C;
extern u8 *D_800D0FA8;
extern u32 D_800DE9A4;
extern s32 D_800DE808;
extern Mode_8007B7FC D_800DE5E0;

#define SPAD ((Spad_8007B7FC *)0x1F800000)

#define SET_LEN(p, n) (((u8 *)(p))[3] = (n))
#define SET_CODE(q, c) (((u8 *)&(q)->rgb0)[3] = (c))
#define XY(x, y) (((u32)(x) << 16) | ((u32)(y) & 0xFFFF))

#define ADDPRIM(ot, p) do { \
    ((u32 *)(p))[0] = (*(ot) >> 8 << 8) | ((u8 *)(p))[3]; \
    *(ot) = ((u8 *)(ot))[3] | ((u32)(p) << 8); \
} while (0)

static inline s32 isin(s32 a) {
    if (a == 0) {
        return 0;
    }
    a %= 4096;
    return (s32)(func_80001CA0((f32)a * 0.000244140625f * 6.283185) * 4096.0f);
}

static inline void set_twin(DrTwin_8007B7FC *p, Rect_8007B7FC *r) {
    SET_LEN(p, 2);
    p->code[0] = 0xE2000000 | (((u8)r->y >> 3) << 15) | (((u8)r->x >> 3) << 10) | (((u32)-r->h << 2) & 0x3E0) |
                 (((-r->w) & 0xFF) >> 3);
    p->code[1] = 0;
}

void func_8007B7FC(Obj_8007B7FC *o) {
    Spad_8007B7FC *s;
    Spad_8007B7FC *cur;
    Spad_8007B7FC *prev;
    Elem_8007B7FC *e;
    Elem_8007B7FC *ec;
    Elem_8007B7FC *ep;
    Inp_8007B7FC *d;
    Prims_8007B7FC *p;
    Rect_8007B7FC tw;
    u32 *ot;
    s32 i;
    s32 dx, dy, len;
    s32 pnx, pny;
    s32 x, y, z;
    s32 a, b, c, k;
    s32 r;
    s32 v;
    u8 tu, tv;
    u32 xyA, xyB, xyC, xyD;
    u32 nxyA, nxyB, nxyC, nxyD;

    if (o->hidden != 0) {
        return;
    }

    /* per-point width from the element data */
    d = D_800D8434;
    e = o->elems;
    s = SPAD;
    for (i = 0; i < o->count; i++) {
        s->z = 1;
        if (1 < d->unk8 || d->unkA == 0) {
            s->off = 1;
        } else {
            s->off = 0;
            s->w0 = e->w0 * 400 / s->z;
            s->w1 = e->w1 * 400 / s->z;
        }
        s++;
        e++;
    }

    /* unit (x64) normal of each segment; a degenerate one keeps the previous normal */
    pnx = 0;
    pny = 0;
    s = SPAD;
    for (i = 0; i < o->count - 1; i++) {
        if (s->off != 0 || s[1].off != 0) {
            s->ny = 0;
            s->nx = 0;
        } else {
            dy = (s[1].p.s.y - s->p.s.y) * 320 / 512;
            dx = s[1].p.s.x - s->p.s.x;
            s->nx = dx;
            s->ny = -dy;
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
            if (len < 4) {
                s->ny = 0;
                s->nx = 0;
            } else {
                s->nx = (s->nx * 64) / len;
                s->ny = (s->ny * 64) / len;
                s->nx = (s->nx * 512) / 320;
            }
        }
        if (s->nx == 0 && s->ny == 0) {
            s->nx = pnx;
            s->ny = pny;
        }
        pnx = s->nx;
        pny = s->ny;
        s++;
    }
    s->nx = pnx;
    s->ny = pny;

    /* edge points of the first strip point */
    y = SPAD[0].p.s.y;
    x = SPAD[0].p.s.x;
    a = (s32)((u32)SPAD[0].nx * (u32)SPAD[0].w0) >> 6;
    b = (s32)((u32)SPAD[0].ny * (u32)SPAD[0].w0) >> 6;
    c = (s32)((u32)SPAD[0].nx * (u32)SPAD[0].w1) >> 6;
    k = (s32)((u32)SPAD[0].ny * (u32)SPAD[0].w1) >> 6;
    xyA = XY(x + b, y + a);
    xyB = XY(x - b, y - a);
    xyC = XY(x + k, y + c);
    xyD = XY(x - k, y - c);

    v = o->vScroll;
    e = o->elems;
    ec = e + 1;
    ep = e;
    cur = &SPAD[1];
    prev = &SPAD[0];
    for (i = 1; i < o->count; i++, prev++, cur++, ep++, ec++) {
        if ((cur->nx | cur->ny) == 0 || (prev->nx | prev->ny) == 0) {
            continue;
        }
        z = prev->z;
        if (cur->z < z) {
            z = cur->z;
        }
        ot = (u32 *)(*(u8 **)(D_800D0F9C + 0x808C) + (z & 0x3FFC));

        y = cur->p.s.y;
        x = cur->p.s.x;
        a = (s32)((u32)cur->nx * (u32)cur->w0) >> 6;
        b = (s32)((u32)cur->ny * (u32)cur->w0) >> 6;
        c = (s32)((u32)cur->nx * (u32)cur->w1) >> 6;
        k = (s32)((u32)cur->ny * (u32)cur->w1) >> 6;
        nxyA = XY(x + b, y + a);
        nxyB = XY(x - b, y - a);
        nxyC = XY(x + k, y + c);
        nxyD = XY(x - k, y - c);

        /* the far half of the strip wobbles */
        if (o->wobble != 0 && i >= o->count / 2) {
            r = isin((s32)((u32)D_800DE808 * 200u + 130u));
            nxyA = XY(x + b + r / 2048, y + a);
            r = isin((s32)((u32)D_800DE808 * 250u));
            x += r * 3 / 4096;
            cur->p.w = (u16)cur->p.s.y | ((u32)x << 16);
            r = isin((s32)((u32)D_800DE808 * 150u + 100u));
            nxyB = XY(x - b + r / 2048, y - a);
        }

        p = (Prims_8007B7FC *)D_800D0FA8;
        if (D_800DE9A4 < (u32)(p + 1)) {
            return;
        }
        D_800D0FA8 = (u8 *)(p + 1);

        tw.x = tw.y = tw.w = tw.h = 0;
        set_twin(&p->untwin, &tw);
        tw.x = o->tex->u;
        tw.y = o->tex->v;
        tw.w = 64;
        tw.h = 64;
        set_twin(&p->twin, &tw);
        ADDPRIM(ot, &p->untwin);

        p->q[3].tag = 0x0C000000;
        p->q[2].tag = 0x0C000000;
        p->q[1].tag = 0x0C000000;
        p->q[0].tag = 0x0C000000;
        p->q[3].clut = p->q[2].clut = p->q[1].clut = p->q[0].clut = o->tex->clut;
        p->q[3].tpage = p->q[2].tpage = p->q[1].tpage = p->q[0].tpage = o->tex->tpage;

        tu = o->tex->u + (o->uScroll & 0x3F);
        tv = o->tex->v + (v & 0x3F);
        p->q[2].u0 = tu;
        p->q[2].v0 = tv;
        p->q[2].u2 = tu + 0x10;
        p->q[2].v2 = tv;
        p->q[2].u1 = tu;
        p->q[2].v1 = ((u8 *)&o->vStep)[3] + tv;
        p->q[2].u3 = tu + 0x10;
        p->q[2].v3 = ((u8 *)&o->vStep)[3] + tv;
        p->q[0].u0 = tu + 0x10;
        p->q[0].v0 = tv;
        p->q[0].u2 = tu + 0x20;
        p->q[0].v2 = tv;
        p->q[0].u1 = tu + 0x10;
        p->q[0].v1 = ((u8 *)&o->vStep)[3] + tv;
        p->q[0].u3 = tu + 0x20;
        p->q[0].v3 = ((u8 *)&o->vStep)[3] + tv;
        p->q[1].u0 = tu + 0x30;
        p->q[1].v0 = tv;
        p->q[1].u2 = tu + 0x20;
        p->q[1].v2 = tv;
        p->q[1].u1 = tu + 0x30;
        p->q[1].v1 = ((u8 *)&o->vStep)[3] + tv;
        p->q[1].u3 = tu + 0x20;
        p->q[1].v3 = ((u8 *)&o->vStep)[3] + tv;
        p->q[3].u0 = tu + 0x40;
        p->q[3].v0 = tv;
        p->q[3].u2 = tu + 0x30;
        p->q[3].v2 = tv;
        p->q[3].u1 = tu + 0x40;
        p->q[3].v1 = ((u8 *)&o->vStep)[3] + tv;
        p->q[3].u3 = tu + 0x30;
        p->q[3].v3 = ((u8 *)&o->vStep)[3] + tv;
        v = (s32)((u32)v - (u32)o->vStep);

        /* q0/q1: the strip between the two points (left/right edge), q2/q3: the outer fade-out band */
        p->q[0].rgb0 = ec->colB;
        p->q[0].rgb1 = ep->colB;
        p->q[0].rgb2 = ec->colA;
        p->q[0].rgb3 = ep->colA;
        p->q[0].xy0 = nxyA;
        p->q[0].xy1 = xyA;
        p->q[0].xy2 = cur->p.w;
        p->q[0].xy3 = prev->p.w;
        p->q[2].rgb0 = 0;
        p->q[2].rgb1 = 0;
        p->q[2].rgb2 = ec->colB;
        p->q[2].rgb3 = ep->colB;
        p->q[2].xy0 = nxyC;
        p->q[2].xy1 = xyC;
        p->q[2].xy2 = nxyA;
        p->q[2].xy3 = xyA;
        p->q[1].rgb0 = ec->colB;
        p->q[1].rgb1 = ep->colB;
        p->q[1].rgb2 = ec->colA;
        p->q[1].rgb3 = ep->colA;
        p->q[1].xy0 = nxyB;
        p->q[1].xy1 = xyB;
        p->q[1].xy2 = cur->p.w;
        p->q[1].xy3 = prev->p.w;
        p->q[3].rgb0 = 0;
        p->q[3].rgb1 = 0;
        p->q[3].rgb2 = ec->colB;
        p->q[3].rgb3 = ep->colB;
        p->q[3].xy0 = nxyD;
        p->q[3].xy1 = xyD;
        p->q[3].xy2 = nxyB;
        p->q[3].xy3 = xyB;
        SET_CODE(&p->q[3], 0x3E);
        SET_CODE(&p->q[2], 0x3E);
        SET_CODE(&p->q[1], 0x3E);
        SET_CODE(&p->q[0], 0x3E);

        ADDPRIM(ot, &p->q[0]);
        ADDPRIM(ot, &p->q[2]);
        ADDPRIM(ot, &p->q[1]);
        ADDPRIM(ot, &p->q[3]);
        ADDPRIM(ot, &p->twin);
        p->mode = D_800DE5E0;
        ADDPRIM(ot, &p->mode);

        xyA = nxyA;
        xyB = nxyB;
        xyC = nxyC;
        xyD = nxyD;
    }
}
