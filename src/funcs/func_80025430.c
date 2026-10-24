/* cflags: -frerun-cse-after-loop */
#include "common.h"

typedef struct {
    s32 x, y, z;
} IVec25430;

typedef struct {
    f32 m[12];
    IVec25430 pos;
} Frame25430;

typedef struct {
    u8 pad0[0xC];
    f32 x0;
    f32 y0;
    f32 z0;
    f32 x1;
    f32 y1;
    f32 z1;
    IVec25430 pos;
} Src25430;

typedef struct {
    u8 pad0[0x84];
    s32 x;
    s32 y;
    s32 z;
} Cam25430;

void func_8002572C(void *, Frame25430 *, void *, f32, f32);
void func_8002611C(void *);
s32 func_80035110(Src25430 *);
void func_80039E60(s32, s32, s32);
void func_8009CAD0(Frame25430 *);
void func_8009CC10(Frame25430 *, f32);
void func_800A68A0(void *);
extern u8 D_80017160[];
extern Cam25430 *D_800DE7A8;

typedef struct {
    f32 x, y, z;
} V3f25430;

static inline void vset_(V3f25430 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void vscale_(V3f25430 *v, f32 s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

static inline f32 fabs_(f32 x, f32 zero) {
    if (!(zero <= x)) {
        return -x;
    }
    return x;
}

void *func_80025430(u8 *arg0, Src25430 *arg1) {
    Frame25430 fr;
    Frame25430 *pf;
    V3f25430 v;
    f32 dx;
    f32 dz;
    f32 w;
    f32 h;
    s32 cond;
    f32 zero;
    f32 t;
    Cam25430 *cam;
    s32 i;
    u8 *p;

    *(void **)arg0 = D_80017160;
    p = arg0 + 8;
    i = 15;
    do {
        func_800A68A0(p);
        i--;
        p += 0xB8;
    } while (i != -1);
    t = arg1->x0 - arg1->x1;
    zero = 0.0f;
    dx = fabs_(t, zero);
    dz = arg1->z0 - arg1->z1;
    if (!(zero <= dz)) {
        dz = -dz;
    }
    cond = 1;
    if (!(dx < dz)) {
        cond = 0;
    }
    if (cond) {
        func_8009CC10(&fr, 1.5707964f);
        w = arg1->z1 - arg1->z0;
    } else {
        func_8009CAD0(&fr);
        w = arg1->x1 - arg1->x0;
    }
    h = arg1->y1 - arg1->y0;
    fr.pos = arg1->pos;
    pf = &fr;
    cam = D_800DE7A8;
    dz = cam->x / 4096;
    vset_(&v, dz, cam->y / 4096, cam->z / 4096);
    vscale_(&v, 30.0f);
    v.y -= 31.25f;
    *(s32 *)(arg0 + 0xB88) = func_80035110(arg1);
    func_80039E60(0x2A, 10000, 0);
    func_8002572C(arg0, pf, &v, w, h);
    func_8002611C(arg0);
    return arg0;
}
