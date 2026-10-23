#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3_24BC4;

void func_8009C8EC(f32 *);
void func_8009D8B4(f32 *, Vec3_24BC4 *);
void func_800A6D38(void *, s32, f32 *);
extern u32 D_800F5664;

void func_80024BC4(void *arg0) {
    f32 mtx[16];
    Vec3_24BC4 v;
    f32 *m;

    if (D_800F5664 < *(u32 *)((u8 *)arg0 + 0x88)) {
        m = mtx;
        func_8009C8EC(m);
        v.z = 2.0f;
        v.y = 2.0f;
        v.x = 2.0f;
        func_8009D8B4(m, &v);
        func_800A6D38(arg0, 0, m);
    }
}
