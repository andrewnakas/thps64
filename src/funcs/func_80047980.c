/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3i_80047980;

typedef struct {
    u16 x;
    u16 y;
} Ang_80047980;

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

static inline s32 icos_(s32 a) {
    if (a == 0) {
        return 0x1000;
    }
    a %= 4096;
    return (s32)(func_800018C0((f32)a * 0.000244140625f * 6.283185) * 4096.0f);
}

static inline s32 isin_(s32 a) {
    if (a == 0) {
        return 0;
    }
    a %= 4096;
    return (s32)(func_80001CA0((f32)a * 0.000244140625f * 6.283185) * 4096.0f);
}

void func_80047980(V3i_80047980 *out, s32 len, Ang_80047980 *ang) {
    out->x = -(((len * icos_(ang->x & 0xFFF)) >> 12) * isin_(ang->y & 0xFFF));
    out->y = len * isin_(ang->x & 0xFFF);
    out->z = -(((len * icos_(ang->x & 0xFFF)) >> 12) * icos_(ang->y & 0xFFF));
}
