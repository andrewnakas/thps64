/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 331/524 positional instructions agree (target525); weighted-product register classes and constructor temporary scheduling differ. */
#include "common.h"

typedef struct {
    s16 x, y, z;
} S3_80063AD8;

struct V3_80063AD8 {
    s32 x, y, z;
    V3_80063AD8() {}
    V3_80063AD8(s32 a, s32 b, s32 c) { x = a; y = b; z = c; }
};

struct B3_80063AD8 {
    s8 x, y, z;
    B3_80063AD8() {}
    B3_80063AD8(s32 a, s32 b, s32 c) { x = a; y = b; z = c; }
};

typedef struct {
    s16 m[3][3];
    s32 t[3];
} M_80063AD8;

typedef struct {
    V3_80063AD8 a;
    V3_80063AD8 b;
    u8 pad18[0x68 - 0x18];
    s32 hit;
    V3_80063AD8 p;
    S3_80063AD8 n;
    u8 pad7E[0x100 - 0x7E];
} Col_80063AD8;

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
} Vt_80063AD8;

typedef struct {
    u8 pad0[4];
    V3_80063AD8 pos;
    S3_80063AD8 rot;
    u8 pad16[0x48 - 0x16];
    Vt_80063AD8 *vt;
    u8 pad4C[0x84 - 0x4C];
    V3_80063AD8 vel;
    u8 pad90[0xB8 - 0x90];
    S3_80063AD8 d;
    u8 padBE[0x2A4 - 0xBE];
    u32 flags;
    u8 pad2A8[0x322 - 0x2A8];
    u16 cnt;
    u16 type;
    u16 w[3];
    u16 timer;
    S3_80063AD8 tgt;
} Obj_80063AD8;

extern s32 D_800C0E20;

extern "C" s32 func_80022E14(s32, s32);
extern "C" s32 func_80022E54(const V3_80063AD8 &, const V3_80063AD8 &);
extern "C" void func_800232DC(S3_80063AD8 *, M_80063AD8 *);
extern "C" void func_80039E60(s32, s32, s32);
extern "C" void func_80046C1C(S3_80063AD8 *, S3_80063AD8 *);
extern "C" void func_80046CB0(S3_80063AD8 *);
extern "C" void func_80046D00(S3_80063AD8 *);
extern "C" V3_80063AD8 func_80047014(const V3_80063AD8 &, const V3_80063AD8 &);
extern "C" void func_800470E0(V3_80063AD8 *, B3_80063AD8 *);
extern "C" void func_800472F8(V3_80063AD8 *);
extern "C" s32 func_800474C8(V3_80063AD8 *);
extern "C" s32 func_80049D60(s32);
extern "C" void func_8005CCD8(Col_80063AD8 *, s32);
extern "C" void func_8005DF8C(Col_80063AD8 *, s32);



static inline s32 iabs_80063AD8(s32 x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}



#define VCPY_80063AD8(d, s)                                                                                    \
    {                                                                                                          \
        s32 _x = (s).x;                                                                                        \
        s32 _y = (s).y;                                                                                        \
        s32 _z = (s).z;                                                                                        \
        (d).x = _x;                                                                                            \
        (d).y = _y;                                                                                            \
        (d).z = _z;                                                                                            \
    }

#define ABS_80063AD8(x) ((x) < 0 ? -(x) : (x))

