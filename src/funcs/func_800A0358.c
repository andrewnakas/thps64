/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 prevOff;
    s32 nextOff;
} List;

void func_800A02AC(List *, u8 *);

#define PREV(n) (*(u8 **)((n) + l->prevOff))
#define NEXT(n) (*(u8 **)((n) + l->nextOff))

void func_800A0358(List *l, u8 *pos, u8 *node) {
    if (NEXT(pos) != NULL) {
        PREV(NEXT(pos)) = node;
        NEXT(node) = NEXT(pos);
        NEXT(pos) = node;
        PREV(node) = pos;
        return;
    }
    func_800A02AC(l, node);
}
