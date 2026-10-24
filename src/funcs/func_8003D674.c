#include "common.h"

typedef struct {
    s32 v0;
    s32 v4;
    s32 v8;
    s32 vC;
    u8 pad10[0x10];
} Sub3D674;

typedef struct {
    u8 pad0[0x18];
    s32 n[4];
    u8 pad28[0x60 - 0x28];
    Sub3D674 sub[7];
    u8 pad140[0x154 - 0x140];
} Row3D674;

typedef struct {
    u8 pad0[0x30];
    s32 v30;
    u8 pad34[0x7B4 - 0x34];
    s32 v7B4;
    u8 a7B8[0x14];
    u8 a7CC[0x14];
    u8 a7E0[0x14];
    u8 a7F4[0x14];
} Obj3D674;

void func_800B1AC4(void *, f32, f32, f32, f32);
extern Row3D674 D_800D4D80[];

void func_8003D674(Obj3D674 *o) {
    Row3D674 *tbl;
    f64 dyf;
    u32 x;
    f32 fx;
    s32 n1, n2, n3, n4;
    s32 two;
    s32 m;
    Row3D674 *r;
    f64 dxf;
    s32 i;
    u32 y;
    void *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
    s32 dx;

    x = 0xDC;
    y = 0xBE;
    dx = 15;
    two = o->v7B4 >= 2;
    tbl = D_800D4D80;
    r = &tbl[o->v30];
    n1 = r->n[0];
    n2 = r->n[1];
    n3 = r->n[2];
    n4 = r->n[3];
    for (i = 0; i < n1; i++, x += dx) {
        p1 = o->a7B8;
        dxf = (s32)x;
        if ((s32)x < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p1, fx, (f32)dyf, 1.0f, 1.0f);
    }
    if (two) {
        m = D_800D4D80[o->v30].sub[o->v7B4].v0;
        for (i = 0; i < m; i++, x += dx) {
            p2 = o->a7F4;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p2, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
    y += 0x17;
    x = 0xDC;
    for (i = 0; i < n2; i++, x += dx) {
        p3 = o->a7CC;
        dxf = (s32)x;
        if ((s32)x < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p3, fx, (f32)dyf, 1.0f, 1.0f);
    }
    if (two) {
        m = D_800D4D80[o->v30].sub[o->v7B4].v4;
        for (i = 0; i < m; i++, x += dx) {
            p4 = o->a7F4;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p4, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
    y += 0x17;
    x = 0xDC;
    for (i = 0; i < n3; i++, x += dx) {
        p5 = o->a7E0;
        dxf = (s32)x;
        if ((s32)x < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p5, fx, (f32)dyf, 1.0f, 1.0f);
    }
    if (two) {
        m = D_800D4D80[o->v30].sub[o->v7B4].v8;
        for (i = 0; i < m; i++, x += dx) {
            p6 = o->a7F4;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p6, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
    y += 0x17;
    x = 0xDC;
    for (i = 0; i < n4; i++, x += dx) {
        p7 = o->a7B8;
        dxf = (s32)x;
        if ((s32)x < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p7, fx, (f32)dyf, 1.0f, 1.0f);
    }
    if (two) {
        m = D_800D4D80[o->v30].sub[o->v7B4].vC;
        for (i = 0; i < m; i++, x += dx) {
            p8 = o->a7F4;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p8, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
}
