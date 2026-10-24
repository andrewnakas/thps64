/* cflags: -O2 */
#include "common.h"

typedef struct { s32 flags; u8 pad[0x40]; s32 id; u8 pad2[0x56]; s16 v; u8 pad3[0x90]; } Ent130;
extern s32 D_800FC2F0;
extern Ent130 *D_800FC2F8;

s32 func_800ABFC4(s32 id, s16 v) {
    s32 i;
    s32 n;
    Ent130 *e;
    if (id == 0) {
        return 0;
    }
    n = 0;
    e = D_800FC2F8;
    for (i = 0; i < D_800FC2F0; i++, e++) {
        if (e->id == id) {
            e->v = v;
            n++;
        }
    }
    return n;
}
