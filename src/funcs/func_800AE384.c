/* cflags: -O2 */
#include "common.h"

typedef struct { s32 flags; u8 pad[0x40]; s32 id; u8 pad2[0xE8]; } Ent130;
extern s32 D_800FC2F0;
extern Ent130 *D_800FC2F8;

void func_800AE384(s32 id, s32 mask, s32 bits) {
    s32 i;
    Ent130 *e = D_800FC2F8;
    for (i = 0; i < D_800FC2F0; i++, e++) {
        if (e->id == id) {
            e->flags = (e->flags & mask) | bits;
        }
    }
}
