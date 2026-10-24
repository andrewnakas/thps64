/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
/* NON_MATCHING: ratio 0.875 (aln), 301/679 positional instructions agree (target683); iterator addressing, branch lowering of the triangle-flag test and register allocation differ. Review fix: the second (cmd 6) triangle also records its hit after func_80061D7C when unk88 is set, as the game does. */
#include "common.h"

struct Mtx_837C8;

struct Vec3_837C8 {
    f32 x;
    f32 y;
    f32 z;
    Vec3_837C8() {}
    Vec3_837C8(f32 v) { x = y = z = v; }
    Vec3_837C8(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
    Vec3_837C8(const Vec3_837C8 &v) { x = v.x; y = v.y; z = v.z; }
    Vec3_837C8 operator-(Vec3_837C8 b) const { return Vec3_837C8(x - b.x, y - b.y, z - b.z); }
    Vec3_837C8 operator*(const Mtx_837C8 &m) const;
};

struct Mtx_837C8 {
    f32 m[4][4];
    Mtx_837C8() {}
    Mtx_837C8(const Mtx_837C8 &o);
    Vec3_837C8 &trans() { return *(Vec3_837C8 *)m[3]; }
};

extern "C" Mtx_837C8 *func_8009C8EC(Mtx_837C8 *, const Mtx_837C8 *);
extern "C" void func_8009CCC8(Mtx_837C8 *, Mtx_837C8 *);
extern "C" void func_8009D8B4(Mtx_837C8 *, Vec3_837C8 *);

inline Mtx_837C8::Mtx_837C8(const Mtx_837C8 &o) {
    func_8009C8EC(this, &o);
}

inline Vec3_837C8 Vec3_837C8::operator*(const Mtx_837C8 &m) const {
    return Vec3_837C8(x * m.m[0][0] + y * m.m[1][0] + z * m.m[2][0] + m.m[3][0],
                      x * m.m[0][1] + y * m.m[1][1] + z * m.m[2][1] + m.m[3][1],
                      x * m.m[0][2] + y * m.m[1][2] + z * m.m[2][2] + m.m[3][2]);
}

struct Iter_837C8 {
    s32 base;
    s32 cur;
    Iter_837C8(s32 p);
    s32 operator[](s32 k);
};

extern "C" s32 func_80084744(Iter_837C8 *, s32);
extern "C" void func_8008475C(Iter_837C8 *, s32);

inline Iter_837C8::Iter_837C8(s32 p) {
    func_8008475C(this, p);
}

inline s32 Iter_837C8::operator[](s32 k) {
    return cur + func_80084744(this, k);
}

typedef struct {
    s32 data;
    s32 hdr;
} Arr_837C8;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[10];
} Vtx_837C8;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx_837C8;

typedef struct {
    u16 a;
    u16 b;
} TriFlag_837C8;

typedef struct {
    u8 pad0[4];
    u32 flags;
} ChunkHdr_837C8;

typedef struct {
    f32 t;
    Vec3_837C8 n;
    u8 pad10[0xC];
    u16 id;
    u8 pad1E[2];
    void *ent;
    s32 b;
    u8 pad28[8];
    s32 a;
    u8 pad34[4];
} Hit_837C8;

typedef struct {
    u16 id;
    u8 pad2[0x1A];
    s32 unk1C;
} EntInfo_837C8;

typedef struct {
    u8 pad0[2];
    s16 model;
    EntInfo_837C8 *info;
    u8 pad8[0x1C];
    Vec3_837C8 pos;
} Ent_837C8;

typedef struct {
    u8 pad0[0x88];
    u8 unk88;
    u8 pad89[0x1B];
    Vec3_837C8 a;
    Vec3_837C8 b;
} Obj_837C8;

typedef struct {
    s32 *tbl;
} Models_837C8;

typedef struct {
    u8 pad0[4];
    Models_837C8 *models;
} World_837C8;

extern "C" void func_80061D7C(s32, s32);
extern "C" s32 func_800833A8(Vec3_837C8 *, Vec3_837C8 *, Vec3_837C8 *, Vec3_837C8 *, Vec3_837C8 *, f32 *,
                             Vec3_837C8 *);
extern s32 D_800D7364;
extern s32 D_800D7368;
extern World_837C8 *D_800E8A10;
extern Hit_837C8 D_800FBD40[];
extern u8 D_800FC0C0;

static inline void hit837C8(TriFlag_837C8 *fl, f32 t, const Vec3_837C8 &n, Ent_837C8 *ent, u8 &cnt) {
    Hit_837C8 *h = &D_800FBD40[cnt++];

    h->t = t;
    h->n = n;
    h->ent = ent;
    h->id = ent->info->id;
    h->a = fl->a << 16;
    h->b = fl->b;
}

static inline u32 ok837C8(s32 solid, TriFlag_837C8 *fl) {
    u32 f = fl->a << 16;

    if (f & D_800D7368) {
        f = 0;
    } else if (~(D_800D7364 | f) != 0) {
        f = 0;
    } else {
        f >>= 16;
        if (f & 1) {
            f = 0;
        } else if (solid) {
            if (f & 2) {
                f = 1;
            } else {
                f = 0;
            }
        } else {
            if (f & 2) {
                f = 0;
            } else {
                f = 1;
            }
        }
    }
    return f;
}

