/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0x68]; s16 off; s16 pad2; void (*fn)(void *); } VtEnt;

void func_800B3C78(u8 *a0) {
    VtEnt *v = *(VtEnt **)(a0 + 0x1C4);
    v->fn(a0 + v->off);
}
