/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0x1C]; } Ent800FC580;
extern Ent800FC580 D_800FC580[];
extern void func_800B4094(Ent800FC580 *, s32, s32, u32);

void func_800B4338(s32 i, u32 v) {
    func_800B4094(&D_800FC580[i], (s8)(v >> 8), (s8)v, v >> 16);
}
