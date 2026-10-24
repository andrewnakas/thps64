/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    s16 x, y, z, w;
} Vec3s;

typedef struct {
    u32 w0;
    u8 pad4[8];
    union {
        u32 w;
        u16 h;
        u8 b;
    } f;
} Tri523A0;

typedef struct {
    Vec3i start;
    Vec3i end;
    u8 pad18[0x68 - 0x18];
    void *hit;
    u8 pad6C[0x78 - 0x6C];
    Vec3s nrm;
    Tri523A0 *tri;
    u8 pad84[0x100 - 0x84];
} Ray523A0;

typedef struct {
    u8 pad0[4];
    Vec3i pos;
    u8 pad10[0x84 - 0x10];
    Vec3i v84;
    u8 pad90[0x16C - 0x90];
    Vec3i v16C;
    u8 pad178[0x21E - 0x178];
    u16 h21E;
    u8 pad220[0x228 - 0x220];
    s32 v228;
    u8 pad22C[0x450 - 0x22C];
    s32 v450;
    u8 pad454[0x460 - 0x454];
    s32 v460;
    u8 pad464[0x8D0 - 0x464];
    Vec3i v8D0;
    Vec3i v8DC;
    Vec3i v8E8;
} Sk523A0;

s32 func_80022E54(Vec3i *, Vec3i *);
s32 func_800474C8(Vec3i *);
void func_8004A204(Sk523A0 *, s32, s32, s32, s32);
void func_8004C3D8(Sk523A0 *);
s32 func_8004D2D4(Sk523A0 *);
void func_80058804(Sk523A0 *, Vec3s, s32);
void func_8005CCD8(Ray523A0 *, s32);
void func_8005DF8C(Ray523A0 *, s32);
extern s32 D_800D71F4;
extern s32 D_800D71F8;
extern s32 D_800D71FC;
extern s32 D_800D7200;
extern s32 D_800D7204;

static inline void *trace_523A0(Ray523A0 *r, void *hit) {
    if (hit != NULL) {
        D_800D71F4 = r->tri->f.h & 0x40;
        D_800D71F8 = (r->tri->f.b ^ 1) & 1;
        D_800D71FC = ((r->tri->f.w >> 23) ^ 1) & 1;
        D_800D7200 = r->tri->w0 & 0x80;
        D_800D7204 = (r->tri->f.h & 0x1E00) >> 9;
    }
    return hit;
}

static inline s32 dotn_523A0(Vec3s *n, Vec3i *b) {
    Vec3i v;
    s32 x = n->x;
    s32 y = n->y;
    s32 z = n->z;
    v.x = x;
    v.y = y;
    v.z = z;
    return func_80022E54(&v, b);
}

static inline void push_523A0(Vec3s nrm, Sk523A0 *p, s32 s) {
    func_80058804(p, nrm, s);
}

s32 func_800523A0(Sk523A0 *p, s32 n) {
    Ray523A0 r;
    Vec3i v;
    Vec3i save;
    s32 s;
    s32 nx, ny, nz;
    void *h;

    r.start.x = p->pos.x + p->v8E8.x * 30;
    r.start.y = p->pos.y + p->v8E8.y * 30;
    r.start.z = p->pos.z + p->v8E8.z * 30;
    r.end.x = r.start.x + n * p->v8DC.x * (p->v450 ? 70 : 10);
    r.end.y = r.start.y + n * p->v8DC.y * (p->v450 ? 70 : 10);
    r.end.z = r.start.z + n * p->v8DC.z * (p->v450 ? 70 : 10);
    func_8005CCD8(&r, 0);
    func_8005DF8C(&r, 1);
    h = trace_523A0(&r, r.hit);
    if (h == NULL) {
        return 0;
    }
    nx = r.nrm.x;
    ny = r.nrm.y;
    nz = r.nrm.z;
    v.x = nx;
    v.y = ny;
    v.z = nz;
    if ((u32)(func_80022E54(&v, &p->v8E8) + 0x3FF) >= 0x7FF) {
        return 0;
    }
    p->pos = p->v16C;
    save = p->v84;
    s = 0;
    if (p->h21E != 0xC && func_800474C8(&save) >= 7 && p->v450 == 0 && p->v460 == 0) {
        if (dotn_523A0(&r.nrm, &p->v8D0) >= 0xB51) {
            p->v228 = 0x10000;
            func_8004D2D4(p);
            func_8004A204(p, 0xC, s, -1, -1);
            s = 200;
            func_8004C3D8(p);
        }
    }
    push_523A0(r.nrm, p, s);
    r.start.x = p->pos.x;
    r.start.y = p->pos.y;
    r.start.z = p->pos.z;
    r.end.x = r.start.x + r.nrm.x * (p->v450 ? 70 : 10);
    r.end.y = r.start.y + r.nrm.y * (p->v450 ? 70 : 10);
    r.end.z = r.start.z + r.nrm.z * (p->v450 ? 70 : 10);
    func_8005CCD8(&r, 0);
    func_8005DF8C(&r, 1);
    h = trace_523A0(&r, r.hit);
    if (h != NULL) {
        return 0;
    }
    {
        s32 x = r.end.x;
        s32 y = r.end.y;
        s32 z = r.end.z;
        p->pos.x = x;
        p->pos.y = y;
        p->pos.z = z;
    }
    return 1;
}
