/* compiler: cc1plus */
/* cflags: -O2 */
/* NON_MATCHING: 446/462 instructions agree; matrix-pointer setup, indexed add operands and display-list scheduling differ. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxB4AD8;

struct Vec3B4AD8 {
    f32 x, y, z;
    Vec3B4AD8() {}
};

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    u16 flag;
    u8 pad8[8];
} TriB4AD8;

typedef struct {
    s32 unk0;
    s32 unk4;
} TexB4AD8;

typedef struct {
    Vec3B4AD8 *data;
    s32 *hdr;
} ArrVB4AD8;

typedef struct {
    TriB4AD8 *data;
    s32 *hdr;
} ArrTB4AD8;

typedef struct {
    TexB4AD8 *tex;
    s32 flags;
} HdrB4AD8;

typedef struct {
    s32 unk0;
    s32 unk4;
} TblB4AD8;

typedef struct {
    u8 pad0[0x40];
    s32 mtx[16];
    s32 count;
} ObjB4AD8;

typedef struct {
    u8 pad0[0x60];
    f32 m[4][4];
} CamB4AD8;

extern "C" s32 func_800B713C(TblB4AD8 *, s32);
extern "C" void func_80001BE8(f32 (*)[4], s32);
extern "C" void func_8009CB1C(void *, Vec3B4AD8 *, s32);
extern "C" void func_800C000C(void *);
extern "C" void func_800B9DE0(s32);
extern GfxB4AD8 *D_800F36A4;
extern CamB4AD8 *D_800EA560;
extern s32 D_800EEC90;
extern s32 D_800EEC94;
extern Vec3B4AD8 D_800FC650;
extern Vec3B4AD8 D_800FC660;

static inline void xformB4AD8(Vec3B4AD8 *r, Vec3B4AD8 *v, f32 (*m)[4]) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    f32 rx = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    f32 ry = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    f32 rz = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
    r->x = rx;
    r->y = ry;
    r->z = rz;
}

static inline void xformLocalB4AD8(Vec3B4AD8 *r, Vec3B4AD8 *v, f32 (*m)[4], const f32 &m00) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    f32 rx = x * m00 + y * m[1][0] + z * m[2][0] + m[3][0];
    f32 ry = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    f32 rz = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
    r->x = rx;
    r->y = ry;
    r->z = rz;
}



static inline void cpyB4AD8(Vec3B4AD8 *r, Vec3B4AD8 *a) {
    r->x = a->x;
    r->y = a->y;
    r->z = a->z;
}

static inline void addB4AD8(Vec3B4AD8 *r, Vec3B4AD8 *a, Vec3B4AD8 *b) {
    f32 x = a->x + b->x;
    f32 y = a->y + b->y;
    f32 z = a->z + b->z;
    r->x = x;
    r->y = y;
    r->z = z;
}

static inline void subB4AD8(Vec3B4AD8 *r, Vec3B4AD8 *a, Vec3B4AD8 *b) {
    f32 x = a->x - b->x;
    f32 y = a->y - b->y;
    f32 z = a->z - b->z;
    r->x = x;
    r->y = y;
    r->z = z;
}

static inline void scaleB4AD8(Vec3B4AD8 *r, f32 k, Vec3B4AD8 *a) {
    f32 x = k * a->x;
    f32 y = k * a->y;
    f32 z = k * a->z;
    r->x = x;
    r->y = y;
    r->z = z;
}

static inline void crossB4AD8(Vec3B4AD8 *r, Vec3B4AD8 *a, Vec3B4AD8 *b) {
    f32 x = a->y * b->z - a->z * b->y;
    f32 y = a->z * b->x - a->x * b->z;
    f32 z = a->x * b->y - a->y * b->x;
    r->x = x;
    r->y = y;
    r->z = z;
}

extern "C" void func_800B4AD8(ObjB4AD8 *arg0, TblB4AD8 *arg1) {
    f32 m[4][4];
    ArrVB4AD8 av;
    ArrTB4AD8 at;
    s32 *mtxp;
    s32 ntris;
    HdrB4AD8 *hdr;
    TexB4AD8 *tex;
    s32 i;
    s32 j;
    s32 s4;
    s32 s2;
    s32 loaded;
    TriB4AD8 *tr;
    Vec3B4AD8 *v2;
    f32 len;
    f32 s;
    CamB4AD8 *cam;
    s32 cnt;
    f32 (*mp)[4];

    hdr = (HdrB4AD8 *)(arg1->unk4 + func_800B713C(arg1, 0));
    if (!(hdr->flags & 1)) {
        return;
    }
    tex = hdr->tex;
    {
        GfxB4AD8 *_g;
        GfxB4AD8 *_h;
        (_g = D_800F36A4++, _g->w0 = 0xD9000000, _g->w1 = 0, _h = D_800F36A4++, _h->w0 = 0xD9FFFFFF, _h->w1 = 0x210005);
    }
    func_800B9DE0(tex->unk4);
    mp = m;
    i = 0;
    while (1) {
        if (i >= arg0->count) {
            break;
        }
        mtxp = &arg0->mtx[i];
        func_80001BE8(m, *mtxp);
        av.hdr = (s32 *)(arg1->unk4 + func_800B713C(arg1, 1));
        av.data = (Vec3B4AD8 *)(av.hdr + 1);
        at.hdr = (s32 *)(arg1->unk4 + func_800B713C(arg1, 2));
        at.data = (TriB4AD8 *)(at.hdr + 2);
        ntris = *at.hdr;
        Vec3B4AD8 pts[16];
        Vec3B4AD8 t;
        Vec3B4AD8 b;
        Vec3B4AD8 d;
        Vec3B4AD8 p;
        Vec3B4AD8 n;
        Vec3B4AD8 e1;
        Vec3B4AD8 q;
        Vec3B4AD8 e2;
        Vec3B4AD8 r;
        Vec3B4AD8 f;
        u8 out[0x40];
        j = 0;
        cnt = *av.hdr;
        while (1) {
            if (j >= cnt) {
                break;
            }
            xformLocalB4AD8(&t, &av.data[j], mp, m[0][0]);
            pts[j] = t;
            j++;
        }
        loaded = 0;
        cam = D_800EA560;
        if (D_800EEC90 == 0) {
            D_800EEC90 = 1;
            {
                Vec3B4AD8 *o = &D_800FC650;
                o->x = 0.0f;
                o->y = 0.0f;
                o->z = 0.0f;
            }
        }
        if (D_800EEC94 == 0) {
            D_800EEC94 = 1;
            {
                Vec3B4AD8 *o = &D_800FC660;
                o->x = 0.0f;
                o->y = 0.0f;
                o->z = 1.0f;
            }
        }
        xformB4AD8(&t, &D_800FC650, cam->m);
        xformB4AD8(&b, &D_800FC660, cam->m);
        p.x = t.x;
        p.y = t.y;
        p.z = t.z;
        d.x = b.x - t.x;
        d.y = b.y - t.y;
        d.z = b.z - t.z;
        s4 = 0;
        while (1) {
            if (s4 >= ntris) {
                break;
            }
            s2 = 0;
            while (1) {
                if (s2 >= 3) {
                    break;
                }
                tr = &at.data[s4 + s2];
                if (tr->flag != 0) {
                    Vec3B4AD8 &first = pts[tr->a];
                    v2 = &pts[tr->b];
                    cpyB4AD8(&n, &d);
                    addB4AD8(&p, v2, &n);
                    cpyB4AD8(&q, &first);
                    subB4AD8(&e1, &p, &q);
                    cpyB4AD8(&r, v2);
                    subB4AD8(&e2, &p, &r);
                    crossB4AD8(&n, &e1, &e2);
                    len = __builtin_sqrtf(n.x * n.x + n.y * n.y + n.z * n.z);
                    if (len != 0.0f) {
                        len = 1.0f / len;
                        n.x *= len;
                        n.y *= len;
                        n.z *= len;
                    }
                    s = (f32)tr->c * 0.0625f;
                    scaleB4AD8(&e2, s, &n);
                    addB4AD8(&q, &first, &e2);
                    {
                        s32 c;
                        f32 fx = tr->a;
                        f32 fy = tr->b;
                        f32 fz = (c = tr->c);
                        f.x = fx;
                        f.y = fy;
                        f.z = fz;
                        subB4AD8(&e1, &q, &f);
                        func_8009CB1C(out, &e1, c);
                    }
                    func_800C000C(out);
                    loaded = 0;
                } else if (loaded == 0) {
                    GfxB4AD8 *_g = D_800F36A4++;
                    _g->w0 = 0xDA380003;
                    loaded = 1;
                    _g->w1 = *mtxp;
                }
                {
                    GfxB4AD8 *_g = D_800F36A4++;
                    _g->w0 = 0x01001000 | (((s2 + 1) & 0x7F) << 1);
                    _g->w1 = (u32)tr;
                }
                s2++;
            }
            s4 += 3;
            {
                GfxB4AD8 *_g = D_800F36A4++;
                _g->w0 = 0x05000204;
                _g->w1 = 0;
            }
        }
        i++;
    }
}
