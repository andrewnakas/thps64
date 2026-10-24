/* cflags: -O2 */
#include "common.h"

typedef struct Blk8009EB54 {
    struct Blk8009EB54 *prev;
    struct Blk8009EB54 *next;
    struct Blk8009EB54 *pprev;
    struct Blk8009EB54 *pnext;
    s32 size;
    s32 free;
    s32 tag;
} Blk8009EB54;

typedef struct {
    Blk8009EB54 *head;
    Blk8009EB54 *tail;
    s32 pad8;
    s32 debug;
    u8 pad10[8];
    s32 tag;
} Heap8009EB54;

extern void func_8009E0F0(u8 *, s32, s32, Blk8009EB54 *);
extern void func_8009EEDC(Heap8009EB54 *, void *, void *);

u8 *func_8009EB54(Heap8009EB54 *heap, u8 *addr, s32 size) {
    Blk8009EB54 *b;
    Blk8009EB54 *n;
    Blk8009EB54 *t;
    u8 *start;
    u8 *end;
    s32 sp10;
    s32 sp14;

    size = (size + 0x1F) & ~3;
    if (heap->head != NULL) {
        b = heap->head;
        while (b->next != NULL) {
            if ((u8 *)b->next >= addr) {
                break;
            }
            b = b->next;
        }
        n = (Blk8009EB54 *)(addr - 0x1C);
        start = (u8 *)b + b->size;
        end = start + b->free;
        if ((u8 *)n >= start && end >= (u8 *)n + size) {
            n->size = size;
            n->free = end - ((u8 *)n + size);
            n->tag = heap->tag;
            if (n->free != 0) {
                ((Blk8009EB54 *)(addr - 0x1C))->prev = b;
                n->next = t = b->next;
                if (b->next != NULL) {
                    t->prev = n;
                }
                b->next = n;
                if (heap->tail == b) {
                    heap->tail = n;
                }
            } else {
                n->prev = NULL;
                n->next = NULL;
            }
            b->free = (u8 *)n - ((u8 *)b + b->size);
            if (b->free == 0) {
                if (b->prev != NULL) {
                    b->prev->next = b->next;
                }
                if (b->next != NULL) {
                    b->next->prev = b->prev;
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
            n->pnext = t = b->pnext;
            if (b->pnext != NULL) {
                t->pprev = n;
            }
            b->pnext = n;
            if (heap->debug != 0) {
                func_8009E0F0(addr, 0xCD, n->size - 0x1C, n);
            }
            return addr;
        }
    }
    func_8009EEDC(heap, &sp10, &sp14);
    return NULL;
}
