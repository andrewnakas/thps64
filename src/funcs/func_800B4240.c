/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0xC];
    u16 flags;
    u8 pad2[0x1C - 0xE];
} Unk800FC580;

extern Unk800FC580 D_800FC580[];

s32 func_800B4240(s32 i, s32 mask) {
    return D_800FC580[i].flags & mask;
}
