#include "common.h"

typedef struct { s16 x, y, z; } Vec3s_Q2;

void func_80022A30(Vec3s_Q2 *, void *);

void func_8005BE00(u8 *arg0) {
    Vec3s_Q2 v;
    s32 a, b, c;

    *(s16 *)(arg0 + 0x886) = -*(s16 *)(arg0 + 0x886);
    *(s16 *)(arg0 + 0x88C) = -*(s16 *)(arg0 + 0x88C);
    *(s16 *)(arg0 + 0x892) = -*(s16 *)(arg0 + 0x892);
    func_80022A30(&v, arg0 + 0x884);
    *(s16 *)(arg0 + 0x886) = -*(s16 *)(arg0 + 0x886);
    *(s16 *)(arg0 + 0x88C) = -*(s16 *)(arg0 + 0x88C);
    *(s16 *)(arg0 + 0x892) = -*(s16 *)(arg0 + 0x892);
    a = v.x;
    b = v.y;
    c = v.z;
    *(s16 *)(arg0 + 0x10) = a;
    *(s16 *)(arg0 + 0x12) = b;
    *(s16 *)(arg0 + 0x14) = c;
}
