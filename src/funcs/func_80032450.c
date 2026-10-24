/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

#define U2F(u) ({ f64 _d = (s32)(u); if ((s32)(u) < 0) { _d += 4294967296.0; } (f32)_d; })

typedef struct {
    u8 pad0[0x18];
    s32 stat[4];
    u8 pad28[0x12C];
} Ent32450;

void func_800B1AC4(void *, f32, f32, f32, f32);
extern Ent32450 D_800D4D80[];

void func_80032450(u8 *arg0) {
    u32 x1;
    u32 x2;
    u32 y;
    f32 sc;
    u32 dx;
    u32 dy;
    s32 i;
    s32 a;
    s32 b;

    x1 = 212;
    x2 = 460;
    y = 300;
    dx = 14;
    dy = 20;
    sc = 0.9f;
    for (i = 0; i < D_800D4D80[arg0[0x3C]].stat[0]; i++) {
        func_800B1AC4(arg0 + 0x4F8, U2F(x1), U2F(y), 1.0f, sc);
        x1 += dx;
    }
    for (i = 0; i < D_800D4D80[arg0[0x3D]].stat[0]; i++) {
        func_800B1AC4(arg0 + 0x4F8, U2F(x2), U2F(y), 1.0f, sc);
        x2 += dx;
    }
    y += dy;
    x1 = 212;
    x2 = 460;
    for (i = 0; i < D_800D4D80[arg0[0x3C]].stat[1]; i++) {
        func_800B1AC4(arg0 + 0x50C, U2F(x1), U2F(y), 1.0f, sc);
        x1 += dx;
    }
    for (i = 0; i < D_800D4D80[arg0[0x3D]].stat[1]; i++) {
        func_800B1AC4(arg0 + 0x50C, U2F(x2), U2F(y), 1.0f, sc);
        x2 += dx;
    }
    y += dy;
    x1 = 212;
    x2 = 460;
    for (i = 0; i < D_800D4D80[arg0[0x3C]].stat[2]; i++) {
        func_800B1AC4(arg0 + 0x520, U2F(x1), U2F(y), 1.0f, sc);
        x1 += dx;
    }
    for (i = 0; i < D_800D4D80[arg0[0x3D]].stat[2]; i++) {
        func_800B1AC4(arg0 + 0x520, U2F(x2), U2F(y), 1.0f, sc);
        x2 += dx;
    }
    y += dy;
    x1 = 212;
    x2 = 460;
    for (i = 0; i < D_800D4D80[arg0[0x3C]].stat[3]; i++) {
        func_800B1AC4(arg0 + 0x4F8, U2F(x1), U2F(y), 1.0f, sc);
        x1 += dx;
    }
    for (i = 0; i < D_800D4D80[arg0[0x3D]].stat[3]; i++) {
        func_800B1AC4(arg0 + 0x4F8, U2F(x2), U2F(y), 1.0f, sc);
        x2 += dx;
    }
    a = 212;
    b = 460;
    for (i = 0; i < arg0[0x48]; i++) {
        func_800B1AC4(arg0 + 0x534, a, 382.0f, 1.0f, 1.0f);
        a += 14;
    }
    for (i = 0; i < arg0[0x49]; i++) {
        func_800B1AC4(arg0 + 0x534, b, 382.0f, 1.0f, 1.0f);
        b += 14;
    }
}
