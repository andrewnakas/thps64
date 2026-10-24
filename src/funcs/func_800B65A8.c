/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *hdr;
    s32 base;
} Chunk;

typedef struct {
    s32 *items;
    s32 count;
} ChunkList;

typedef struct {
    u8 pad[0x66];
    u16 id;
} Def;

typedef struct {
    u8 pad[4];
    Def *def;
} Inst;

typedef struct {
    Inst *inst;
    s32 flags;
} Ent;

s32 func_800B713C(Chunk *, s32);
void func_800B7160(Chunk *, s32);
Inst *func_800BAB04(void *, s32);
void func_800BABE0(void *, Inst *);
extern u8 D_800EECF0[];

static __inline__ Ent *read_(Chunk *c, s32 base) {
    func_800B7160(c, base);
    return (Ent *)(c->base + func_800B713C(c, 0));
}

void func_800B65A8(ChunkList *arg0, s32 id, s32 arg2, s32 sel) {
    Chunk a;
    Chunk b;
    Chunk c;
    Chunk *pa;
    s32 all;
    s32 i;
    s32 j;
    s32 n;
    Ent *e;

    i = 0;
    all = -1;
    pa = &a;
    while (1) {
        if (i >= arg0->count) break;
        if (i != sel && sel != all) {
            goto next_i;
        }
        func_800B7160(pa, arg0->items[i]);
        func_800B7160(&b, pa->base + func_800B713C(pa, 1));
        j = 0;
        n = *b.hdr;
        while (1) {
            if (j >= n) break;
            e = read_(&c, b.base + func_800B713C(&b, j));
            if (id == -1) {
                if (e->flags & 1) {
                    goto next;
                }
                e->flags |= 1;
                e->inst = func_800BAB04(D_800EECF0, arg2);
            } else {
                if (!(e->flags & 1)) {
                    goto next;
                }
                if (e->inst == NULL) {
                    goto next;
                }
                if (e->inst->def->id != id) {
                    goto next;
                }
                func_800BABE0(D_800EECF0, e->inst);
                e->inst = func_800BAB04(D_800EECF0, arg2);
            }
        next:
            j++;
        }
    next_i:
        i++;
    }
}
