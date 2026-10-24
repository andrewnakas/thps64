/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* D4 from F2's 678/690 draft: (1) the matrix copy goes through an inline (mcopy_) and both func_800223C0 calls through
 * an inline (rot_), so CSE has no &m pseudo and the address is rematerialised like the game; (2) the first atan result
 * is ay itself (block local) instead of ey; (3) the unk818 block counts in its own block-scoped nb. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_8006ACC4;

typedef struct {
    s16 x, y, z, w;
} A4_8006ACC4;

typedef struct {
    s16 m[3][3];
    s32 t[3];
} M_8006ACC4;

typedef struct {
    s32 type;
    s32 val;
} Ev_8006ACC4;

typedef struct {
    s32 active;
    u8 pad4[4];
    u8 *buf;
    u8 padC[4];
    u32 *ptr;
    u32 acc;
    s32 left;
    s32 count;
    u8 pad20[0x78 - 0x20];
    s32 anim;
    s32 animIdx;
    s32 frame;
    A4_8006ACC4 rot;
    A4_8006ACC4 prevRot;
    V3_8006ACC4 pos;
    V3_8006ACC4 prevPos;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
} Rec_8006ACC4;

typedef struct {
    u8 pad0[4];
    V3_8006ACC4 pos;
    u8 pad10[0x208 - 0x10];
    u32 unk208;
    u8 pad20C[0x21C - 0x20C];
    s16 unk21C;
    u16 unk21E;
    u8 pad220[0x818 - 0x220];
    s32 unk818;
    s32 unk81C;
    u8 pad820[0x82C - 0x820];
    s32 unk82C;
    u8 pad830[0x884 - 0x830];
    M_8006ACC4 mtx;
} Sk_8006ACC4;

extern Sk_8006ACC4 *D_800D61A8;
extern volatile s32 D_800D613C;
extern Rec_8006ACC4 D_800DC618;
extern Rec_8006ACC4 D_800DC6D8;
extern s32 D_800DC614;
extern s32 D_800DC798[];
extern s32 D_800DC7B4[];
extern s32 D_800DC7D0[];
extern s32 D_800DC7EC[];
extern s32 D_800DC808[];
extern Ev_8006ACC4 D_800DC82C[];
extern s32 D_800DC91C;
extern s32 D_800DC920;
extern s32 D_800DC924;
extern s32 D_800DC928;
extern s32 D_800DC92C;
extern s32 D_800DC930;

void func_8006A380(Rec_8006ACC4 *, s32, s32);
s32 func_80023190(s32, s32);
void func_800223C0(s32, M_8006ACC4 *);
static inline void rot_8006ACC4(s32 a, M_8006ACC4 *m) { func_800223C0(a, m); }
static inline void mcopy_8006ACC4(M_8006ACC4 *d, M_8006ACC4 *s) { *d = *s; }
void func_80046DAC(V3_8006ACC4 *, V3_8006ACC4 *, s32 *);

static inline s32 nbits_8006ACC4(s32 v) {
    s32 n = 2;
    s32 t;

    if (v < 0) {
        for (t = -2; v < t; t <<= 1) {
            n++;
        }
    } else {
        for (t = 2; v >= t; t <<= 1) {
            n++;
        }
    }
    return n;
}

static inline void popEv_8006ACC4(s32 *type, s32 *val) {
    Ev_8006ACC4 *e = D_800DC82C;
    s32 n = D_800DC91C;

    *type = e[n].type;
    *val = e[n].val;
    D_800DC91C = (n + 1) % 30;
}

static inline void emit3_8006ACC4(Rec_8006ACC4 *r, s32 sel, s32 n, s32 x, s32 y, s32 z) {
    s32 i;
    s32 *tbl;

    i = 0;
    tbl = sel ? D_800DC7B4 : D_800DC798;
    for (; i < 6; i++) {
        if (tbl[i] >= n) {
            break;
        }
    }
    func_8006A380(r, D_800DC7EC[i], D_800DC808[i]);
    func_8006A380(r, x, tbl[i]);
    func_8006A380(r, y, tbl[i]);
    func_8006A380(r, z, tbl[i]);
}

