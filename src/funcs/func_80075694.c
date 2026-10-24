/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80075694;

typedef struct {
    s32 x, y, z, w;
} Q_80075694;

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} M_80075694;

typedef struct {
    V3_80075694 start;
    V3_80075694 end;
    u8 pad18[0x68 - 0x18];
    s32 hit;
    u8 pad6C[0x88 - 0x6C];
    u8 unk88;
    u8 pad89[0x100 - 0x89];
} Ray_80075694;

typedef union {
    Q_80075694 q;
    M_80075694 m;
} QM_80075694;

typedef union {
    Q_80075694 q;
    V3_80075694 v;
} QV_80075694;

void func_800226A0(void *, void *, void *);
s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
void func_80042F58(void);
void func_80043264(void *);
void func_8004356C(void *);
void func_80043590(void *);
void func_80046FBC(void *, void *, void *);
s32 func_800474C8(void *);
void func_80049C20(void *, void *);
void func_8005CCD8(Ray_80075694 *, s32);
void func_8005DF8C(Ray_80075694 *, s32);
void func_800673B0(void *, void *, void *);
void func_800676D0(void *, s32);
void func_80067A48(void *, void *);
void func_80067B44(void *, void *);
void func_80067F30(Q_80075694, Q_80075694, s32, Q_80075694 *);
void func_80074254(u8 *);
extern s32 D_800D7238;
extern s16 D_800DE12E;
extern s32 D_800DE130;
extern V3_80075694 D_800DE134;
extern s16 D_800DE2F0[];

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define V3(o) (*(V3_80075694 *)(c + (o)))
#define Q(o) (*(Q_80075694 *)(c + (o)))
typedef struct {
    s32 pad0[0x6D4 / 4];
    s32 hist[6];
} Hist_80075694;

#define H ((Hist_80075694 *)c)
#define TGT (*(u8 **)(c + 0x4B4))

static inline s32 mph_80075694(s32 v, s32 d) {
    return v / 34 * 60 / d * 3600 / 5278;
}

static inline s32 scale_80075694(s32 v, s32 k) {
    return v * k / 30;
}

