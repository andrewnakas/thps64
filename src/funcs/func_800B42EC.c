#include "common.h"

typedef struct { u8 pad[0x14]; f32 a; f32 b; } S800FC580;
extern S800FC580 D_800FC580[];

f32 func_800B42EC(s32 arg0, u8 arg1) {
    S800FC580 *e = &D_800FC580[arg0];
    if (arg1 == 0x78) {
        return e->a;
    }
    return e->b;
}
