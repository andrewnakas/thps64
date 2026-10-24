/* cflags: -O2 */
#include "common.h"

typedef struct { s32 nextOff; s32 prevOff; u8 *tail; u8 *head; } List;

void func_800A0270(List *l, u8 *n) {
    *(u8 **)(n + l->prevOff) = l->tail;
    if (l->tail != NULL) {
        *(u8 **)(l->tail + l->nextOff) = n;
    } else {
        l->head = n;
    }
    *(u8 **)(n + l->nextOff) = NULL;
    l->tail = n;
}
