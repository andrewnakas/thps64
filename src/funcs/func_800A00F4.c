#include "common.h"

typedef struct { u8 pad[8]; s16 off; s16 pad2; void (*fn)(void *); } V800A00F4;

void func_800A00F4(u8 *arg0) {
    V800A00F4 *v = *(V800A00F4 **)(arg0 + 0x1C4);
    v->fn(arg0 + v->off);
}
