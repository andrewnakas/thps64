/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0xC]; u16 cur; u16 prev; u8 pad2[0xC]; } Ent800FC580;
extern Ent800FC580 D_800FC580[];

s32 func_800B4264(s32 i, s32 mask) {
    if ((D_800FC580[i].cur & mask) && !(D_800FC580[i].prev & mask)) {
        return 1;
    }
    return 0;
}
