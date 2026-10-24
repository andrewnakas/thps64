/* cflags: -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z, w;
} Quat_80078280;

typedef struct {
    s32 x, y, z;
} Vec_80078280;

typedef struct {
    u8 pad0[0x18];
    Quat_80078280 rot;
    Vec_80078280 pos;
    u16 unk34;
    u8 pad36[6];
    Quat_80078280 q2;
    u8 pad4C[0x20];
    Quat_80078280 q3;
} Obj_80078280;

typedef struct {
    s16 q[4];
    u16 unk8;
    s16 p[3];
} Src_80078280;

s32 func_800233EC(s32);

Obj_80078280 *func_80078280(Obj_80078280 *o, Src_80078280 *s) {
    s32 n;
    s32 k;

    k = 0x1000;
    o->rot.x = 0;
    o->rot.y = 0;
    o->rot.z = 0;
    o->rot.w = k;
    o->q2.x = 0;
    o->q2.y = 0;
    o->q2.z = 0;
    o->q2.w = k;
    o->q3.x = 0;
    o->q3.y = 0;
    o->q3.z = 0;
    o->q3.w = k;
    {
        Quat_80078280 q;
        s32 a, b, c, d;
        a = s->q[0];
        b = s->q[1];
        c = s->q[2];
        d = s->q[3];
        q.x = a;
        q.y = b;
        q.z = c;
        q.w = d;
        o->rot = q;
    }
    n = func_800233EC(o->rot.x * o->rot.x + o->rot.y * o->rot.y + o->rot.z * o->rot.z + o->rot.w * o->rot.w);
    if (n == 0) {
        n = 1;
    }
    o->rot.x = (o->rot.x << 12) / n;
    o->rot.y = (o->rot.y << 12) / n;
    o->rot.z = (o->rot.z << 12) / n;
    o->rot.w = (o->rot.w << 12) / n;
    o->unk34 = s->unk8;
    {
        Vec_80078280 v;
        s32 a, b, c;
        a = s->p[0] << 12;
        b = s->p[1] << 12;
        c = s->p[2] << 12;
        v.x = a;
        v.y = b;
        v.z = c;
        o->pos = v;
    }
    return o;
}
