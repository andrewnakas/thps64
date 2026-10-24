/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0xCB - 0x48];
    u8 unkCB;
    u8 unkCC;
    u8 padCD[0x130 - 0xCD];
} Ent;

extern s32 D_800FC2F0;
extern Ent *D_800FC2F8;

s32 func_800AC1B8(s32 arg0, s32 arg1) {
    s32 i;
    s32 n;
    Ent *e;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 0x7F) {
        arg1 = 0x7F;
    }
    e = D_800FC2F8;
    n = 0;
    i = 0;
    while (i < D_800FC2F0) {
        i++;
        if (e->unk44 == arg0) {
            n++;
            e->unkCB = arg1;
            e->unkCC = 0xFF;
        }
        e++;
    }
    return n;
}
