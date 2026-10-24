/* cflags: -O2 */
#include "common.h"

typedef struct Blk {
    struct Blk *n0;
    struct Blk *n4;
    struct Blk *n8;
    struct Blk *nC;
    u32 size;
    u32 free;
} Blk;

typedef struct {
    Blk *head;
    Blk *tail;
    s32 pad8;
    s32 unkC;
    u32 max;
} Heap;

void func_8009E0F0(Blk *, s32, u32, Blk *);

u32 func_8009ED5C(Heap *heap, u8 *p) {
    Blk *b;
    Blk *o;
    Blk *a;
    Blk *h;
    u32 s;

    if (p == NULL) {
        return 0;
    }
    b = (Blk *)(p - 0x1C);
    o = b->n8;
    if (o->free == 0) {
        h = heap->head;
        if (h >= b || h == NULL) {
            o->n4 = h;
            if (heap->head != NULL) {
                heap->head->n0 = o;
            } else {
                heap->tail = o;
            }
            heap->head = o;
        } else {
            a = b->n0;
            if (a == NULL) {
                a = h;
                while (a->n4 != NULL) {
                    h = a->n4;
                    if (b < h) break;
                    a = h;
                }
            }
            o->n0 = a;
            o->n4 = a->n4;
            if (a->n4 != NULL) {
                o->n4->n0 = o;
            }
            a->n4 = o;
            if (heap->tail == a) {
                heap->tail = o;
            }
        }
    }
    s = o->free + b->size + b->free;
    o->free = s;
    if (b->nC != NULL) {
        b->nC->n8 = b->n8;
    }
    b->n8->nC = b->nC;
    if (b->free != 0) {
        if (b->n0 != NULL) {
            b->n0->n4 = b->n4;
        }
        if (b->n4 != NULL) {
            b->n4->n0 = b->n0;
        }
        if (heap->tail == b) {
            heap->tail = b->n0;
        }
    }
    if (s >= heap->max) {
        heap->max = s + 1;
    }
    if (heap->unkC != 0) {
        func_8009E0F0(b, 0, b->size, o);
    }
    return s;
}