void func_80075694(u8 *c, s32 arg1) {
    V3_80075694 v28;
    V3_80075694 v38;
    V3_80075694 v48;
    V3_80075694 v58;
    Q_80075694 q68;
    Q_80075694 q78;
    QV_80075694 q88;
    M_80075694 m98;
    V3_80075694 vB8;
    Ray_80075694 ray;
    s32 i;
    s32 sum;
    s32 speed;
    s32 k;
    s32 sq;
    s32 n;
    s32 w;
    Q_80075694 *pq;
    Q_80075694 *p78;
    Q_80075694 *p564;
    s32 t;
    s32 flag;

    Q(0x574) = Q(0x554);
    if (TGT == NULL) {
        func_80046FBC(&v58, c + 0x500, c + 0x4D0);
        func_80049C20(&v48, &v58);
        v38.x = 0;
        v38.y = 0x1000;
        v38.z = 0;
        func_80043590(&v38);
        func_8004356C(&v48);
        func_80042F58();
        func_80043264(&v28);
        v28.x >>= 12;
        v28.y >>= 12;
        v28.z >>= 12;
        func_80043590(&v48);
        func_8004356C(&v28);
        func_80042F58();
        func_80043264(&v38);
        v38.x >>= 12;
        v38.y >>= 12;
        v38.z >>= 12;
        D_800DE2F0[0] = v28.x;
        D_800DE2F0[3] = v28.y;
        D_800DE2F0[6] = v28.z;
        D_800DE2F0[1] = v38.x;
        D_800DE2F0[4] = v38.y;
        D_800DE2F0[7] = v38.z;
        D_800DE2F0[2] = v48.x;
        D_800DE2F0[5] = v48.y;
        D_800DE2F0[8] = v48.z;
        q68.x = 0;
        q68.y = 0;
        q68.z = 0;
        q68.w = 0x1000;
        func_80067B44(D_800DE2F0, &q68);
        if (I32(0x4CC) != 0) {
            Q(0x554) = q68;
            I32(0x4CC) = 0;
        } else {
            q78 = Q(0x574);
            func_80067F30(q78, q68, 0x7FF, &Q(0x554));
        }
        V3(0x4) = V3(0x4D0);
        return;
    }
    v28 = V3(0x4);
    v38 = *(V3_80075694 *)(TGT + 0x84);
    if (*(s32 *)(TGT + 0x82C) == 0 || *(s32 *)(TGT + 0x82C) == 4) {
        i = 5;
    shift:
        H->hist[i] = H->hist[i - 1];
        i--;
        if (i > 0) {
            goto shift;
        }
        if (func_800474C8(&v38) >= 0x65) {
            v38.x = 0x64000;
            v38.y = 0;
            v38.z = 0;
        }
        I32(0x6D4) = func_800233B8(func_80022E54(&v38, &v38)) << 6;
    }
    sum = 0;
    for (i = 0; i < 6; i++) {
        sum += I32(0x6D4 + i * 4);
    }
    sum /= 6;
    speed = mph_80075694(sum, 2);
    speed >>= 12;
    I32(0x6D0) = speed;
    n = (D_800DE130 + speed * 4 + I32(0x684)) >> 1;
    I32(0x684) = n;
    v48.x = 0;
    v48.y = 0;
    v48.z = -(n << 12);
    pq = &q68;
    if (I32(0x6C0) >= 4) {
        func_800676D0(&q88, -0x1C2);
        func_800673B0(pq, c + 0x564, &q88);
        q88.v.x = 0;
        q88.v.y = 0;
        q88.v.z = -(D_800DE130 << 12);
        func_80067A48(pq, &m98);
        func_800226A0(&m98, &q88, &vB8);
        ray.start.x = I32(0x4D0);
        ray.start.y = I32(0x4D4);
        ray.start.z = I32(0x4D8);
        ray.end.x = I32(0x4D0) + vB8.x;
        ray.end.y = I32(0x4D4) + vB8.y;
        ray.end.z = I32(0x4D8) + vB8.z;
        func_8005CCD8(&ray, 0);
        ray.unk88 = 0;
        D_800D7238 = 1;
        func_8005DF8C(&ray, 1);
        D_800D7238 = 0;
        if (ray.hit == 0) {
            Q(0x564) = q68;
        }
    }
    if ((I32(0x688) != 0 && *(s32 *)(TGT + 0x454) != 0) || I32(0x68C) > 0) {
        func_80074254(c);
        if (I32(0x68C) == 0) {
            I32(0x694) = speed;
        }
        if (I32(0x694) >= 0x1F) {
            I32(0x694) = 0x1E;
        }
        if (I32(0x688) == 0) {
            k = I32(0x68C);
            if (k <= 0) {
                k = 0;
            } else if (I32(0x690) == 0) {
                if (k >= 8) {
                    k = 7;
                }
                I32(0x690) = k + 1;
            } else {
                k = I32(0x690) - 1;
            }
            if (k == 0) {
                I32(0x690) = 1;
                I32(0x68C) = -1;
                I32(0x698) = 0;
            }
            k = k * k;
            I32(0x690)--;
            goto common;
        } else {
            I32(0x690) = 0;
            if (I32(0x68C) >= 7) {
                k = 49;
                D_800DE134.y += (t = I32(0x694) * 8000) * k / 30;
                v48.z += (t = I32(0x694) * 18000) * k / 30;
                I32(0x698)++;
            } else if (I32(0x68C) >= 0) {
                I32(0x698) = 0;
                k = I32(0x68C);
                k *= k;
            common:
                D_800DE134.y += k * (t = I32(0x694) * 8000) / 30;
                v48.z += k * (t = I32(0x694) * 18000) / 30;
            }
        }
        q68 = Q(0x574);
        func_80067F30(q68, Q(0x564), 0xDE, &Q(0x554));
        I32(0x68C)++;
    } else {
        flag = 0;
        if (I32(0x720) > 0) {
            flag = 1;
            I32(0x720)--;
        }
        p564 = (Q_80075694 *)(c + 0x564);
        pq = &q68;
        p78 = &q78;
        func_800676D0(p78, D_800DE12E);
        func_800673B0(pq, p564, p78);
        Q(0x564) = q68;
        func_80074254(c);
        if (*(s32 *)(TGT + 0x838) != 0) {
            if (*(s32 *)(TGT + 0x82C) == 3) {
                flag = 1;
                I32(0x720) = 20;
            } else if (*(s32 *)(TGT + 0x82C) == 1) {
                func_800676D0(p78, 200);
                func_800673B0(pq, p564, p78);
                Q(0x564) = q68;
            }
        }
        if ((u32)(I32(0x69C) - 2) < 0x12) {
            q68 = Q(0x574);
            func_80067F30(q68, Q(0x564), 0x137, &Q(0x554));
        } else if (flag) {
            w = (20 - I32(0x720)) * 13 + 0x33;
            q68 = Q(0x574);
            func_80067F30(q68, Q(0x564), w, &Q(0x554));
        } else {
            q68 = Q(0x574);
            func_80067F30(q68, Q(0x564), arg1, &Q(0x554));
        }
    }
    if (U32(0x610) < 12) {
        Q(0x554) = Q(0x564);
        Q(0x574) = Q(0x554);
    }
    func_80067A48(c + 0x554, (M_80075694 *)&q68);
    func_800226A0((M_80075694 *)&q68, &v48, &v58);
    v48.x = D_800DE134.x;
    v48.y = D_800DE134.y;
    v48.z = D_800DE134.z;
    func_800226A0((M_80075694 *)&q68, &v48, c + 0x6F0);
    I32(0x4) = I32(0x4D0) + v58.x;
    I32(0x8) = I32(0x4D4) + v58.y;
    I32(0xC) = I32(0x4D8) + v58.z;
    func_80046FBC(&q88, c + 4, &v28);
    V3(0x84) = q88.v;
}
