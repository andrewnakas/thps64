/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_4D718;

typedef struct {
    f32 x, y, z;
} Vec3f_4D718;

typedef struct {
    Vec3i_4D718 a;
    Vec3i_4D718 b;
    u8 pad18[0x68 - 0x18];
    s32 hit;
    Vec3i_4D718 pos;
    u8 pad78[0xA4 - 0x78];
    Vec3f_4D718 fa;
    Vec3f_4D718 fb;
    u8 padBC[0xF8 - 0xBC];
    u8 *obj;
    s32 padFC;
} Ray_4D718;

typedef struct {
    u8 pad0[4];
    Vec3i_4D718 pos;
    u8 pad10[0x84 - 0x10];
    Vec3i_4D718 vel;
    u8 pad90[0x16C - 0x90];
    Vec3i_4D718 pos2;
} Obj_4D718;

typedef struct {
    u8 pad0[0x7D4];
    s32 unk7D4;
    u8 pad7D8[0x2208 - 0x7D8];
    Vec3f_4D718 dir2;
    u8 pad2214[0x2228 - 0x2214];
    Vec3f_4D718 dir1;
    u8 pad2234[0x2368 - 0x2234];
    s8 count;
    u8 pad2369[3];
    Vec3f_4D718 fpos;
    Vec3f_4D718 fvel;
} Sk_4D718;

void func_800278AC(void *, s32, void *);
void func_8005CCD8(Ray_4D718 *, s32);
void func_8005DF8C(Ray_4D718 *, s32);

#define ITOF_4D718(d, v)                  \
    {                                     \
        f32 x_;                           \
        f32 y_;                           \
        f32 z_;                           \
        x_ = (v).x * 0.000244140625f;     \
        y_ = (v).y * 0.000244140625f;     \
        z_ = (v).z * 0.000244140625f;     \
        (d).x = x_;                       \
        (d).y = y_;                       \
        (d).z = z_;                       \
    }

#define COPYI_4D718(d, v)                 \
    {                                     \
        s32 x_;                           \
        s32 y_;                           \
        s32 z_;                           \
        x_ = (v).x;                       \
        y_ = (v).y;                       \
        z_ = (v).z;                       \
        (d).x = x_;                       \
        (d).y = y_;                       \
        (d).z = z_;                       \
    }

#define SCALE_4D718(d, s, v)              \
    {                                     \
        f32 x_;                           \
        f32 y_;                           \
        f32 z_;                           \
        x_ = (s) * (v).x;                 \
        y_ = (s) * (v).y;                 \
        z_ = (s) * (v).z;                 \
        (d).x = x_;                       \
        (d).y = y_;                       \
        (d).z = z_;                       \
    }

#define ADD_4D718(d, a, b)                \
    {                                     \
        f32 x_;                           \
        f32 y_;                           \
        f32 z_;                           \
        x_ = (a).x + (b).x;               \
        y_ = (a).y + (b).y;               \
        z_ = (a).z + (b).z;               \
        (d).x = x_;                       \
        (d).y = y_;                       \
        (d).z = z_;                       \
    }

#define SUB_4D718(d, a, b)                \
    {                                     \
        f32 x_;                           \
        f32 y_;                           \
        f32 z_;                           \
        x_ = (a).x - (b).x;               \
        y_ = (a).y - (b).y;               \
        z_ = (a).z - (b).z;               \
        (d).x = x_;                       \
        (d).y = y_;                       \
        (d).z = z_;                       \
    }

