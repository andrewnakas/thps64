/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

f32 func_80001CA0(f32);

typedef struct {
    s32 x;
    s32 y;
} Pt;

typedef struct {
    u8 pad0[0x48];
    Pt *unk48;
    u8 pad4C[4];
    u32 unk50;
    u8 pad54[0x14];
    s32 unk68[8];
    s32 unk88[8];
    s32 unkA8;
    s32 unkAC;
} Wave;

static inline s32 isin(s32 a) {
    if (a == 0) {
        return 0;
    }
    a %= 4096;
    return (s32)(func_80001CA0((f32)a * 0.000244140625f * 6.283185) * 4096.0f);
}

void func_8007D808(Wave *arg0) {
    u32 i;
    s32 v;
    s32 t;

    i = 0;
    while (1) {
        if (i >= arg0->unk50) {
            break;
        }
        t = arg0->unk88[i] + arg0->unk68[i];
        arg0->unk88[i] = t;
        v = isin(t);
        arg0->unk48[i].x = arg0->unkAC + arg0->unkA8 * v / 4096;
        i++;
    }
}
