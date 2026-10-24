/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} SmpEnt;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
    SmpEnt ents[1];
} Smp;

typedef struct {
    u8 pad0[0x78];
    Smp *unk78;
    u8 pad7C[0x2A];
    u16 unkA6;
    u8 padA8[0x88];
} Voice;

s32 func_800ADEEC(Voice *, Smp *, s32, s32, s32, s32);
s32 func_800ADF98(Smp *, s32, s32, s32, s32);
extern s32 D_800FC2F0;
extern Voice *D_800FC2FC;
extern s32 D_800FC314;
extern Smp *D_800FC324;
extern Smp *D_800FC328;

s32 func_800ABA60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Smp *s;
    Voice *v;
    s32 i;
    s32 r;

    if (D_800FC328 != NULL) {
        s = D_800FC328;
        D_800FC328 = NULL;
    } else {
        s = D_800FC324;
        if (s == NULL) {
            D_800FC314 = 0;
            return 0;
        }
    }
    if (D_800FC314 == 0) {
        D_800FC314 = s->unk10;
    }
    if (arg3 != 0) {
        v = D_800FC2FC;
        for (i = 4; i < D_800FC2F0; i++, v++) {
            if (v->unkA6 == arg0 && v->unk78 == s) {
                if (arg4 == -1) {
                    arg4 = s->ents[arg0].unk4;
                }
                r = func_800ADEEC(v, s, arg0, arg1, arg2, arg4);
                D_800FC314 = 0;
                return r;
            }
        }
    }
    r = func_800ADF98(s, arg0, arg1, arg2, arg4);
    D_800FC314 = 0;
    return r;
}
