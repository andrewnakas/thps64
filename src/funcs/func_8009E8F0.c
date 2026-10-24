/* cflags: -O2 */
#include "common.h"

typedef struct Blk8009E8F0 {
    struct Blk8009E8F0 *prev;
    struct Blk8009E8F0 *next;
    struct Blk8009E8F0 *pprev;
    struct Blk8009E8F0 *pnext;
    u32 size;
    u32 free;
    s32 tag;
} Blk8009E8F0;

typedef struct {
    Blk8009E8F0 *head;
    Blk8009E8F0 *tail;
    s32 pad8;
    s32 debug;
    u32 minFail;
    s32 mutex;
    s32 tag;
} Heap8009E8F0;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);
extern void func_8009E0F0(void *, s32, s32);
extern void func_8009EEDC(Heap8009E8F0 *, void *, void *);

void *func_8009E8F0(Heap8009E8F0 *heap, s32 size, u32 align) {
    struct {
        s32 m;
        s32 a;
        s32 b;
    } st;
    Blk8009E8F0 *b;
    Blk8009E8F0 *n;
    Blk8009E8F0 *t;
    u32 pad;
    void *p;

    st.m = heap->mutex;
    func_80005070(st.m, 0, 1);
    size = (size + 0x1F) & ~3;
    if ((u32)size < heap->minFail || heap->minFail == (u32)-1) {
        b = heap->tail;
    loop:
        if (b != NULL) {
            if (b->free >= (u32)size) {
                if (align >= 5) {
                    pad = ((u32)b + b->size + b->free - size + 0x1C) & (align - 1);
                } else {
                    pad = 0;
                }
                if (b->free >= size + pad) {
                    size += pad;
                    n = (Blk8009E8F0 *)((u32)b + b->size + b->free - size);
                    n->size = size;
                    n->free = 0;
                    b->free -= size;
                    n->tag = heap->tag;
                    n->next = NULL;
                    n->prev = NULL;
                    if (b->free == 0) {
                        t = b->prev;
                        if (t != NULL) {
                            t->next = b->next;
                        }
                        t = b->next;
                        if (t != NULL) {
                            t->prev = b->prev;
                        }
                        if (heap->head == b) {
                            heap->head = b->next;
                        }
                        if (heap->tail == b) {
                            heap->tail = b->next != NULL ? b->next : b->prev;
                        }
                        b->prev = NULL;
                        b->next = NULL;
                    }
                    n->pprev = b;
                    n->pnext = b->pnext;
                    if (b->pnext != NULL) {
                        b->pnext->pprev = n;
                    }
                    b->pnext = n;
                    p = (u8 *)n + 0x1C;
                    if (heap->debug != 0) {
                        func_8009E0F0(p, 0xCD, n->size - 0x1C);
                    }
                    func_80004ED0(st.m, 0, 1);
                    return p;
                }
            }
            b = b->prev;
            goto loop;
        }
        heap->minFail = size;
    }
    func_8009EEDC(heap, &st.a, &st.b);
    func_80004ED0(st.m, 0, 1);
    return NULL;
}
