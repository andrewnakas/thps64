/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 prev;
    s32 next;
    u8 *head;
    u8 *tail;
} List;

#define LNK(n, o) (*(u8 **)((n) + (o)))

void func_800A03C8(List *l, u8 *n) {
    if (l->head == n) {
        l->head = LNK(n, l->next);
    } else {
        LNK(LNK(n, l->prev), l->next) = LNK(n, l->next);
    }
    if (l->tail == n) {
        l->tail = LNK(n, l->prev);
    } else {
        LNK(LNK(n, l->next), l->prev) = LNK(n, l->prev);
    }

}
