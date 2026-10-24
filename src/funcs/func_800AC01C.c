/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0xB0 - 0x48];
    s16 unkB0;
    u8 padB2[0xBE - 0xB2];
    u8 unkBE;
    u8 padBF[0x130 - 0xBF];
} Ent;

extern s32 D_800FC2F0;
extern Ent *D_800FC2F8;

s32 func_800AC01C(s32 arg0, s32 arg1) {
    s32 i;
    s32 n;
    Ent *e;

    if (arg0 == 0) {
        return 0;
    }
    e = D_800FC2F8;
    n = 0;
    i = 0;
    while (i < D_800FC2F0) {
        i++;
        if (e->unk44 == arg0) {
            n++;
            e->unkB0 = arg1;
            e->unkBE = 0xFF;
        }
        e++;
    }
    return n;
}
