/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
/* NON_MATCHING: reorg: LO live at 0x9B8 target, bgtzl fallthrough reaches bne w/o label; p-in-LO -> spill t5, best 1295/1296. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* NEAR-MISS func_80074254 (G17): 1295/1296 instructions equal (was ~1024 in TC's draft). The only difference:
 * in the second 0x62E test (k = k * r2) GCC leaves the mult after `beqz a0` (game: mult; beqz; nop; mflo, i.e. the
 * mult went into the delay slot like the first test's). reorg fills that slot only when LO is dead at the branch
 * target (.L 0x9B8: lw 0x68C; bgtz; lw TGT; bne): mark_target_live_regs sees LO live (the reload copy `mflo` has
 * no REG_DEAD note; the forward scan stops at the second conditional branch, bne, with no label on the
 * fallthrough). A product temp kept in LO (`p = k * r2; k = p >> 12;`) gets the slot filled but the sra input
 * reload then uses spill reg t5 (`mflo t5; sra a1, t5`) instead of a1; `k = p; k >>= 12` is merged back by
 * combine. 25 statement-shape combinations of both tests (work/q/G17/t/combo.py), C++ and flag variants tried.
 * Fixes vs TC's draft: per-block temporaries (t = t * t; t >>= 12), `s *= t` for the 0x5E0 scaling, r1/r2 as s32
 * with (u32) shifts, k = r1 * k; k >>= 12, qmul on c directly, pointer locals for the tail quaternion calls,
 * block-local flag, VSET macro for the 0x1000 vectors, pos pointer in the 0x648 == 4 block.
 * Z1 (instrumented reorg.c): opposite_needed at the 0x9B8 target has LO set. mark_target_live_regs starts from
 * block 32 (last BARRIER is far above), the mflo output-reload copies carry no REG_DEAD lo, so LO is live; the
 * forward scan from 0x9B8 kills it on the bgtzl taken path (label = spill regs dead) but the fallthrough path
 * reaches bne (2nd conditional, jump_count 10) without crossing a label. The first test wins only because label
 * 1433 lies on both of its paths. p-in-LO forms give REG_DEAD lo but the input reload takes spill reg t5 (spill
 * regs are t5-t8 only), else-if (the two tests are exclusive) adds a j. Needs a source shape with a label/barrier
 * between 0x9B8 and the bne, or a dying LO before 0x9B8. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80074254;

typedef struct {
    s32 x, y, z, w;
} Q_80074254;

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} M_80074254;

typedef struct {
    V3_80074254 start;
    V3_80074254 end;
    u8 pad18[0x40 - 0x18];
    s32 dist;
    s32 len;
    u8 pad48[0x68 - 0x48];
    s32 hit;
    u8 pad6C[0x88 - 0x6C];
    u8 unk88;
    u8 pad89[0x100 - 0x89];
} Ray_80074254;

void func_800226A0(void *, void *, void *);
s32 func_80022E54(void *, void *);
void func_80042F58(void);
void func_80043264(void *);
void func_8004356C(void *);
void func_80043590(void *);
void func_80046FBC(void *, void *, void *);
s32 func_800470A8(void *, void *);
void func_80047244(void *, void *);
void func_80049C20(void *, void *);
void func_8005CCD8(Ray_80074254 *, s32);
void func_8005DF8C(Ray_80074254 *, s32);
void func_80067528(void *, void *);
void func_800673B0(void *, void *, void *);
void func_800676D0(void *, s32);
void func_800677F8(void *, s32);
void func_80067A48(void *, void *);
void func_80067F30(Q_80074254, Q_80074254, s32, Q_80074254 *);
extern s32 D_800D7238;
extern s32 D_800DE130;
extern s32 D_800DE820;
extern s32 D_800DE9AC;
extern s32 D_800E9038;

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define V3(o) (*(V3_80074254 *)(c + (o)))
#define Q(o) (*(Q_80074254 *)(c + (o)))
#define TGT (*(u8 **)(c + 0x4B4))
#define AVG(a, b) ((S16(a) + S16(b)) >> 1)

static inline s32 scale_80074254(s32 v, s32 s) {
    return (v * s) >> 12;
}

#define CAST(r)            \
    func_8005CCD8(r, 0);   \
    (r)->unk88 = 0;        \
    D_800D7238 = 1;        \
    func_8005DF8C(r, 1);   \
    D_800D7238 = 0

#define VSET_80074254(t, a, b, c) \
    {                             \
        s32 _x = (a);             \
        s32 _y = (b);             \
        s32 _z = (c);             \
        (t).x = _x;               \
        (t).y = _y;               \
        (t).z = _z;               \
    }

static inline void qmul_80074254(u8 *c, Q_80074254 *b) {
    s32 x, y, z, w;

    w = (Q(0x564).w * b->w - Q(0x564).x * b->x - Q(0x564).y * b->y - Q(0x564).z * b->z) >> 12;
    x = (Q(0x564).w * b->x + Q(0x564).x * b->w + Q(0x564).y * b->z - Q(0x564).z * b->y) >> 12;
    y = (Q(0x564).w * b->y + Q(0x564).y * b->w + Q(0x564).z * b->x - Q(0x564).x * b->z) >> 12;
    z = (Q(0x564).w * b->z + Q(0x564).z * b->w + Q(0x564).x * b->y - Q(0x564).y * b->x) >> 12;
    Q(0x564).x = x;
    Q(0x564).y = y;
    Q(0x564).z = z;
    Q(0x564).w = w;
}

void func_80074254(u8 *c) {
    Ray_80074254 ray;
    M_80074254 m;
    V3_80074254 va;
    V3_80074254 vb;
    V3_80074254 vc;
    V3_80074254 vd;
    V3_80074254 ve;
    V3_80074254 vf;
    V3_80074254 vg;
    V3_80074254 vh;
    Q_80074254 q1;
    Q_80074254 q2;
    Q_80074254 q3;
    V3_80074254 vi;
    V3_80074254 vj;
    M_80074254 m2;
    s32 r1;
    s32 r2;
    s32 k;
    s32 f;
    s32 dot;
    Ray_80074254 *r;
    u8 *p4;
    Q_80074254 *pq;
    Q_80074254 *pout;
    Q_80074254 *ptmp;
    s32 x;
    s32 x0;
    s32 y0;
    s32 z0;
    s32 y;
    s32 z;

    if (D_800E9038 != 0 || D_800DE820 != 0 || U32(0x610) < 13) {
        return;
    }
    r = &ray;
    func_80067A48(c + 0x564, &m);
    if (++U8(0x648) >= 3) {
        U8(0x648) = 0;
        I32(0x64C)++;
    }
    if (U8(0x648) == 2) {
        U16(0x63C) = U16(0x62C);
        x0 = I32(0x4);
        y0 = I32(0x8);
        z0 = I32(0xC);
        ray.start.x = x0;
        ray.start.y = y0;
        ray.start.z = z0;
        x = I32(0x4);
        y = I32(0x8);
        z = I32(0xC);
        ray.end.x = x;
        ray.end.y = y;
        ray.end.z = z;
        ray.end.y += 0xBB8000;
        func_8005CCD8(r, 0);
        ray.unk88 = 0;
        func_8005DF8C(r, 1);
        if (ray.hit != 0) {
            I32(0x650) = ray.dist;
            if (ray.dist < 0x78) {
                s32 t = ((0x78 - ray.dist) << 12) / 120;

                t = t * t;
                U16(0x62C) = t >> 15;
            } else {
                U16(0x62C) = 0;
            }
        } else {
            if (*(s32 *)(TGT + 0x82C) == 1) {
                U16(0x62C) = 0x200;
            } else {
                U16(0x62C) = U16(0x63C);
            }
            I32(0x650) = -1;
        }
        if (*(s32 *)(TGT + 0x82C) == 2) {
            vd.x = 0;
            vd.y = D_800DE130 << 13;
            vd.z = 0;
            func_800226A0(&m, &vd, &vc);
            ray.start.x = I32(0x4);
            ray.start.y = I32(0x8);
            ray.start.z = I32(0xC);
            ray.end.x = I32(0x4) + vc.x;
            ray.end.y = I32(0x8) + vc.y;
            ray.end.z = I32(0xC) + vc.z;
            CAST(&ray);
            U16(0x62C) = 0;
            if (ray.hit != 0) {
                s32 t;

                if (ray.len == 0) {
                    ray.len = 1;
                }
                t = ((ray.len - ray.dist) << 12) / ray.len;
                t = t * t;
                t >>= 12;
                U16(0x62C) += scale_80074254(t, 300);
                I32(0x650) = ray.dist;
            } else {
                I32(0x650) = D_800DE130;
            }
        }
    }
    vd.z = 0;
    vd.y = 0;
    vd.x = -(D_800DE130 << 13);
    func_800226A0(&m, &vd, &va);
    vb.x = -va.x;
    vb.y = -va.y;
    vb.z = -va.z;
    if (I32(0x5D8) != 0) {
        if (U8(0x648) == 0) {
            U16(0x638) = U16(0x628);
            if (I32(0x64C) & 1) {
                ray.start.x = I32(0x4);
                ray.start.y = I32(0x8);
                ray.start.z = I32(0xC);
                ray.end.x = I32(0x4) + va.x;
                ray.end.y = I32(0x8) + va.y;
                ray.end.z = I32(0xC) + va.z;
            } else {
                ray.start.x = I32(0x4D0);
                ray.start.y = I32(0x4D4);
                ray.start.z = I32(0x4D8);
                ray.end.x = ((I32(0x4) + I32(0x4D0)) >> 1) + va.x;
                ray.end.y = ((I32(0x8) + I32(0x4D4)) >> 1) + va.y;
                ray.end.z = ((I32(0xC) + I32(0x4D8)) >> 1) + va.z;
            }
            CAST(&ray);
            U16(0x628) = 0;
            if (ray.hit != 0) {
                s32 t;

                if (ray.len == 0) {
                    ray.len = 1;
                }
                t = ((ray.len - ray.dist) << 12) / ray.len;
                t = t * t;
                t >>= 12;
                {
                    s32 s = S16(0x5E0);

                    s *= t;
                    U16(0x628) = s >> 12;
                }
            }
        }
        if (U8(0x648) == 1) {
            U16(0x63A) = U16(0x62A);
            if (I32(0x64C) & 1) {
                ray.start.x = I32(0x4);
                ray.start.y = I32(0x8);
                ray.start.z = I32(0xC);
                ray.end.x = I32(0x4) + vb.x;
                ray.end.y = I32(0x8) + vb.y;
                ray.end.z = I32(0xC) + vb.z;
            } else {
                ray.start.x = I32(0x4D0);
                ray.start.y = I32(0x4D4);
                ray.start.z = I32(0x4D8);
                ray.end.x = ((I32(0x4) + I32(0x4D0)) >> 1) + vb.x;
                ray.end.y = ((I32(0x8) + I32(0x4D4)) >> 1) + vb.y;
                ray.end.z = ((I32(0xC) + I32(0x4D8)) >> 1) + vb.z;
            }
            CAST(&ray);
            U16(0x62A) = 0;
            if (ray.hit != 0) {
                s32 t;

                if (ray.len == 0) {
                    ray.len = 1;
                }
                t = ((ray.len - ray.dist) << 12) / ray.len;
                t = t * t;
                t >>= 12;
                {
                    s32 s = S16(0x5E0);

                    s *= t;
                    U16(0x62A) = -(s >> 12);
                }
            }
        }
    }
    vd.x = 0;
    vd.y = 0;
    vd.z = -(D_800DE130 << 12);
    func_800226A0(&m, &vd, &vc);
    vd.x = 0x64000;
    vd.y = 0;
    vd.z = 0;
    func_800226A0(&m, &vd, &vh);
    if (I32(0x68C) <= 0 && *(s32 *)(TGT + 0x82C) != 2) {
        if (S16(0x5E4) != 0) {
            r1 = 0;
            U16(0x63E) = U16(0x62E);
            r2 = 0;
            ray.start.x = I32(0x4D0) + (vh.x >> 1);
            ray.start.y = I32(0x4D4) + (vh.y >> 1);
            ray.start.z = I32(0x4D8) + (vh.z >> 1);
            ray.end.x = I32(0x4D0) - vh.x + vc.x * 2;
            ray.end.y = I32(0x4D4) - vh.y + vc.y * 2;
            ray.end.z = I32(0x4D8) - vh.z + vc.z * 2;
            CAST(&ray);
            if (ray.hit != 0) {
                if (ray.len == 0) {
                    ray.len = 1;
                }
                r2 = ((ray.len - ray.dist) << 12) / ray.len;
                r2 = r2 * r2;
                r2 = (u32)r2 >> 12;
            }
            ray.start.x = I32(0x4D0) - (vh.x >> 1);
            ray.start.y = I32(0x4D4) - (vh.y >> 1);
            ray.start.z = I32(0x4D8) - (vh.z >> 1);
            ray.end.x = I32(0x4D0) + vh.x + vc.x * 2;
            ray.end.y = I32(0x4D4) + vh.y + vc.y * 2;
            ray.end.z = I32(0x4D8) + vh.z + vc.z * 2;
            CAST(&ray);
            if (ray.hit != 0) {
                if (ray.len == 0) {
                    ray.len = 1;
                }
                r1 = ((ray.len - ray.dist) << 12) / ray.len;
                r1 = r1 * r1;
                r1 = (u32)r1 >> 12;
            }
            k = 0x568;
            if (*(s32 *)(TGT + 0x82C) == 4) {
                r1 = 0;
                r2 = 0;
            }
            U16(0x62E) = 0;
            if (r1 != 0 || r2 != 0) {
                f = AVG(0x63A, 0x62A) != 0 && -AVG(0x63A, 0x62A) > AVG(0x638, 0x628);
                if (f) {
                    k = r1 * k;
                    k >>= 12;
                    U16(0x62E) = -k;
                }
                f = AVG(0x638, 0x628) != 0 && -AVG(0x63A, 0x62A) < AVG(0x638, 0x628);
                if (f) {
                    k = k * r2;
                    k >>= 12;
                    U16(0x62E) = k;
                }
            }
        }
    }
    if (I32(0x68C) > 0 || *(s32 *)(TGT + 0x82C) == 2) {
        U16(0x62E) = 0;
        U16(0x63E) = 0;
    }
    func_80049C20(&ve, c + 0x84);
    if (U8(0x648) == 4) {
        V3_80074254 *pos;

        U16(0x640) = U16(0x630);
        func_80047244(&ve, &D_800DE130);
        pos = &V3(0x4);
        ray.end.x = I32(0x4) + ve.x;
        ray.end.y = I32(0x8) + ve.y;
        ray.end.z = I32(0xC) + ve.z;
        ray.start.x = I32(0x4);
        ray.start.y = I32(0x8);
        ray.start.z = I32(0xC);
        CAST(&ray);
        func_80049C20(&ve, c + 0x84);
        func_80046FBC(&q1, TGT + 4, pos);
        func_80049C20(&vf, &q1);
        U16(0x630) = 0;
        if (ray.hit != 0) {
            s32 t;

            if (ray.len == 0) {
                ray.len = 1;
            }
            t = ((ray.len - ray.dist) << 12) / ray.len;
            U16(0x630) = (t * t) >> 16;
        }
    }
    p4 = c + 4;
    if (AVG(0x63C, 0x62C) != 0) {
        pq = &Q(0x564);
        pout = &q2;
        ptmp = &q3;
        func_800676D0(ptmp, AVG(0x63C, 0x62C));
        func_800673B0(pout, pq, ptmp);
        Q(0x564) = q2;
    }
    if (AVG(0x638, 0x628) != 0) {
        pq = &Q(0x564);
        pout = &q1;
        ptmp = &q2;
        func_800677F8(ptmp, AVG(0x638, 0x628));
        func_800673B0(pout, pq, ptmp);
        Q(0x564) = q1;
    }
    if (AVG(0x63A, 0x62A) != 0) {
        pq = &Q(0x564);
        pout = &q1;
        ptmp = &q2;
        func_800677F8(ptmp, AVG(0x63A, 0x62A));
        func_800673B0(pout, pq, ptmp);
        Q(0x564) = q1;
    }
    if (S16(0x630) != 0) {
        func_80046FBC(&q1, TGT + 4, p4);
        func_80049C20(&vf, &q1);
        func_80043590(&ve);
        func_8004356C(&vf);
        func_80042F58();
        func_80043264(&vg);
        vg.x *= S16(0x630);
        vg.y *= S16(0x630);
        vg.z *= S16(0x630);
        func_80067528(&q1, &vg);
        qmul_80074254(c, &q1);
    }
    if (AVG(0x63E, 0x62E) != 0) {
        func_800677F8(&q1, AVG(0x63E, 0x62E));
        qmul_80074254(c, &q1);
    }
    if (I32(0x5A4) != 0) {
        VSET_80074254(q3, 0, 0x1000, 0);
        VSET_80074254(q1, 0, 0x1000, 0);
        func_800226A0(&m, &q1, &q2);
        vi.x = q2.x;
        vi.y = q2.y;
        vi.z = q2.z;
        func_80067A48(c + 0x594, &m2);
        VSET_80074254(q1, 0, 0, 0x1000);
        func_800226A0(&m2, &q1, &q2);
        vj.x = q2.x;
        vj.y = q2.y;
        vj.z = q2.z;
        if (func_80022E54(&vi, &vj) >= 0) {
            dot = func_80022E54(&vi, &vj);
        } else {
            dot = -func_80022E54(&vi, &vj);
        }
        func_80022E54(&q3, &vj);
        func_80022E54(&q3, &vj);
        if (I32(0x650) < 0 || dot >= 0x76D) {
            I32(0x5A4) = 0;
        }
    }
    if (U32(0x6D0) < 4 || func_800470A8(c + 0x4D0, c + 0x4C0) != 0 || *(s32 *)(TGT + 0x450) != 0) {
        if (I32(0x5A4) == 0 && I32(0x650) >= 0) {
            q1 = Q(0x554);
            func_80067F30(q1, Q(0x564), 0x600, &Q(0x594));
            I32(0x5A4) = 1;
        }
        if (D_800DE9AC == 0 && I32(0x5A4) != 0) {
            f = AVG(0x638, 0x628) == 0 && AVG(0x63A, 0x62A) == 0 && AVG(0x63E, 0x62E) == 0;
            if (f) {
                q1 = Q(0x554);
                func_80067F30(q1, Q(0x564), 0x5E7, &Q(0x594));
            }
            Q(0x564) = Q(0x594);
            f = AVG(0x63A, 0x62A) != 0 && AVG(0x638, 0x628) == 0 && AVG(0x63E, 0x62E) == 0;
            if (f) {
                pq = &Q(0x564);
                pout = &q1;
                ptmp = &q2;
                func_800677F8(ptmp, AVG(0x63A, 0x62A));
                func_800673B0(pout, pq, ptmp);
                Q(0x564) = q1;
            } else {
                s32 f2 = AVG(0x63A, 0x62A) == 0 && AVG(0x638, 0x628) != 0 && AVG(0x63E, 0x62E) == 0;

                if (f2) {
                    pq = &Q(0x564);
                    pout = &q1;
                    ptmp = &q2;
                    func_800677F8(ptmp, AVG(0x638, 0x628));
                    func_800673B0(pout, pq, ptmp);
                    Q(0x564) = q1;
                }
            }
        }
    } else {
        I32(0x5A4) = 0;
        S16(0x6EC) = 0;
    }
    if (S16(0x6EC) != 0) {
        func_800677F8(&q1, S16(0x6EC));
        qmul_80074254(c, &q1);
    }
}
