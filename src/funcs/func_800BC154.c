/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Ent800BC154;

typedef struct {
    u8 pad0[0x2288];
    Ent800BC154 unk2288[4];
    s32 unk22B8;
    s32 unk22BC;
} Obj800BC154;

extern s32 func_800BC244(Obj800BC154 *);

Ent800BC154 *func_800BC154(Obj800BC154 *arg0, s32 arg1, s32 arg2) {
    Ent800BC154 *e;
    s32 v;

    if (++arg0->unk22B8 == arg0->unk22BC) {
        arg0->unk22B8 = 0;
    }
    e = &arg0->unk2288[arg0->unk22B8];
    v = func_800BC244(arg0);
    e->unk4 = (v < arg1) ? arg1 : ((v > arg2) ? arg2 : v);
    return e;
}
