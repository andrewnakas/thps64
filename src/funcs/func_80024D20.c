/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3_80024D20;

typedef struct {
    s32 x, y, z;
} Vec3i_80024D20;

typedef struct {
    Vec3i_80024D20 start;
    Vec3i_80024D20 end;
    u8 pad18[0x68 - 0x18];
    s32 hit;
    u8 pad6C[0xF8 - 0x6C];
    u8 *face;
    u8 padFC[4];
} Ray_80024D20;

typedef struct {
    f32 m[12];
    Vec3_80024D20 t;
    f32 w;
} Mtx_80024D20;

void func_800283F4(void *, Vec3_80024D20 *, s32);
void func_8005CCD8(Ray_80024D20 *, s32);
void func_8005DF8C(Ray_80024D20 *, s32);
void func_8009C8EC(void *, Mtx_80024D20 *);
void func_8009CAD0(Mtx_80024D20 *);
void func_8009CB68(Mtx_80024D20 *, Vec3_80024D20 *);
void func_8009DA14(Mtx_80024D20 *, Vec3_80024D20 *);
f32 func_8009F2CC(void);

void func_80024D20(u8 *arg0) {
    Vec3i_80024D20 ip;
    Vec3_80024D20 pos;
    Ray_80024D20 ray;
    Vec3_80024D20 dir0;
    Vec3_80024D20 dir1;
    Mtx_80024D20 mtx;
    Vec3_80024D20 rot;
    f32 a;
    f32 b;
    f32 x;
    u8 *e;
    u8 n;

    *(f32 *)(arg0 + 0x470) = func_8009F2CC() * 0.3;
    if (arg0[0x475] >= 8) {
        *(f32 *)(arg0 + 0x470) = 1000.0f;
        return;
    }
    func_800283F4(*(void **)(arg0 + 0x464), &pos, 0);
    a = 16.0f;
    pos.x *= a;
    pos.y *= a;
    pos.z *= a;
    a = 4096.0f;
    ip.x = pos.x * a;
    ip.y = pos.y * a;
    ip.z = pos.z * a;
    ray.start.x = ip.x;
    ray.start.y = ip.y - 0x28000;
    ray.start.z = ip.z;
    ray.end.x = ip.x;
    ray.end.y = ip.y + 0x320000;
    ray.end.z = ip.z;
    func_8005CCD8(&ray, 0);
    func_8005DF8C(&ray, 1);
    dir0.z = 0.0f;
    dir0.y = 0.0f;
    dir0.x = 0.0f;
    dir1.z = 0.0f;
    dir1.y = 0.0f;
    dir1.x = 0.0f;
    if (ray.hit != 0) {
        dir0 = *(Vec3_80024D20 *)(ray.face + 4);
        dir1 = *(Vec3_80024D20 *)(ray.face + 0x10);
    }
    func_8009CAD0(&mtx);
    x = func_8009F2CC() * 1.5f + 0.5f;
    b = func_8009F2CC() * 1.5f + 0.5f;
    rot.x = x;
    rot.y = 0.0f;
    rot.z = b;
    func_8009CB68(&mtx, &rot);
    func_8009DA14(&mtx, &dir0);
    mtx.t = dir1;
    n = arg0[0x475]++;
    e = arg0 + (n * 0x8C + 4);
    func_8009C8EC(e, &mtx);
    *(f32 *)(e + 0x30) *= 0.0625f;
    *(f32 *)(e + 0x34) *= 0.0625f;
    *(f32 *)(e + 0x38) *= 0.0625f;
    *(f32 *)(e + 0x80) = *(f32 *)(arg0 + 0x46C) * 0.5f;
    e[0x88] = *(s32 *)(*(u8 **)(arg0 + 0x464) + 0x824) == 6;
}
