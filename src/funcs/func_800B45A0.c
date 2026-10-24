/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u16 unkC;
    u16 unkE;
    f32 unk10;
    f32 unk14;
    f32 unk18;
} E1C;

extern E1C D_800FC580[];

s32 func_800B45A0(s32 arg0) {
    E1C *e = &D_800FC580[arg0];
    s32 a;
    s32 b;

    a = 0;
    if ((e->unkC & 0x400) || e->unk8 == -1.0f) {
        a = 1;
    }
    if (a == 0) {
        return 0;
    }
    b = 0;
    if ((e->unkE & 0x400) || e->unk18 == -1.0f) {
        b = 1;
    }
    return b ^ 1;
}
