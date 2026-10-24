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

static __inline__ s32 *read_(Chunk *c, s32 base) {
    func_800B7160(c, base);
    return (s32 *)(c->base + func_800B713C(c, 0));
}

static __inline__ u8 *addr_(Chunk *c) {
    return (u8 *)(c->base + func_800B713C(c, 1));
}

void func_800B6758(ChunkList *arg0) {
    Chunk a;
    Chunk t;
    Chunk b;
    Chunk c;
    Chunk *pa;
    s32 i;
    s32 j;
    s32 n;
    s32 off;
    u8 *p;
    s32 *q;
    u8 op;

    i = 0;
    pa = &a;
    while (1) {
        if (i >= arg0->count) break;
        func_800B7160(pa, arg0->items[i]);
        off = 0;
        t.base = pa->base + func_800B713C(pa, 2);
        t.hdr = (s32 *)(t.base + 8);
        func_800B7160(&b, pa->base + func_800B713C(pa, 1));
        j = 0;
        n = *b.hdr;
        while (1) {
            if (j >= n) break;
            if (read_(&c, b.base + func_800B713C(&b, j))[1] & 0x8000) {
                j++;
            } else {
                p = addr_(&c);
                q = (s32 *)(p + 4);
                do {
                    op = *p;
                    if (op == 1) {
                        s32 k = off * 16;
                        off += *q;
                        *q = (s32)t.hdr + k;
                    }
                    q += 2;
                    p += 8;
                } while (op != 0xDF);
                j++;
            }
        }
        i++;
    }
}
