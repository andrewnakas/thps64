/* cflags: -frerun-cse-after-loop */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s32 n[4];
    u8 pad28[0x154 - 0x28];
} Row2F904;

typedef struct {
    u8 pad0[0x30];
    u8 a30[0x14];
    u8 a44[0x14];
    u8 a58[0x14];
    u8 pad6C[0x78C - 0x6C];
    s32 v78C;
    s32 v790;
    u8 pad794[4];
    u16 h798;
    u16 h79A;
    u16 h79C;
} Obj2F904;

void func_800B1AC4(void *, f32, f32, f32, f32);
extern Row2F904 D_800D4D80[];

void func_8002F904(Obj2F904 *o) {
    u32 x1;
    u32 x2;
    u32 y;
    s32 dx;
    s32 dy;
    f32 sc;
    s32 i;
    f64 dxf;
    f64 dyf;
    f32 fx;
    void *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

    x1 = o->h798;
    y = o->h79C;
    x2 = o->h79A;
    dx = 15;
    dy = 0x11;
    sc = 0.9f;
    for (i = 0; i < D_800D4D80[o->v78C].n[0]; i++, x1 += dx) {
        p1 = o->a30;
        dxf = (s32)x1;
        if ((s32)x1 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p1, fx, (f32)dyf, 1.0f, sc);
    }
    for (i = 0; i < D_800D4D80[o->v790].n[0]; i++, x2 += dx) {
        p2 = o->a30;
        dxf = (s32)x2;
        if ((s32)x2 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p2, fx, (f32)dyf, 1.0f, sc);
    }
    y += dy;
    x1 = o->h798;
    x2 = o->h79A;
    for (i = 0; i < D_800D4D80[o->v78C].n[1]; i++, x1 += dx) {
        p3 = o->a44;
        dxf = (s32)x1;
        if ((s32)x1 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p3, fx, (f32)dyf, 1.0f, sc);
    }
    for (i = 0; i < D_800D4D80[o->v790].n[1]; i++, x2 += dx) {
        p4 = o->a44;
        dxf = (s32)x2;
        if ((s32)x2 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p4, fx, (f32)dyf, 1.0f, sc);
    }
    y += dy;
    x1 = o->h798;
    x2 = o->h79A;
    for (i = 0; i < D_800D4D80[o->v78C].n[2]; i++, x1 += dx) {
        p5 = o->a58;
        dxf = (s32)x1;
        if ((s32)x1 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p5, fx, (f32)dyf, 1.0f, sc);
    }
    for (i = 0; i < D_800D4D80[o->v790].n[2]; i++, x2 += dx) {
        p6 = o->a58;
        dxf = (s32)x2;
        if ((s32)x2 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p6, fx, (f32)dyf, 1.0f, sc);
    }
    y += dy;
    x1 = o->h798;
    x2 = o->h79A;
    for (i = 0; i < D_800D4D80[o->v78C].n[3]; i++, x1 += dx) {
        p7 = o->a30;
        dxf = (s32)x1;
        if ((s32)x1 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p7, fx, (f32)dyf, 1.0f, sc);
    }
    for (i = 0; i < D_800D4D80[o->v790].n[3]; i++, x2 += dx) {
        p8 = o->a30;
        dxf = (s32)x2;
        if ((s32)x2 < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p8, fx, (f32)dyf, 1.0f, sc);
    }
}
