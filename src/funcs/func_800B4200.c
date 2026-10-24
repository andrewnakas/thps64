#include "common.h"

typedef struct {
    u8 pad0[0x4];
    f32 unk4;
    f32 unk8;
    u8 padC[0x10];
} Unk_800FC580;

extern Unk_800FC580 D_800FC580[];

f32 func_800B4200(s32 arg0, u8 arg1) {
    Unk_800FC580 *e;

    e = &D_800FC580[arg0];
    if (arg1 == 0x78) {
        return e->unk4;
    }
    return e->unk8;
}