extern "C" s32 func_800837C8(Obj_837C8 *obj, Ent_837C8 *ent, Mtx_837C8 *mtx) {
    Iter_837C8 it0(D_800E8A10->models->tbl[ent->model]);
    Arr_837C8 va;
    Vec3_837C8 nrm;
    Vec3_837C8 p0;
    Vec3_837C8 p1;
    f32 t;
    u32 vb;
    s32 start;

    va.hdr = it0[2];
    va.data = va.hdr + 8;
    vb = va.data;
    t = 2.0f;
    start = D_800FC0C0;
    if (mtx != NULL) {
        Mtx_837C8 m(*mtx);
        f32 k = 16.0f;

        func_8009D8B4(&m, &Vec3_837C8(k));
        m.m[3][0] *= k;
        m.m[3][1] *= k;
        m.m[3][2] *= k;
        Mtx_837C8 inv;
        func_8009C8EC(&inv, &m);
        func_8009CCC8(&m, &inv);
        p0 = Vec3_837C8(obj->a.x * m.m[0][0] + obj->a.y * m.m[1][0] + obj->a.z * m.m[2][0] + m.m[3][0],
                        obj->a.x * m.m[0][1] + obj->a.y * m.m[1][1] + obj->a.z * m.m[2][1] + m.m[3][1],
                        obj->a.x * m.m[0][2] + obj->a.y * m.m[1][2] + obj->a.z * m.m[2][2] + m.m[3][2]);
        p1 = Vec3_837C8(obj->b.x * m.m[0][0] + obj->b.y * m.m[1][0] + obj->b.z * m.m[2][0] + m.m[3][0],
                        obj->b.x * m.m[0][1] + obj->b.y * m.m[1][1] + obj->b.z * m.m[2][1] + m.m[3][1],
                        obj->b.x * m.m[0][2] + obj->b.y * m.m[1][2] + obj->b.z * m.m[2][2] + m.m[3][2]);
    } else {
        p0 = obj->a - ent->pos;
        p1 = obj->b - ent->pos;
    }
    Iter_837C8 it1(it0[1]);
    s32 n = *(s32 *)it1.base;
    s32 i = 0;
    while (1) {
        if (i >= n) {
            break;
        }
        {
            Iter_837C8 it2(it1[i]);
            if (((ChunkHdr_837C8 *)(it2[0]))->flags & 0x8000) {
                goto next;
            }
            Gfx_837C8 *dl = (Gfx_837C8 *)(it2[1]);
            Arr_837C8 ta;
            ta.hdr = it2[2];
            ta.data = ta.hdr + 4;
            Vec3_837C8 verts[32];
            s32 tri = 0;
            while (1) {
                u32 w0 = dl->w0;
                u32 w1 = dl->w1;
                u32 cmd = w0 >> 24;

                dl++;
                if (cmd == 0xDF) {
                    break;
                }
                if (cmd == 1) {
                    u32 src = (w1 - vb) >> 4;
                    s32 cnt = (w0 >> 12) & 0xFF;
                    s32 dst = ((w0 & 0xFE) >> 1) - cnt;
                    s32 j;

                    j = 0;
                    while (1) {
                        if (j >= cnt) {
                            break;
                        }
                        Vtx_837C8 *v = &((Vtx_837C8 *)vb)[src + j];
                        verts[j + dst] = Vec3_837C8(v->x, v->y, v->z);
                        j++;
                    }
                } else if (cmd - 5 < 2) {
                    if (ok837C8(obj->unk88, (TriFlag_837C8 *)(ta.data + tri * 4))) {
                        s32 a = (w0 >> 17) & 0x7F;
                        s32 b = (w0 >> 9) & 0x7F;
                        s32 c = (w0 >> 1) & 0x7F;

                        if (func_800833A8(&p0, &p1, &verts[a], &verts[b], &verts[c], &t, &nrm)) {
                            if (obj->unk88) {
                                func_80061D7C(ent->info->unk1C, 1);
                            } else {
                                if (mtx != NULL) {
                                    Mtx_837C8 m(*mtx);

                                    m.trans() = Vec3_837C8(0.0f);
                                    Vec3_837C8 v(nrm);

                nrm = v * m;
                                    f32 len = __builtin_sqrtf(nrm.x * nrm.x + nrm.y * nrm.y + nrm.z * nrm.z);
                                    if (len != 0.0f) {
                                        f32 inv = 1.0f / len;

                                        nrm.x *= inv;
                                        nrm.y *= inv;
                                        nrm.z *= inv;
                                    }
                                }
                                hit837C8((TriFlag_837C8 *)(ta.data + tri * 4), t, nrm, ent, D_800FC0C0);
                            }
                        }
                    }
                    tri++;
                    if (cmd == 6) {
                        if (ok837C8(obj->unk88, (TriFlag_837C8 *)(ta.data + tri * 4))) {
                            s32 a = (w1 >> 17) & 0x7F;
                            s32 b = (w1 >> 9) & 0x7F;
                            s32 c = (w1 >> 1) & 0x7F;

                            if (func_800833A8(&p0, &p1, &verts[a], &verts[b], &verts[c], &t, &nrm)) {
                                /* unlike the first triangle, the game records this hit even when unk88 is
                                   set (after func_80061D7C it jumps to the hit store at 800841AC) */
                                if (obj->unk88) {
                                    func_80061D7C(ent->info->unk1C, 1);
                                } else if (mtx != NULL) {
                                    Mtx_837C8 m(*mtx);

                                    m.trans() = Vec3_837C8(0.0f);
                                    Vec3_837C8 v(nrm);

                                    nrm = v * m;
                                    f32 len = __builtin_sqrtf(nrm.x * nrm.x + nrm.y * nrm.y + nrm.z * nrm.z);
                                    if (len != 0.0f) {
                                        f32 inv = 1.0f / len;

                                        nrm.x *= inv;
                                        nrm.y *= inv;
                                        nrm.z *= inv;
                                    }
                                }
                                hit837C8((TriFlag_837C8 *)(ta.data + tri * 4), t, nrm, ent, D_800FC0C0);
                            }
                        }
                        tri++;
                    }
                }
            }
        }
    next:
        i++;
    }
    return D_800FC0C0 - start;
}
