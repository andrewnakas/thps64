#include "common.h"

typedef struct { u8 a; u8 b; u8 pad[0x1A]; } S800FC580;
extern S800FC580 D_800FC580[];

u8 func_800B3CF0(s32 arg0) {
    return D_800FC580[arg0].b;
}
