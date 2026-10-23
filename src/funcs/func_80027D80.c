#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_27D80;

typedef struct {
    Vec3i_27D80 a;
    Vec3i_27D80 b;
    u8 pad18[0x68 - 0x18];
    s32 hit;
    u8 pad6C[0xF8 - 0x6C];
    u8 *obj;
    s32 padFC;
} Ray_27D80;

void func_800278AC(void *, s32, void *);
void func_8005CCD8(Ray_27D80 *, s32);
void func_8005DF8C(Ray_27D80 *, s32);

void func_80027D80(void *arg0) {
    Ray_27D80 ray;
    Ray_27D80 *r;

    r = &ray;

    ray.a.x = (*(s32 *)((u8 *)(arg0) + 4));
    ray.a.y = (*(s32 *)((u8 *)(arg0) + 8));
    ray.a.z = (*(s32 *)((u8 *)(arg0) + 0xC));
    ray.b = ray.a;
    ray.b.y += 0x01F40000;
    func_8005CCD8(r, 0);
    func_8005DF8C(r, 1);
    if (ray.hit != 0) {
        func_800278AC(arg0, *(s32 *)(ray.obj + 0x14), ray.obj + 4);
    }
}
