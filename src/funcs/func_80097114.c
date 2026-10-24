#include "common.h"

typedef struct { u8 pad[0x38]; s16 off; s16 pad2; void (*fn)(void *); } V80097114;

void func_80097114(u8 *arg0) {
    V80097114 *v;

    *(u16 *)arg0 |= 0x41;
    v = *(V80097114 **)(arg0 + 0x48);
    v->fn(arg0 + v->off);
}