void func_8006ACC4(Sk_8006ACC4 *sk) {
    Rec_8006ACC4 *r;
    s32 ex, ey, ez;
    s32 n, n2, n3;
    s32 i;
    s32 *tbl;
    M_8006ACC4 unused;
    V3_8006ACC4 tmp;
    M_8006ACC4 m;
    s32 k;
    s32 px, py, pz;

    if (sk == D_800D61A8) {
        r = &D_800DC618;
    } else {
        r = &D_800DC6D8;
    }
    if ((u32)(r->ptr + 6) >= (u32)(r->buf + 0x5DC0)) {
        Rec_8006ACC4 *q;

        if (sk == D_800D61A8) {
            q = &D_800DC618;
        } else {
            q = &D_800DC6D8;
        }
        if (q->active == 1 && q->left != 32) {
            *q->ptr++ = q->acc;
            q->acc = 0;
            q->left = 32;
        }
        q->active = 0;
        D_800DC614 = 0;
        return;
    }
    r->count++;
    px = r->pos.x * 2 - r->prevPos.x;
    py = r->pos.y * 2 - r->prevPos.y;
    pz = r->pos.z * 2 - r->prevPos.z;
    ex = (sk->pos.x >> 12) - px;
    ey = (sk->pos.y >> 12) - py;
    ez = (sk->pos.z >> 12) - pz;
    r->prevPos = r->pos;
    k = 12;
    func_80046DAC(&tmp, &sk->pos, &k);
    r->pos = tmp;
    n = nbits_8006ACC4(ex);
    n2 = nbits_8006ACC4(ey);
    n3 = nbits_8006ACC4(ez);
    if (n < n2) {
        n = n2;
    }
    if (n < n3) {
        n = n3;
    }
    emit3_8006ACC4(r, 0, n, ex, ey, ez);

    mcopy_8006ACC4(&m, &sk->mtx);
    m.m[0][1] = -m.m[0][1];
    m.m[1][1] = -m.m[1][1];
    m.m[2][1] = -m.m[2][1];
    {
        s32 ax, ay, az;

        ay = func_80023190(m.m[0][2], m.m[2][2]) & 0xFFF;
        rot_8006ACC4(-ay, &m);
        ax = func_80023190(-m.m[1][2], m.m[2][2]) & 0xFFF;
        rot_8006ACC4(-ax, &m);
        az = func_80023190(m.m[1][0], m.m[1][1]) & 0xFFF;
        r->rot.x = ax;
        r->rot.y = ay;
        r->rot.z = az;
        r->rot.x &= 0xFFF;
        r->rot.y &= 0xFFF;
        r->rot.z &= 0xFFF;
    }
    ex = (r->rot.x - r->prevRot.x + 0x4000) & 0xFFF;
    ey = (r->rot.y - r->prevRot.y + 0x4000) & 0xFFF;
    ez = (r->rot.z - r->prevRot.z + 0x4000) & 0xFFF;
    if (ex >= 0x800) {
        ex -= 0x1000;
    }
    if (ey >= 0x800) {
        ey -= 0x1000;
    }
    if (ez >= 0x800) {
        ez -= 0x1000;
    }
    r->prevRot = r->rot;
    n = nbits_8006ACC4(ex);
    n2 = nbits_8006ACC4(ey);
    n3 = nbits_8006ACC4(ez);
    if (n < n2) {
        n = n2;
    }
    if (n < n3) {
        n = n3;
    }
    emit3_8006ACC4(r, 1, n, ex, ey, ez);

    if (sk->unk82C == r->anim) {
        func_8006A380(r, 0, 1);
    } else {
        func_8006A380(r, (sk->unk82C << 1) | 1, 5);
    }
    r->anim = sk->unk82C;
    if (sk->unk21E == r->animIdx) {
        func_8006A380(r, 0, 1);
    } else {
        func_8006A380(r, (sk->unk21E << 1) | 1, 8);
    }
    r->animIdx = sk->unk21E;
    ex = sk->unk21C - r->frame;
    if ((u32)ex < 4) {
        func_8006A380(r, ex << 1, 3);
    } else {
        func_8006A380(r, (sk->unk21C << 1) | 1, 9);
    }
    r->frame = sk->unk21C;
    func_8006A380(r, (sk->unk208 >> 1) & 1, 1);
    if (sk->unk818 == 0) {
        func_8006A380(r, 0, 1);
        r->unkAC = 0;
        r->unkB0 = 0;
    } else {
        s32 nb;

        func_8006A380(r, 1, 1);
        ex = sk->unk81C - (r->unkAC + r->unkB0);
        nb = 0;
        if (ex != 0) {
            s32 t;

            nb = 2;
            if (ex < 0) {
                for (t = -2; ex < t; t <<= 1) {
                    nb++;
                }
            } else {
                for (t = 2; ex >= t; t <<= 1) {
                    nb++;
                }
            }
        }
        i = 0;
        tbl = D_800DC7D0;
        for (; i < 6; i++) {
            if (tbl[i] >= nb) {
                break;
            }
        }
        func_8006A380(r, D_800DC7EC[i], D_800DC808[i]);
        func_8006A380(r, ex, tbl[i]);
        r->unkAC = sk->unk81C;
        r->unkB0 = ex;
    }
    ex = D_800D613C - r->unkB4;
    if (ex >= 6) {
        s32 t = D_800D613C + 5;

        r->unkB4 = t - ex;
        ex = 5;
    } else {
        r->unkB4 = D_800D613C;
    }
    func_8006A380(r, ex - 2, 2);
    if (D_800DC91C != D_800DC920) {
        s32 type;
        s32 val;

        func_8006A380(r, 1, 1);
        popEv_8006ACC4(&type, &val);
        if (type == 1) {
            func_8006A380(r, 1, 1);
            func_8006A380(r, val, 8);
        } else if (type == 2) {
            func_8006A380(r, 0, 1);
            func_8006A380(r, val, 8);
        }
    } else {
        func_8006A380(r, 0, 1);
    }
    if (D_800DC924 != -1 || D_800DC928 != -1 || D_800DC92C != -1 || D_800DC930 != -1) {
        func_8006A380(r, 1, 1);
        if (sk == D_800D61A8) {
            if (D_800DC924 != -1) {
                func_8006A380(r, 1, 1);
                func_8006A380(r, D_800DC924, 2);
                D_800DC924 = -1;
            } else {
                func_8006A380(r, 0, 1);
            }
        } else {
            if (D_800DC928 != -1) {
                func_8006A380(r, 1, 1);
                func_8006A380(r, D_800DC928, 2);
                D_800DC928 = -1;
            } else {
                func_8006A380(r, 0, 1);
            }
        }
        if (sk == D_800D61A8) {
            if (D_800DC92C != -1) {
                func_8006A380(r, 1, 1);
                func_8006A380(r, D_800DC92C, 8);
                D_800DC92C = -1;
                return;
            }
        } else {
            if (D_800DC930 != -1) {
                func_8006A380(r, 1, 1);
                func_8006A380(r, D_800DC930, 8);
                D_800DC930 = -1;
                return;
            }
        }
    }
    func_8006A380(r, 0, 1);
}
