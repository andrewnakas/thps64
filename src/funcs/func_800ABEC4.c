/* cflags: -O2 */
#include "common.h"

typedef struct { s32 flags; u8 pad[0x40]; s32 id; u8 pad2[0xE8]; } Ent130;
extern s32 D_800FC2F0;
extern Ent130 *D_800FC2F8;

s32 func_800ABEC4(s32 id) {
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
            n++;
        }
    }
    return n;
}
