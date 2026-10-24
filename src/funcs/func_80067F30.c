/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z, w;
} Quat67F30;

s32 func_800233EC(s32);
s32 func_80048EF0(s32);
f32 func_80001CA0(f32);

static inline s32 sin67F30(s32 a) {
    s32 b;

    s32 r;

    r = 0;
    if (a != 0) {
        b = a;
        b = a - (b / 4096) * 4096;
        r = func_80001CA0(b * 0.000244140625f * 6.283185) * 4096.0f;
    }
    return r;
}

static inline s32 sinb67F30(s32 a) {
    s32 b;

    if (a == 0) {
        return 0;
    }
    b = a;
    b = a - (b / 4096) * 4096;
    return func_80001CA0(b * 0.000244140625f * 6.283185) * 4096.0f;
}

void func_80067F30(Quat67F30 a, Quat67F30 b, s32 t, Quat67F30 *out) {
    s32 dot;
    s32 th;
    s32 s;
    s32 ka;
    s32 kb;
    s32 m;

    {
        s32 l;
        l = func_800233EC(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
        if (l == 0) {
            l = 1;
        }
        a.x = (a.x << 12) / l;
        a.y = (a.y << 12) / l;
        a.z = (a.z << 12) / l;
        a.w = (a.w << 12) / l;
    }
    {
        s32 l;
        l = func_800233EC(b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w);
        if (l == 0) {
            l = 1;
        }
        b.x = (b.x << 12) / l;
        b.y = (b.y << 12) / l;
        b.z = (b.z << 12) / l;
        b.w = (b.w << 12) / l;
    }
    dot = (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w) >> 12;
    if (dot < 0) {
        dot = -dot;
        a.x = -a.x;
        a.y = -a.y;
        a.z = -a.z;
        a.w = -a.w;
    }
    if (dot > 0x1000) {
        dot = 0x1000;
    }
    if (dot + 0x1000 > 0x80) {
        if (0x1000 - dot > 0x80) {
            th = func_80048EF0(dot);
            s = sinb67F30(th);
            ka = (sinb67F30(((0x1000 - t) * th) >> 12) << 12) / s;
            kb = (sinb67F30((t * th) >> 12) << 12) / s;
        } else {
            ka = 0x1000 - t;
            kb = t;
        }
        out->x = (ka * a.x + kb * b.x) >> 12;
        out->y = (ka * a.y + kb * b.y) >> 12;
        out->z = (ka * a.z + kb * b.z) >> 12;
        out->w = (ka * a.w + kb * b.w) >> 12;
    } else {
        out->x = -a.y;
        out->y = -a.x;
        out->z = -a.w;
        out->w = a.z;
        {
            s32 a0 = ((0x1000 - t) * 6434) >> 12;
            ka = 0;
            if (a0 != 0) {
                a0 = a0 - (a0 / 4096) * 4096;
                ka = func_80001CA0(a0 * 0.000244140625f * 6.283185) * 4096.0f;
            }
        }
        kb = sin67F30((t * 6434) >> 12);
        out->x = (ka * a.x + kb * out->x) >> 12;
        out->y = (ka * a.y + kb * out->y) >> 12;
        out->z = (ka * a.z + kb * out->z) >> 12;
        out->w = (ka * a.w + kb * out->w) >> 12;
    }
    {
        s32 l;
        l = func_800233EC(out->x * out->x + out->y * out->y + out->z * out->z + out->w * out->w);
        if (l == 0) {
            l = 1;
        }
        out->x = (out->x << 12) / l;
        out->y = (out->y << 12) / l;
        out->z = (out->z << 12) / l;
        out->w = (out->w << 12) / l;
    }
}
