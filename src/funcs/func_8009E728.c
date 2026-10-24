/* cflags: -O2 */
#include "common.h"

typedef struct Blk_8009E728 {
    struct Blk_8009E728 *prev;
    struct Blk_8009E728 *next;
    struct Blk_8009E728 *aprev;
    struct Blk_8009E728 *anext;
    u32 size;
    u32 free;
    s32 tag;
} Blk_8009E728;

typedef struct {
    Blk_8009E728 *first;
    Blk_8009E728 *last;
    s32 unk8;
    s32 debug;
    u32 failsz;
    s32 unk14;
    s32 tag;
} Heap_8009E728;

void func_8009E0F0(void *, s32, s32);
void func_8009EEDC(Heap_8009E728 *, s32 *, s32 *);

void *func_8009E728(Heap_8009E728 *h, s32 size, u32 align) {
    Blk_8009E728 *b;
    Blk_8009E728 *n;
    u32 pad;
    u32 r;
    Blk_8009E728 *x;
    u8 *ret;
    s32 sp10;
    s32 sp14;

    size = (size + 0x1F) & ~3;
    if ((u32)size < h->failsz || h->failsz == (u32)-1) {
        b = h->first;
        while (1) {
            if (b == NULL) {
                break;
            }
            if (b->free < (u32)size) {
                goto next;
            }
            if (align >= 5) {
                r = ((u32)b + b->size + 0x1C) & (align - 1);
                if (r != 0) {
                    pad = align - r;
                } else {
                    pad = 0;
                }
            } else {
                pad = 0;
            }
            if (b->free < size + pad) {
                goto next;
            }
            b->free -= pad;
            b->size += pad;
            n = (Blk_8009E728 *)((u8 *)b + b->size);
            n->size = size;
            n->free = b->free - size;
            n->tag = h->tag;
            if (n->free != 0) {
                n->prev = b;
                x = b->next;
                n->next = x;
                if (b->next != NULL) {
                    x->prev = n;
                }
                b->next = n;
                if (h->last == b) {
                    h->last = n;
                }
            } else {
                n->prev = NULL;
                n->next = NULL;
            }
            b->free = 0;
            if (b->prev != NULL) {
                b->prev->next = b->next;
            }
            if (b->next != NULL) {
                b->next->prev = b->prev;
            }
            if (h->first == b) {
                h->first = b->next;
            }
            if (h->last == b) {
                if (b->next != NULL) {
                    h->last = b->next;
                } else {
                    h->last = b->prev;
                }
            }
            b->prev = NULL;
            b->next = NULL;
            n->aprev = b;
            x = b->anext;
            n->anext = x;
            if (b->anext != NULL) {
                x->aprev = n;
            }
            b->anext = n;
            ret = (u8 *)n + 0x1C;
            if (h->debug != 0) {
                func_8009E0F0(ret, 0xCD, n->size - 0x1C);
            }
            return ret;
        next:
            b = b->next;
        }
        h->failsz = size;
    }
    func_8009EEDC(h, &sp10, &sp14);
    return NULL;
}
