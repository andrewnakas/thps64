/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *hdr;
    u8 *base;
} Chunk_800B5210;

typedef struct {
    u8 **items;
    s32 count;
} Model_800B5210;

typedef struct EntB_800B5210 {
    u8 *addr;
    s32 v;
    struct EntB_800B5210 *next;
} EntB_800B5210;

typedef struct Tex_800B5210 {
    struct Tex_800B5210 *self;
    EntB_800B5210 *head;
    EntB_800B5210 *tail;
    s32 used;
    struct Tex_800B5210 *next;
    u32 flags;
    u8 pad18[0x4F - 0x18];
    u8 unk4F;
    u8 pad50[0x5C - 0x50];
    s32 unk5C;
} Tex_800B5210;

typedef struct {
    Tex_800B5210 **tex;
    u32 flags;
} Mat_800B5210;

typedef struct {
    s32 v;
    Tex_800B5210 *t;
    u8 *addr;
    u32 flags;
} EntA_800B5210;

typedef struct {
    u8 pad0[0x40];
    s32 vals[16];
    s32 nvals;
    Tex_800B5210 *list84;
    Tex_800B5210 *list88;
    EntB_800B5210 eb[0x200];
    s32 neb;
    Model_800B5210 *model;
    s32 sel;
    EntA_800B5210 ea[0x40];
    s32 nea;
} Obj_800B5210;

s32 func_800B713C(Chunk_800B5210 *, s32);
void func_800B7160(Chunk_800B5210 *, u8 *);
void func_800B4AD8(Obj_800B5210 *, Chunk_800B5210 *);
extern s32 D_800EEC88;
extern s32 D_800EEC8C;

static __inline__ Mat_800B5210 *read_(Chunk_800B5210 *c, u8 *base) {
    func_800B7160(c, base);
    return (Mat_800B5210 *)(c->base + func_800B713C(c, 0));
}

static __inline__ u8 *addr_(Chunk_800B5210 *c) {
    return c->base + func_800B713C(c, 1);
}

static __inline__ void addA_(Obj_800B5210 *o, Tex_800B5210 *t, u8 *addr, Mat_800B5210 *mat) {
    s32 k;

    k = 0;
    while (1) {
        s32 idx;
        s32 *vp;
        s32 v;
        EntA_800B5210 *e;
        if (k >= o->nvals) {
            break;
        }
        idx = o->nea;
        vp = &o->vals[k];
        if (idx == 0x40) {
            return;
        }
        o->nea = idx + 1;
        e = &o->ea[idx];
        v = *vp;
        e->t = t;
        e->addr = addr;
        e->v = v;
        e->flags = mat->flags;
        k++;
    }
}

static __inline__ void addB_(Obj_800B5210 *o, Tex_800B5210 *tex, u8 *addr, Mat_800B5210 *mat, s32 skip) {
    Tex_800B5210 *t = tex;
    s32 k;

    if (t->used == 0) {
        t->used = 1;
        t->tail = NULL;
        t->head = NULL;
        t->self = t;
        t->flags = mat->flags;
        if (t->unk4F != 0) {
            t->next = o->list88;
            o->list88 = t;
        } else {
            t->next = o->list84;
            o->list84 = t;
        }
    }
    if (skip != 0) {
        return;
    }
    k = 0;
    while (1) {
        s32 idx;
        s32 *vp;
        EntB_800B5210 *e;
        if (k >= o->nvals) {
            break;
        }
        idx = o->neb;
        vp = &o->vals[k];
        if (idx == 0x200) {
            return;
        }
        o->neb = idx + 1;
        e = &o->eb[idx];
        e->addr = addr;
        e->v = *vp;
        e->next = NULL;
        if (t->tail != NULL) {
            t->tail->next = e;
        } else {
            t->head = e;
        }
        t->tail = e;
        k++;
    }
}

void func_800B5210(Obj_800B5210 *o) {
    Chunk_800B5210 c0;
    Chunk_800B5210 c1;
    Chunk_800B5210 c2;
    Chunk_800B5210 *pc0;
    s32 i;
    s32 j;
    s32 n;
    s32 skip;
    Mat_800B5210 *mat;
    u32 fl;
    Tex_800B5210 **tp;
    Tex_800B5210 *t;
    u8 *addr;

    if (o->nvals == 0) {
        return;
    }
    skip = 0;
    if (D_800EEC8C != 0 || D_800EEC88 != 0) {
        skip = 1;
    }
    i = 0;
    pc0 = &c0;
    while (1) {
        if (i >= o->model->count) {
            break;
        }
        if (o->sel != -1) {
            i = o->sel;
        }
        func_800B7160(pc0, o->model->items[i]);
        func_800B7160(&c1, pc0->base + func_800B713C(pc0, 1));
        j = 0;
        n = *c1.hdr;
        while (1) {
            if (j >= n) break;
            mat = read_(&c2, c1.base + func_800B713C(&c1, j));
            fl = mat->flags;
            if (fl & 0x800) {
                goto next;
            }
            if (fl & 0x8000) {
                func_800B4AD8(o, &c2);
                goto next;
            }
            if (fl & 1) {
                tp = mat->tex;
                if (tp == NULL) {
                    goto next;
                }
                addr = addr_(&c2);
                t = tp[1];
                if ((t->unk5C & 3) == 3 && t->unk4F == 0) {
                    addA_(o, t, addr, mat);
                } else {
                    addB_(o, t, addr, mat, skip);
                }
            } else {
                addA_(o, NULL, addr_(&c2), mat);
            }
        next:
            j++;
        }
        i++;
        if (o->sel != -1) break;
    }
    o->nvals = 0;
}
