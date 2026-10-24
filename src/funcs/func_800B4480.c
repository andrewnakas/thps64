/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x4];
    f32 unk4;
    u8 pad8[0x4];
    u16 unkC;
    u16 unkE;
    u8 pad10[0x4];
    f32 unk14;
    u8 pad18[0x4];
} Ent800B4480;

extern Ent800B4480 D_800FC580[];

s32 func_800B4480(s32 arg0) {
    Ent800B4480 *e;
    s32 a;
    s32 b;
    s32 r;

    e = &D_800FC580[arg0];
    a = 0;
    if ((e->unkC & 0x100) || e->unk4 == 1.0f) {
        a = 1;
    }
    if (a == 0) {
        return 0;
    }
    b = 0;
    if ((e->unkE & 0x100) || e->unk14 == 1.0f) {
        b = 1;
    }
    return b ^ 1;
}
