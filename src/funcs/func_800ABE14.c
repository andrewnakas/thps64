/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0xC];
    s32 unk10;
    u8 pad14[8];
    s32 unk1C;
    u8 pad20[0x24];
    s32 unk44;
    u8 pad48[0x130 - 0x48];
} Ent;

extern s32 D_800FC2F0;
extern Ent *D_800FC2F8;

s32 func_800ABE14(s32 arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 m;
    Ent *e;

    if (arg0 == 0) {
        return 0;
    }
    m = arg1;
    if (arg1 == 0) {
        m = 1;
    }
    e = D_800FC2F8;
    n = 0;
    for (i = 0; i < D_800FC2F0; i++, e++) {
        if (e->unk44 == arg0 && e->unk10 == -1) {
            if (e->unk0 & 1) {
                e->unk1C = 1;
                e->unk10 = 0;
                e->unk0 &= ~1;
            } else {
                e->unk1C = m;
                e->unk10 = arg1;
            }
            n++;
        }
    }
    return n;
}
