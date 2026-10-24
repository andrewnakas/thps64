/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *buf;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 pos;
    s32 count;
    s32 size;
} Ring;

void func_800BD680(Ring *r, s32 v) {
    s32 i;

    i = r->pos;
    if (i >= r->unk4) {
        r->unk4 = i - 1;
    }
    i <<= 2;
    *(s32 *)((u8 *)r->buf + i) = v;
    r->pos = (r->pos + 1) % r->size;
    r->count++;
}
