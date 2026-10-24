/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 flags;
    s32 unk4;
    u8 pad8[0x8];
    s32 unk10;
    u8 pad14[0x8];
    s32 unk1C;
    u8 pad20[0x58];
    s32 unk78;
    u8 pad7C[0xB4];
} Voice800ABCDC;

extern s32 D_800FC2F0;
extern Voice800ABCDC *D_800FC2F8;

void func_800ABCDC(s32 arg0, s32 arg1) {
    s32 i;
    s32 vol;
    Voice800ABCDC *v;

    vol = arg1;
    if (arg1 == 0) {
        vol = 1;
    }
    v = D_800FC2F8;
    for (i = 0; i < D_800FC2F0; i++, v++) {
        if (v->unk78 != 0) {
            if (arg0 & 1) {
                goto check;
            }
            continue;
        }
        if (!(arg0 & 2)) {
            continue;
        }
    check:
        if (v->unk4 != 0 && v->unk10 == -1) {
            if (v->flags & 1) {
                v->unk1C = 1;
                v->unk10 = 0;
                v->flags &= ~1;
            } else {
                v->unk1C = vol;
                v->unk10 = arg1;
            }
        }
    }
}
