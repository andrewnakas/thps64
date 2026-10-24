/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3f_800340A0;

typedef struct {
    f32 m[12];
    Vec3f_800340A0 t;
    f32 w;
} Mtx_800340A0;

typedef struct {
    void *a;
    u8 *b;
} Pair_800340A0;

extern u8 D_800FA600[];
extern s32 D_800D36E4;
extern s32 D_800D36E8;
extern u32 D_800F5628;
extern u8 D_800ECFE0[];
extern Pair_800340A0 D_800FA3B0[];
extern Pair_800340A0 D_800FA3D0[];
extern u8 D_800FA5A0[];
extern u8 D_800FA350[];
void func_800A41C8(u8 *);
void func_800A4418(u8 *, f32, f32, f32, f32, f32, f32);
void func_8009C8EC(Mtx_800340A0 *, void *);
void func_8009D1BC(Mtx_800340A0 *, f32);
void func_800B4978(void *);
void func_800B4998(void *, s32, s32);
void func_800A4624(u8 *, Mtx_800340A0 *);
void func_800A4D48(u8 *);
void func_8003908C(void *, void *);
void func_800A426C(u8 *);

static inline void vset(Vec3f_800340A0 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_800340A0(u8 *arg0, s32 arg1) {
    Mtx_800340A0 m;
    Vec3f_800340A0 save;
    Vec3f_800340A0 t;
    u32 flags;
    Mtx_800340A0 *pm;
    f32 fa;
    f32 ne;
    f32 inv;
    f32 d;
    f32 x0, x1, x2, x3;
    s32 i;
    s32 j;
    Pair_800340A0 *tbl;
    s32 started;
    Pair_800340A0 *p;

    if (D_800FA600[arg1] == 0 && (D_800D36E4 == 0 || D_800D36E8 == 0)) {
        return;
    }
    flags = D_800F5628;
    D_800F5628 = flags & 0xFFF8FFFF;
    func_800A41C8(arg0);
    d = *(f32 *)(arg0 + 0x170);
    fa = 20000.0f;
    ne = 200.0f;
    inv = ne / d;
    x0 = *(f32 *)(arg0 + 0x160);
    x1 = *(f32 *)(arg0 + 0x164);
    x2 = *(f32 *)(arg0 + 0x168);
    x3 = *(f32 *)(arg0 + 0x16C);
    func_800A4418(arg0, x0 * inv, x1 * inv, x2 * inv, x3 * inv, ne, fa);
    pm = &m;
    func_8009C8EC(pm, arg0 + 0x60);
    save.x = m.t.x;
    save.y = m.t.y;
    save.z = m.t.z;
    func_8009D1BC(pm, -3.1415927f);
    if (D_800D36E4 != 0) {
        func_800B4978(D_800ECFE0);
        i = 0;
        while (1) {
            if (i >= D_800D36E4) {
                break;
            }
            vset(&t, *(f32 *)(D_800FA3B0[i].b + 0x24) * 0.0625f, *(f32 *)(D_800FA3B0[i].b + 0x28) * 0.0625f, *(f32 *)(D_800FA3B0[i].b + 0x2C) * 0.0625f);
            m.t = t;
            func_800A4624(arg0, &m);
            func_800A4D48(arg0);
            func_8003908C(D_800FA3B0[i].a, D_800FA3B0[i].b);
            i++;
        }
        func_800B4998(D_800ECFE0, 1, 1);
    }
    m.t = save;
    func_800A4624(arg0, &m);
    started = 0;
    j = 0;
    while (1) {
        if (j >= D_800FA600[arg1]) {
            break;
        }
        tbl = D_800FA3D0;
        p = tbl + D_800FA5A0[j + arg1 * 48];
        if (!started) {
            started = 1;
            func_800A4D48(arg0);
            func_800B4978(D_800ECFE0);
        }
        func_8003908C(D_800FA350, p->b);
        j++;
    }
    if (started) {
        func_800B4998(D_800ECFE0, 1, 1);
    }
    D_800FA600[arg1] = 0;
    func_800A426C(arg0);
    D_800F5628 = flags;
}
