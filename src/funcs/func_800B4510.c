/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    f32 unk8;
    u16 unkC;
    u16 unkE;
    u8 pad10[8];
    f32 unk18;
} Unk_800FC580;

extern Unk_800FC580 D_800FC580[];

s32 func_800B4510(s32 arg0) {
    Unk_800FC580 *p = &D_800FC580[arg0];
    s32 a;
    s32 b;

    a = 0;
    if ((p->unkC & 0x800) || p->unk8 == 1.0f) {
        a = 1;
    }
    if (!a) {
        return 0;
    }
    b = 0;
    if ((p->unkE & 0x800) || p->unk18 == 1.0f) {
        b = 1;
    }
    return !b;
}
