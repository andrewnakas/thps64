/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec800DA14;

typedef struct {
    Vec800DA14 right;
    f32 pad0C;
    Vec800DA14 up;
    f32 pad1C;
    Vec800DA14 fwd;
} Basis800DA14;

#define CROSS(o, a, b)                     \
    {                                      \
        f32 ax = (a).x;                    \
        f32 ay = (a).y;                    \
        f32 az = (a).z;                    \
        f32 bx = (b).x;                    \
        f32 by = (b).y;                    \
        f32 bz = (b).z;                    \
        (o).x = ay * bz - az * by;         \
        (o).y = az * bx - ax * bz;         \
        (o).z = ax * by - ay * bx;         \
    }

#define NORM(v)                                                       \
    {                                                                 \
        f32 len = __builtin_sqrtf((v).x * (v).x + (v).y * (v).y + (v).z * (v).z); \
        if (len != 0.0f) {                                            \
            f32 inv = 1.0f / len;                                     \
            (v).x *= inv;                                             \
            (v).y *= inv;                                             \
            (v).z *= inv;                                             \
        }                                                             \
    }

void func_8009DA14(Basis800DA14 *arg0, Vec800DA14 *arg1) {
    Vec800DA14 t;
    Vec800DA14 *u;
    Vec800DA14 *f;

    u = &arg0->up;
    *u = *arg1;
    CROSS(t, arg0->right, (*u));
    arg0->fwd = t;
    f = &arg0->fwd;
    NORM((*f));
    CROSS(t, (*u), (*f));
    arg0->right = t;
    NORM(arg0->right);
}
