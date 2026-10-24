#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3_80048E68;

typedef struct {
    Vec3_80048E68 a;
    Vec3_80048E68 b;
    u8 pad18[0x50];
    s32 unk68;
    u8 pad6C[0x94];
} Query80048E68;

void func_8005CCD8(Query80048E68 *, s32);
void func_8005DF8C(Query80048E68 *, s32);
extern s32 D_800D7248;

s32 func_80048E68(Vec3_80048E68 *arg0, Vec3_80048E68 *arg1) {
    Query80048E68 q;
    Query80048E68 *p = &q;
    s32 x, y, z;

    x = arg0->x;
    y = arg0->y;
    z = arg0->z;
    q.a.x = x;
    q.a.y = y;
    q.a.z = z;
    x = arg1->x;
    y = arg1->y;
    z = arg1->z;
    q.b.x = x;
    q.b.y = y;
    q.b.z = z;
    D_800D7248 = 1;
    func_8005CCD8(p, 0);
    func_8005DF8C(p, 1);
    D_800D7248 = 0;
    return q.unk68 == 0;
}
