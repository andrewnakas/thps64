#include "common.h"

typedef struct {
    s32 x, y, z;
} IVec269C4;

typedef struct {
    f32 x, y, z;
} FVec269C4;

typedef struct {
    u8 pad0[4];
    s32 pos[3];
    u8 pad10[0x884 - 0x10];
    s16 m[3][3];
    u8 pad896[0x2208 - 0x896];
    FVec269C4 r0;
    u8 pad2214[4];
    FVec269C4 r1;
    u8 pad2224[4];
    FVec269C4 r2;
    u8 pad2234[4];
    FVec269C4 p;
} Obj269C4;

void func_800269C4(Obj269C4 *arg0) {
    IVec269C4 a;
    IVec269C4 c;
    IVec269C4 b;
    FVec269C4 t;
    FVec269C4 s1;
    FVec269C4 s2;
    s32 x;
    s32 y;
    s32 z;

    a.x = x = arg0->m[0][0];
    a.y = y = arg0->m[1][0];
    a.z = z = arg0->m[2][0];
    b.x = arg0->m[0][1];
    b.y = arg0->m[1][1];
    b.z = arg0->m[2][1];
    c.x = arg0->m[0][2];
    c.y = arg0->m[1][2];
    c.z = arg0->m[2][2];
    {
        f32 fx, fy, fz, nx, ny, nz;
        fx = x * 0.000244140625f;
        fy = y * 0.000244140625f;
        fz = z * 0.000244140625f;
        s1.x = fx;
        s1.y = fy;
        s1.z = fz;
        nx = -s1.x;
        ny = -s1.y;
        nz = -s1.z;
        t.x = nx;
        t.y = ny;
        t.z = nz;
        arg0->r0 = t;
    }
    {
        f32 fx, fy, fz, nx, ny, nz;
        fx = b.x * 0.000244140625f;
        fy = b.y * 0.000244140625f;
        fz = b.z * 0.000244140625f;
        s2.x = fx;
        s2.y = fy;
        s2.z = fz;
        nx = -s2.x;
        ny = -s2.y;
        nz = -s2.z;
        t.x = nx;
        t.y = ny;
        t.z = nz;
        arg0->r1 = t;
    }
    {
        f32 fx, fy, fz, nx, ny, nz;
        fx = c.x * 0.000244140625f;
        fy = c.y * 0.000244140625f;
        fz = c.z * 0.000244140625f;
        s1.x = fx;
        s1.y = fy;
        s1.z = fz;
        nx = -s1.x;
        ny = -s1.y;
        nz = -s1.z;
        t.x = nx;
        t.y = ny;
        t.z = nz;
        arg0->r2 = t;
    }
    {
        f32 fx, fy, fz;
        fx = arg0->pos[0] * 0.000244140625f;
        fy = arg0->pos[1] * 0.000244140625f;
        fz = arg0->pos[2] * 0.000244140625f;
        t.x = fx;
        t.y = fy;
        t.z = fz;
    }
    arg0->p = t;
}
