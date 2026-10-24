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

s32 func_800B713C(Chunk *, s32);
void func_800B7160(Chunk *, s32);
typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B6E3C;

extern Gfx800B6E3C *D_800F36A4;

static __inline__ s32 *read_(Chunk *c, s32 base) {
    func_800B7160(c, base);
    return (s32 *)(c->base + func_800B713C(c, 0));
}

static __inline__ s32 addr_(Chunk *c) {
    return c->base + func_800B713C(c, 1);
}

void func_800B6E3C(ChunkList *arg0, s32 arg1) {
    Chunk a;
    Chunk b;
    Chunk c;
    Chunk *pa;
    s32 all;
    s32 i;
    s32 j;
    s32 n;
    s32 flags;
    s32 addr;

    i = 0;
    all = -1;
    pa = &a;
    while (1) {
        if (i >= arg0->count) break;
        if (arg1 != all) {
            i = arg1;
        }
        func_800B7160(pa, arg0->items[i]);
        func_800B7160(&b, pa->base + func_800B713C(pa, 1));
        j = 0;
        n = *b.hdr;
        while (1) {
            if (j >= n) break;
            flags = read_(&c, b.base + func_800B713C(&b, j))[1];
            if (flags & 0x8000) {
                goto next;
            }
            if (flags & 0x800) {
                goto next;
            }
            addr = addr_(&c);
            {
                Gfx800B6E3C *_g = D_800F36A4++;
                _g->w0 = 0xDE000000;
                _g->w1 = addr;
            }
        next:
            j++;
        }
        i++;
        if (arg1 != all) break;
    }
}
