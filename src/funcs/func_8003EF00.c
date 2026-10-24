#include "common.h"

typedef struct {
    s32 v[4];
    u8 pad10[0x10];
} Sub3EF00;

typedef struct {
    u8 pad0[0x18];
    s32 n[4];
    u8 pad28[0x60 - 0x28];
    Sub3EF00 sub[7];
    u8 pad140[0x154 - 0x140];
} Row3EF00;

typedef struct {
    u8 pad0[0x60];
    u8 b60;
    u8 b61;
    u8 pad62[0x66 - 0x62];
    u8 b66;
    u8 pad67[0x2B4 - 0x67];
    u8 a2B4[0x14];
    u8 a2C8[0x14];
    u8 a2DC[0x14];
    u8 a2F0[0x14];
    u8 a304[0x14];
    u8 pad318[0x3A4 - 0x318];
    u8 b3A4;
} Obj3EF00;

void func_800B1AC4(void *, f32, f32, f32, f32);
extern Row3EF00 D_800D4D80[];

void func_8003EF00(Obj3EF00 *o) {
    Row3EF00 *tbl;
    f64 dyf;
    u32 x;
    f32 fx;
    s32 n1, n2, n3, n4;
    s32 two;
    s32 three;
    s32 m;
    Row3EF00 *r;
    f64 dxf;
    s32 i;
    u32 y;
    void *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12;
    s32 dx;

    x = 0x194;
    y = 0x7F;
    dx = 15;
    two = !(o->b3A4 < 2);
    three = o->b3A4 < o->b61;
    tbl = D_800D4D80;
    r = &tbl[o->b60];
    n1 = r->n[0];
    n2 = r->n[1];
    n3 = r->n[2];
    n4 = r->n[3];
    for (i = 0; i < n1; i++, x += dx) {
        p1 = o->a2C8;
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
        m = D_800D4D80[o->b60].sub[o->b3A4].v[0];
        for (i = 0; i < m; i++, x += dx) {
            p2 = o->a304;
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
    if (three) {
        m = D_800D4D80[o->b60].sub[o->b61].v[0] - D_800D4D80[o->b60].sub[o->b3A4].v[0];
        for (i = 0; i < m; i++, x += dx) {
            p3 = o->a2B4;
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
    }
    y += 0x16;
    x = 0x194;
    for (i = 0; i < n2; i++, x += dx) {
        p4 = o->a2DC;
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
    if (two) {
        m = D_800D4D80[o->b60].sub[o->b3A4].v[1];
        for (i = 0; i < m; i++, x += dx) {
            p5 = o->a304;
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
    }
    if (three) {
        m = D_800D4D80[o->b60].sub[o->b61].v[1] - D_800D4D80[o->b60].sub[o->b3A4].v[1];
        for (i = 0; i < m; i++, x += dx) {
            p6 = o->a2B4;
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
    y += 0x16;
    x = 0x194;
    for (i = 0; i < n3; i++, x += dx) {
        p7 = o->a2F0;
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
        m = D_800D4D80[o->b60].sub[o->b3A4].v[2];
        for (i = 0; i < m; i++, x += dx) {
            p8 = o->a304;
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
    if (three) {
        m = D_800D4D80[o->b60].sub[o->b61].v[2] - D_800D4D80[o->b60].sub[o->b3A4].v[2];
        for (i = 0; i < m; i++, x += dx) {
            p9 = o->a2B4;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p9, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
    y += 0x16;
    x = 0x194;
    for (i = 0; i < n4; i++, x += dx) {
        p10 = o->a2C8;
        dxf = (s32)x;
        if ((s32)x < 0) {
            dxf += 4294967296.0;
        }
        fx = dxf;
        dyf = (s32)y;
        if ((s32)y < 0) {
            dyf += 4294967296.0;
        }
        func_800B1AC4(p10, fx, (f32)dyf, 1.0f, 1.0f);
    }
    if (two) {
        m = D_800D4D80[o->b60].sub[o->b3A4].v[3];
        for (i = 0; i < m; i++, x += dx) {
            p11 = o->a304;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p11, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
    if (three) {
        m = D_800D4D80[o->b60].sub[o->b61].v[3] - D_800D4D80[o->b60].sub[o->b3A4].v[3];
        for (i = 0; i < m; i++, x += dx) {
            p12 = o->a2B4;
            dxf = (s32)x;
            if ((s32)x < 0) {
                dxf += 4294967296.0;
            }
            fx = dxf;
            dyf = (s32)y;
            if ((s32)y < 0) {
                dyf += 4294967296.0;
            }
            func_800B1AC4(p12, fx, (f32)dyf, 1.0f, 1.0f);
        }
    }
    x = 0x194;
    for (i = 0; i < o->b66; i++, x += 0xE) {
        func_800B1AC4(o->a304, (f32)(s32)x, 217.0f, 1.0f, 1.0f);
    }
}
