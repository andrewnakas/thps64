/* cflags: -O2 */
#include "common.h"

typedef struct { s32 v; u8 pad[0x20]; } Ent800A9B40;
typedef struct { s32 active; u8 pad[0x538]; Ent800A9B40 e[200]; } Unk800A9B40;

void func_800A9B40(Unk800A9B40 *a0, s32 a1, s32 a2) {
    if (a0->active != 0 && a1 < 200) {
        a0->e[a1].v = a2;
    }
}