void func_8004D718(Obj_4D718 *o, Vec3i_4D718 pos) {
    Ray_4D718 ray;
    Ray_4D718 *p;
    Vec3f_4D718 base;
    Vec3f_4D718 r;
    Vec3f_4D718 t;
    Vec3f_4D718 t2;
    Sk_4D718 *sk;
    s32 found;
    f32 dy;
    f32 d;
    f32 step;
    f32 up;
    f32 scale;

    p = &ray;
    sk = (Sk_4D718 *)o;
    if (sk->unk7D4 != 0) {
        sk->count = 0;
        ITOF_4D718(base, o->pos);
        sk->fpos = base;
        ITOF_4D718(base, o->vel);
        sk->fvel = base;
        return;
    }
    ray.a.x = pos.x;
    ray.a.y = pos.y;
    ray.a.z = pos.z;
    ray.b = ray.a;
    ray.b.y += 0x01F40000;
    func_8005CCD8(p, 0);
    func_8005DF8C(p, 1);
    ITOF_4D718(base, pos);
    found = 0;
    dy = 0.0f;
    step = 300.0f;
    up = 8000.0f;
    scale = 4096.0f;
    while (1) {
        if (!(dy < step)) {
            break;
        }
        d = 2.0f;
        while (1) {
            if (!(d < 200.0f)) {
                break;
            }
            if (ray.hit == 0) {
                SCALE_4D718(t, d, sk->dir1);
                ADD_4D718(r, base, t);
                ray.fa = r;
                ray.fa.y -= dy;
                ray.fb = ray.fa;
                ray.fb.y += up;
                func_8005CCD8(&ray, 1);
                func_8005DF8C(&ray, 1);
                if (ray.hit != 0) {
                    found = 1;
                } else {
                    SCALE_4D718(t2, d, sk->dir1);
                    SUB_4D718(r, base, t2);
                    ray.fa = r;
                    ray.fa.y -= dy;
                    ray.fb = ray.fa;
                    ray.fb.y += up;
                    func_8005CCD8(&ray, 1);
                    func_8005DF8C(&ray, 1);
                    if (ray.hit != 0) {
                        found = 2;
                    } else {
                        SCALE_4D718(t, d, sk->dir2);
                        ADD_4D718(r, base, t);
                        ray.fa = r;
                        ray.fa.y -= dy;
                        ray.fb = ray.fa;
                        ray.fb.y += up;
                        func_8005CCD8(&ray, 1);
                        func_8005DF8C(&ray, 1);
                        if (ray.hit != 0) {
                            found = 3;
                        } else {
                            SCALE_4D718(t, d, sk->dir2);
                            SUB_4D718(r, base, t);
                            ray.fa = r;
                            ray.fa.y -= dy;
                            ray.fb = ray.fa;
                            ray.fb.y += up;
                            func_8005CCD8(&ray, 1);
                            func_8005DF8C(&ray, 1);
                            if (ray.hit != 0) {
                                found = 4;
                            }
                        }
                    }
                }
            }
            if (found != 0) {
                if (dy == 0.0f) {
                    o->pos.x = ray.fa.x * scale;
                    o->pos.y = ray.fa.y * scale;
                    o->pos.z = ray.fa.z * scale;
                } else {
                    COPYI_4D718(o->pos, ray.pos);
                    o->pos.y += -0x1E000;
                }
                o->pos2 = o->pos;
                break;
            }
            d *= 4.0f;
        }
        if (found != 0) {
            break;
        }
        dy += step;
    }
    if (ray.hit != 0) {
        func_800278AC(sk, *(s32 *)(ray.obj + 0x14), ray.obj + 4);
        sk->count = 0;
        ITOF_4D718(r, o->pos);
        sk->fpos = r;
        ITOF_4D718(r, o->vel);
        sk->fvel = r;
        return;
    }
    COPYI_4D718(ray.a, pos);
    ray.a.y += -0x12C000;
    ray.b = ray.a;
    ray.b.y += 0x190000;
    func_8005CCD8(&ray, 0);
    func_8005DF8C(&ray, 1);
    if (ray.hit != 0) {
        COPYI_4D718(o->pos, ray.pos);
        o->pos.y += -0x1E000;
        o->pos2 = o->pos;
        sk->count += 1;
        return;
    }
    sk->count += 2;
    if (sk->count >= 9) {
        if (sk->count >= 11) {
            s32 tmp = o->vel.x;
            o->vel.x = -o->vel.z;
            o->vel.z = tmp;
        }
        r.x = sk->fpos.x;
        r.y = sk->fpos.y;
        r.z = sk->fpos.z;
        o->pos.x = r.x * 4096.0f;
        o->pos.y = r.y * 4096.0f;
        o->pos.z = r.z * 4096.0f;
        o->pos2 = o->pos;
    }
}
