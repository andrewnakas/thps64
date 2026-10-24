/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 unk0;
    u8 pad4[0x10];
    s32 unk14;
    u8 pad18[0x48];
    f32 unk60;
    u8 pad64[0x9C];
} Sub;

typedef struct {
    u8 pad0[0x30];
    Sub s;
} Ent;

extern s32 D_800FC2F0;
extern Ent *D_800FC2F8;

s32 func_800AC0CC(s32 arg0, f32 arg1) {
    s32 i;
    s32 n;
    Ent *e;

    if (arg0 == 0) {
        return 0;
    }
    n = 0;
    for (e = D_800FC2F8, i = 0; i < D_800FC2F0; i++, e++) {
        if (e->s.unk14 == arg0) {
            n++;
            e->s.unk0 = arg1 + e->s.unk60;
        }
    }
    return n;

}
