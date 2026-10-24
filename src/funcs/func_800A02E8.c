/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 nextOff;
    s32 prevOff;
} List800A02E8;

extern void func_800A0270(List800A02E8 *, u8 *);

void func_800A02E8(List800A02E8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *next;

    next = *(u8 **)(arg1 + arg0->nextOff);
    if (next != NULL) {
        *(u8 **)(next + arg0->prevOff) = arg2;
        *(u8 **)(arg2 + arg0->nextOff) = *(u8 **)(arg1 + arg0->nextOff);
        *(u8 **)(arg1 + arg0->nextOff) = arg2;
        *(u8 **)(arg2 + arg0->prevOff) = arg1;
    } else {
        func_800A0270(arg0, arg2);
    }
}
