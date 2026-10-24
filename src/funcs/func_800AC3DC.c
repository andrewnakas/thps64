/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 off;
    s32 unk4;
} Ent8;

typedef struct {
    s32 count;
    s32 unk4;
    s32 unk8;
    s32 flags;
    s32 unk10;
    s32 unk14;
    Ent8 e[1];
} Hdr;

extern Hdr *D_800FC324;

void func_800AC3DC(Hdr *arg0) {
    s32 i;
    u8 *base = (u8 *)arg0;

    if (!(arg0->flags & 1)) {
        if (D_800FC324 == NULL) {
            D_800FC324 = arg0;
        }
        arg0->flags = 1;
        arg0->unk10 = 0;
        arg0->unk14 = (s32)(base + arg0->unk14);
        for (i = 0; i < arg0->count; i++) {
            arg0->e[i].off = (s32)(base + arg0->e[i].off);
        }
    }

}
