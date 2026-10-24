#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
    u16 unkE;
    u8 pad10[0xC];
} Unk_800FC580;

extern Unk_800FC580 D_800FC580[];

s32 func_800B42A8(s32 arg0, s32 arg1) {
    Unk_800FC580 *p;
    Unk_800FC580 *base = D_800FC580;
    p = &base[arg0];
    if (!(p->unkC & arg1) && (p->unkE & arg1)) {
        return 1;
    }
    return 0;
}
