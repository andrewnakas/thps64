#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x8];
} Unk_800FC580;

extern Unk_800FC580 D_800FC580[];

s32 func_800B4380(s32 arg0) {
    return D_800FC580[arg0].unk10;
}
