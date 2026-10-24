/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x40];
    s32 unk40;
    f32 pitch;
    s32 unk48;
    f32 frac;
    s32 unk50;
} Res_800AF870;

s32 func_80003520(s32);
u32 *func_800AF160(Res_800AF870 *, s16 *, s32, u32 *);

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MAX_RATIO 1.99996
#define UNITY_PITCH 0x8000
#define FIXED_SAMPLE 0xB8

u32 *func_800AF870(Res_800AF870 *e, s16 *outp, u32 *p) {
    u32 *ptr = p;
    s16 inp;
    s32 inCount;
    s32 incr;
    f32 finCount;

    inp = 0x170;
    if (e->unk48 != 0) {
        ptr = func_800AF160(e, &inp, FIXED_SAMPLE, p);
        {
            u32 *_a = ptr;
            ptr += 2;
            _a[0] = _SHIFTL(0x0A, 24, 8) | _SHIFTL(inp, 0, 24);
            _a[1] = _SHIFTL(*outp, 16, 16) | _SHIFTL(FIXED_SAMPLE << 1, 0, 16);
        }
    } else {
        if (e->pitch > MAX_RATIO) {
            e->pitch = MAX_RATIO;
        }
        e->pitch = (s32)(e->pitch * UNITY_PITCH);
        e->pitch = e->pitch / UNITY_PITCH;
        finCount = e->frac + (e->pitch * (f32)FIXED_SAMPLE);
        inCount = (s32)finCount;
        e->frac = finCount - (f32)inCount;
        ptr = func_800AF160(e, &inp, inCount, p);
        incr = (s32)(e->pitch * UNITY_PITCH);
        {
            u32 *_a = ptr;
            ptr += 2;
            _a[0] = _SHIFTL(0x05, 24, 8) | _SHIFTL(func_80003520(e->unk40), 0, 24);
            _a[1] = _SHIFTL(e->unk50, 30, 2) | _SHIFTL(incr, 14, 16) | _SHIFTL(inp, 2, 12) | _SHIFTL(0, 0, 2);
        }
        e->unk50 = 0;
    }
    return ptr;
}
