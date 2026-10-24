/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 prev;
    s32 next;
    s32 head;
    s32 tail;
} Unk_800A02AC;

void func_800A02AC(Unk_800A02AC *arg0, s32 arg1) {
    *(s32 *)(arg1 + arg0->prev) = arg0->tail;
    if (arg0->tail != 0) {
        *(s32 *)(arg0->tail + arg0->next) = arg1;
    } else {
        arg0->head = arg1;
    }
    *(s32 *)(arg1 + arg0->next) = 0;
    arg0->tail = arg1;
}
