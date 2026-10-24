/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    f32 z;
    u8 pad8C[0x658 - 0x8C];
    u8 mtx[0x40];
    f32 m[16];
} Obj800A5648;

void func_8009CAD0(f32 *);
void func_80001A30(f32 *, void *);

void func_800A5648(Obj800A5648 *o) {
    f32 x;
    f32 z;
    f32 len;
    f32 inv;

    x = o->x;
    z = o->z;
    len = __builtin_sqrtf(x * x + z * z);
    if (len == 0.0f) {
        func_8009CAD0(o->m);
    } else {
        inv = 1.0f / len;
        z = z * inv;
        x = x * inv;
        o->m[1] = 0.0f;
        o->m[3] = 0.0f;
        o->m[4] = 0.0f;
        o->m[6] = 0.0f;
        o->m[7] = 0.0f;
        o->m[9] = 0.0f;
        o->m[11] = 0.0f;
        o->m[12] = 0.0f;
        o->m[13] = 0.0f;
        o->m[14] = 0.0f;
        o->m[5] = 1.0f;
        o->m[15] = 1.0f;
        o->m[0] = z;
        o->m[2] = -x;
        o->m[8] = x;
        o->m[10] = z;
    }
    func_80001A30(o->m, o->mtx);
}
