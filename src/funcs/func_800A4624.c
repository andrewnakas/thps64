/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s8 x0;
    s8 y0;
    s8 z0;
    u8 padB[0x18 - 0xB];
    s8 x1;
    s8 y1;
    s8 z1;
    u8 pad1B[0x20 - 0x1B];
} Light800A4624;

typedef struct {
    u8 pad0[0x20];
    f32 m0[16];
    f32 m1[16];
    f32 m2[16];
    f32 mtx[16];
    f32 m4[16];
    u8 pad160[0x184 - 0x160];
    Light800A4624 *lights;
    u8 pad188[0x6DC - 0x188];
    u8 flip;
} Obj800A4624;

extern void func_8009C8EC(void *, void *);
extern void func_8009CA00(void *, void *, void *);
extern void func_8009CCC8(void *, void *);
extern void func_8009D1BC(void *, f32);
extern void func_8009E0F0(void *, s32, s32);
extern s32 D_800F32B8;

void func_800A4624(Obj800A4624 *arg0, void *arg1) {
    Light800A4624 *l;

    func_8009C8EC(arg0->m0, arg0->m1);
    func_8009C8EC(arg0->m1, arg1);
    if (arg0->flip == 1) {
        func_8009D1BC(arg0->m1, 3.1415927f);
    }
    func_8009CCC8(arg0->mtx, arg0->m1);
    l = &arg0->lights[D_800F32B8];
    func_8009E0F0(l, 0, sizeof(Light800A4624));
    l->x0 = (arg0->mtx[0] * 128.0f < 127.0f) ? (s32)(arg0->mtx[0] * 128.0f) : 0x7F;
    l->y0 = (arg0->mtx[4] * 128.0f < 127.0f) ? (s32)(arg0->mtx[4] * 128.0f) : 0x7F;
    l->z0 = (arg0->mtx[8] * 128.0f < 127.0f) ? (s32)(arg0->mtx[8] * 128.0f) : 0x7F;
    l->x1 = (arg0->mtx[1] * 128.0f < 127.0f) ? (s32)(arg0->mtx[1] * 128.0f) : 0x7F;
    l->y1 = (arg0->mtx[5] * 128.0f < 127.0f) ? (s32)(arg0->mtx[5] * 128.0f) : 0x7F;
    l->z1 = (arg0->mtx[9] * 128.0f < 127.0f) ? (s32)(arg0->mtx[9] * 128.0f) : 0x7F;
    func_8009CA00(arg0->m4, arg0->mtx, arg0->m2);
}
