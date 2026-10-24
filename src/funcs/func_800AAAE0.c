/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x58];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    s32 unk64;
    u8 pad68[0x57];
    u8 unkBF;
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 padC3[3];
    u8 unkC6;
    u8 unkC7;
    u8 unkC8;
} Env;

u8 *func_800AAAE0(Env *arg0, u8 *p) {
    u8 n;

    n = *p++;
    if (n == 0) {
        n = 1;
    }
    arg0->unkBF = n;
    arg0->unk64 = 0x400 / n;
    arg0->unkC0 = *p++;
    n = *p++;
    arg0->unkC6 = n;
    arg0->unkC1 = *p++;
    arg0->unk58 = 1.0 / (f32)n * (f32)(arg0->unkC1 - arg0->unkC0);
    n = *p++;
    arg0->unkC7 = n;
    arg0->unkC2 = *p++;
    arg0->unk5C = 1.0 / (f32)n * (f32)(arg0->unkC2 - arg0->unkC1);
    n = *p++;
    arg0->unkC8 = n;
    arg0->unk60 = 1.0 / (f32)n;
    return p;
}
