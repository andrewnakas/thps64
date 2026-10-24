/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 v[3];
    s16 h10;
    u8 pad12[0x5AA - 0x12];
    u16 a5AA;
} C48928;

typedef struct {
    s32 x, y, z;
} V48928;

f32 func_80001CA0(f32);
s32 func_80023190(s32, s32);
s32 func_80047C34(s32 *, V48928 *);
extern C48928 *D_800DE144;

s32 func_80048928(s32 *pos, s32 lo, s32 hi) {
    V48928 v;
    s32 d;
    s32 a;
    s32 r;
    s32 ang;
    s32 h;
    s32 b;
    s32 s;
    s32 left;
    s32 right;
    u32 flag;
    s32 g;

    flag = 0;
    if (D_800DE144 == NULL) {
        return 0;
    }
    v = *(V48928 *)D_800DE144->v;
    d = func_80047C34(pos, &v);
    if (lo >= d) {
        return 0x0FFF0FFF;
    }
    if (d >= hi) {
        return 0;
    }
    g = ((hi - d) * 4095) / hi;
    a = D_800DE144->h10;
    if ((a - 0x400 >= 0 ? a - 0x400 : 0x400 - a) < 0x40) {
        return g | (g << 16);
    }
    ang = 0x400 - func_80023190(pos[2] - v.z, pos[0] - v.x);
    h = D_800DE144->a5AA - 0x800;
    r = (ang - h) & 0xFFF;
    if ((u32)(r - 0x401) < 0x7FF) {
        flag = 0x80000000;
        g -= g >> 4;
    }
    left = g;
    if (r < 0x800) {
        if (r == 0) {
            s = 0;
        } else {
            s = func_80001CA0(r % 4096 * 0.000244140625f * 6.283185) * 4096.0f;
        }
        left = g - ((g * s) >> 12);
        right = g;
    } else {
        b = r;
        if (b == 0) {
            s = 0;
        } else {
            b = r - (b / 4096) * 4096;
            s = func_80001CA0(b * 0.000244140625f * 6.283185) * 4096.0f;
        }
        right = g + ((g * s) >> 12);
    }
    return left | (right << 16) | flag;
}