extern "C" void func_80063AD8(Obj_80063AD8 *o) {
    M_80063AD8 mtx;
    Col_80063AD8 col;
    V3_80063AD8 np;
    V3_80063AD8 v;
    B3_80063AD8 sh;
    s32 h;
    s32 len;
    s32 i;

    if (o->timer != 0 && --o->timer == 0) {
        o->vt[2].fn((u8 *)o + o->vt[2].delta);
        return;
    }
    if (!(o->flags & 0x20)) {
        return;
    }
    func_80046D00(&o->tgt);
    o->d.x = (o->tgt.x - o->rot.x) >> 5;
    o->d.y = (o->tgt.y - o->rot.y) >> 5;
    o->d.z = (o->tgt.z - o->rot.z) >> 5;
    func_80046CB0(&o->d);
    if (iabs_80063AD8(o->d.x) < 40 && ABS_80063AD8(o->tgt.x - o->rot.x) > 40) {
        o->d.x = o->d.x < 0 ? -40 : 40;
    }
    if (iabs_80063AD8(o->d.y) < 40 && ABS_80063AD8(o->tgt.y - o->rot.y) > 40) {
        o->d.y = o->d.y < 0 ? -40 : 40;
    }
    if (iabs_80063AD8(o->d.z) < 40 && ABS_80063AD8(o->tgt.z - o->rot.z) > 40) {
        o->d.z = o->d.z < 0 ? -40 : 40;
    }
    func_80046C1C(&o->rot, &o->d);
    func_80046D00(&o->rot);
    func_800232DC(&o->rot, &mtx);
    #define SABS_80063AD8(x) ({ s32 _t = (x); if (_t < 0) { _t = -_t; } _t; })
    h = (o->w[0] * SABS_80063AD8(mtx.m[1][0]) + o->w[1] * SABS_80063AD8(mtx.m[1][1]) +
         o->w[2] * SABS_80063AD8(mtx.m[1][2])) >> 1;
    v = o->vel;
    v.y += 0x8000;
    sh = B3_80063AD8(6, 6, 6);
    func_800470E0(&v, &sh);
    func_800472F8(&v);
    np = func_80047014(o->pos, v);
    {
    V3_80063AD8 hv;

    hv = v;
    hv.y = 0;
    len = func_800474C8(&hv);
    i = 0;
    while (1) {
        if (i >= 3) {
            break;
        }
        VCPY_80063AD8(col.a, o->pos)
        VCPY_80063AD8(col.b, np)
        func_8005CCD8(&col, 0);
        func_8005DF8C(&col, 1);
        if (col.hit == 0) {
            if (v.y > 0) {
                VCPY_80063AD8(col.a, np)
                col.b = col.a;
                col.a.y -= h;
                col.b.y += h;
                func_8005CCD8(&col, 0);
                func_8005DF8C(&col, 1);
            }
            if (col.hit == 0) {
                o->pos = np;
                o->vel = v;
                break;
            }
        }
        if (o->cnt < 5) {
            s32 snd;

            switch (o->type) {
            case 1:
                snd = func_80049D60(2) == 0 ? 0x67 : 0x66;
                func_80039E60(snd, 10000, 0);
                break;
            case 3:
                func_80039E60(0x28, 10000, 0);
                break;
            case 2:
                if (D_800C0E20 != 0) {
                    snd = func_80049D60(2) == 0 ? 0x6B : 0x6A;
                } else {
                    snd = func_80049D60(2) + 0x53;
                }
                func_80039E60(snd, 10000, 0);
                break;
            case 4:
                snd = func_80049D60(2) == 0 ? 0x51 : 0x50;
                func_80039E60(snd, 10000, 0);
                break;
            case 5:
                snd = func_80049D60(2) + 0x53;
                func_80039E60(snd, 10000, 0);
                break;
            }
        }
        o->cnt++;
        V3_80063AD8 n(col.n.x, col.n.y, col.n.z);
        s32 d = func_80022E54(v, n);
        v.x -= func_80022E14(n.x, d) * 2;
        v.y -= func_80022E14(n.y, d) * 2;
        v.z -= func_80022E14(n.z, d) * 2;
        sh = B3_80063AD8(3, 2, 3);
        if (ABS_80063AD8(v.y) <= 0xBFFF) {
            sh.y = 0;
            sh.z = 2;
            sh.x = 2;
        } else {
            o->tgt.y = func_80049D60(0x1000);
            if (o->cnt == 1) {
                o->tgt.x += (func_80049D60(2) * 2 - 1) << 10;
                if ((o->type == 2 || o->type == 4) &&
                    ((o->tgt.x == 0x800 && o->tgt.z == 0) || (o->tgt.x == 0 && o->tgt.z == 0x800))) {
                    o->tgt.x = (func_80049D60(2) * 2 - 1) << 10;
                }
            }
            if (o->cnt == 1) {
                o->tgt.z += (func_80049D60(3) - 1) << 10;
                if ((o->type == 2 || o->type == 4) &&
                    ((o->tgt.x == 0x800 && o->tgt.z == 0) || (o->tgt.x == 0 && o->tgt.z == 0x800))) {
                    o->tgt.z = (func_80049D60(2) * 2 - 1) << 10;
                }
            }
            if (o->cnt == 1 && len < 0x12) {
                o->tgt.y = o->rot.y + func_80049D60(0x400) - 0x200;
                o->tgt.x = (o->rot.x + 0x200) & 0xC00;
                o->tgt.z = (o->rot.z + 0x200) & 0xC00;
            }
        }
        func_800470E0(&v, &sh);
        func_800472F8(&v);
        if (o->cnt >= 19) {
            o->rot.x = o->tgt.x;
            o->rot.z = o->tgt.z;
            func_800232DC(&o->rot, &mtx);
            v.z = 0;
            v.y = 0;
            v.x = 0;
            o->flags &= ~0x20;
            o->timer = 10;
            return;
        }
        np.x = col.p.x + func_80022E14(col.n.x, h);
        np.y = col.p.y + func_80022E14(col.n.y, h);
        np.z = col.p.z + func_80022E14(col.n.z, h);
        i++;
    }
    if (o->cnt >= 19) {
        o->rot.x = o->tgt.x;
        o->rot.z = o->tgt.z;
        v.z = 0;
        v.y = 0;
        v.x = 0;
        o->flags &= ~0x20;
        o->timer = 10;
    }
    }
}
