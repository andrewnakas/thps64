/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0xC]; s32 head; s32 pad10; s32 count; s32 size; } Q800BD6F4;

void func_800BD6F4(Q800BD6F4 *arg0) {
    arg0->head = (arg0->head + 1) % arg0->size;
    arg0->count--;
}
