/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_8006B78C;

typedef struct {
    s16 x, y, z, w;
} A4_8006B78C;

typedef struct {
    s16 m[3][3];
    s32 t[3];
} M_8006B78C;

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
    A4_8006B78C rot;
    A4_8006B78C prevRot;
    V3_8006B78C pos;
    V3_8006B78C prevPos;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
} Rec_8006B78C;

typedef struct {
    u8 pad0[4];
    V3_8006B78C pos;
    u8 pad10[0x84 - 0x10];
    V3_8006B78C unk84;
    u8 pad90[0x16C - 0x90];
    V3_8006B78C unk16C;
    u8 pad178[0x208 - 0x178];
    u32 unk208;
    u8 pad20C[0x21C - 0x20C];
    s16 unk21C;
    u16 unk21E;
    u8 pad220[0x28C - 0x220];
    s32 unk28C;
    u8 pad290[0x3E0 - 0x290];
    s32 unk3E0;
    u8 pad3E4[0x818 - 0x3E4];
    s32 unk818;
    s32 unk81C;
    u8 pad820[0x82C - 0x820];
    s32 unk82C;
    u8 pad830[0x884 - 0x830];
    M_8006B78C mtx;
} Sk_8006B78C;

typedef struct {
    V3_8006B78C start;
    V3_8006B78C end;
    u8 pad18[0x88 - 0x18];
    u8 unk88;
    u8 pad89[0x100 - 0x89];
} Ray_8006B78C;

typedef struct {
    s32 x, y, z, w;
} V4_8006B78C;

typedef struct {
    u16 flags;
    u8 pad2[0x20 - 0x2];
    s32 unk20;
} Info_8006B78C;

typedef struct Node_8006B78C {
    s32 unk0;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u8 pad8[4];
    struct Node_8006B78C *next;
    Info_8006B78C *info;
} Node_8006B78C;

typedef struct {
    s16 delta;
    s16 index;
    void (*fn)();
} VtEntry_8006B78C;

typedef struct {
    u8 pad0[0x48];
    VtEntry_8006B78C *vt;
} Obj_8006B78C;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x154 - 0x10];
} Rec4D80_8006B78C;

extern Sk_8006B78C *D_800D61A8;
extern Sk_8006B78C *D_800DE7A8;
extern Sk_8006B78C *D_800D61A0;
extern volatile s32 D_800D613C;
extern Rec_8006B78C D_800DC618;
extern Rec_8006B78C D_800DC6D8;
extern s32 D_800DC798[];
extern s32 D_800DC7B4[];
extern s32 D_800DC7D0[];
extern s32 D_800DC610;
extern Node_8006B78C *D_800DC5E0;
extern s32 D_800DC604;
extern s32 D_800DE7A0;
extern s32 D_800DC5A0;
extern Rec4D80_8006B78C D_800D4D80[];

s32 func_8006A454(Rec_8006B78C *, s32);
void func_80047124(V3_8006B78C *, s32 *);
void func_80046FBC(V3_8006B78C *, V3_8006B78C *, V3_8006B78C *);
void func_80022598(A4_8006B78C *, M_8006B78C *);
void func_8005BED8(Sk_8006B78C *);
void func_8005E45C(Sk_8006B78C *);
void func_80039E60(s32, s32, s32);
void func_80039F88(s32);
void func_8004C4A4(Sk_8006B78C *, s32, s32);
Info_8006B78C *func_800635E4(s32);
void func_80035138(s32, s32, s32);
s32 func_80061904(s32);
void func_80061BC8(s32);
void func_8005CCD8(Ray_8006B78C *, s32);
void func_8005DF8C(Ray_8006B78C *, s32);
void func_80061E7C(s32);
void func_80061E34(s32);
Obj_8006B78C *func_8005CA90(V4_8006B78C *, V4_8006B78C *, V3_8006B78C *, s32, s32);
void func_8004C7CC(Sk_8006B78C *);
void func_8004C774(Sk_8006B78C *);

static inline u32 getbit_8006B78C(Rec_8006B78C *r) {
    u32 v;

    if (r->left == 0) {
        r->acc = *r->ptr++;
        r->left = 32;
    }
    r->left--;
    v = r->acc & 1;
    r->acc >>= 1;
    return v;
}

static inline u32 getbits_8006B78C(Rec_8006B78C *r, s32 n) {
    s32 avail;
    s32 rest;
    u32 v;

    if (r->left == 0) {
        r->acc = *r->ptr++;
        r->left = 32;
    }
    avail = r->left;
    if (avail >= n) {
        r->left = avail - n;
        v = r->acc & ((1 << n) - 1);
        r->acc >>= n;
    } else {
        v = r->acc & ((1 << avail) - 1);
        rest = n - avail;
        r->acc = *r->ptr++;
        v |= (r->acc & ((1 << rest) - 1)) << r->left;
        r->acc >>= rest;
        r->left = 32 - rest;
    }
    return v;
}

static inline s32 code_8006B78C(Rec_8006B78C *r) {
    s32 i = 0;

    while (1) {
        if (i >= 6) {
            break;
        }
        if (getbit_8006B78C(r) == 0) {
            break;
        }
        i++;
    }
    return i;
}

void func_8006B78C(Sk_8006B78C *sk, s32 mode) {
    Rec_8006B78C *r;
    s32 i;
    s32 v;
    V3_8006B78C tmp;
    Ray_8006B78C ray;
    V4_8006B78C a;
    V4_8006B78C b;
    s32 k;
    V3_8006B78C *p;

    if (sk == D_800D61A8) {
        r = &D_800DC618;
    } else {
        r = &D_800DC6D8;
    }
    sk->unk16C = sk->pos;
    i = 0;
    while (1) {
        if (i >= 6) {
            break;
        }
        if (getbit_8006B78C(r) == 0) {
            break;
        }
        i++;
    }
    (p = &sk->pos)->x = r->pos.x * 2 - r->prevPos.x + func_8006A454(r, D_800DC798[i]);
    sk->pos.y = r->pos.y * 2 - r->prevPos.y + func_8006A454(r, D_800DC798[i]);
    sk->pos.z = r->pos.z * 2 - r->prevPos.z + func_8006A454(r, D_800DC798[i]);
    r->prevPos = r->pos;
    r->pos = sk->pos;
    k = 12;
    func_80047124(p, &k);
    func_80046FBC(&tmp, p, &sk->unk16C);
    sk->unk84 = tmp;

    i = 0;
    while (1) {
        if (i >= 6) {
            break;
        }
        if (getbit_8006B78C(r) == 0) {
            break;
        }
        i++;
    }
    {
        s32 ax, ay, az;

        ax = func_8006A454(r, D_800DC7B4[i]) & 0xFFF;
        ay = func_8006A454(r, D_800DC7B4[i]) & 0xFFF;
        az = func_8006A454(r, D_800DC7B4[i]) & 0xFFF;
        r->rot.x = (r->prevRot.x + ax + 0x4000) & 0xFFF;
        r->rot.y = (r->prevRot.y + ay + 0x4000) & 0xFFF;
        r->rot.z = (r->prevRot.z + az + 0x4000) & 0xFFF;
    }
    r->prevRot = r->rot;
    if (mode == 1) {
        func_80022598(&r->rot, &sk->mtx);
        sk->mtx.m[0][1] = -sk->mtx.m[0][1];
        sk->mtx.m[1][1] = -sk->mtx.m[1][1];
        sk->mtx.m[2][1] = -sk->mtx.m[2][1];
        func_8005BED8(sk);
        func_8005E45C(sk);
    }

    if (getbit_8006B78C(r) == 1) {
        sk->unk82C = getbits_8006B78C(r, 4);
    }
    if (getbit_8006B78C(r) == 1) {
        sk->unk21E = getbits_8006B78C(r, 7);
    }
    r->animIdx = sk->unk21E;
    if (getbit_8006B78C(r) == 0) {
        sk->unk21C = r->frame + getbits_8006B78C(r, 2);
    } else {
        sk->unk21C = getbits_8006B78C(r, 8);
    }
    r->frame = sk->unk21C;
    if (getbit_8006B78C(r)) {
        sk->unk208 |= 2;
    } else {
        sk->unk208 &= ~2;
    }
    if (getbit_8006B78C(r) == 0) {
        r->unkAC = 0;
        r->unkB0 = 0;
        sk->unk81C = 0;
        sk->unk818 = 0;
    } else {
        sk->unk818 = 1000;
        i = 0;
        while (1) {
            if (i >= 6) {
                break;
            }
            if (getbit_8006B78C(r) == 0) {
                break;
            }
            i++;
        }
        if (D_800DC7D0[i] != 0) {
            v = func_8006A454(r, D_800DC7D0[i]);
            sk->unk81C = r->unkAC + r->unkB0 + v;
            r->unkAC = sk->unk81C;
            r->unkB0 = v;
        }
    }
    r->unkB8 += getbits_8006B78C(r, 2) + 2;
    if (mode == 1) {
        (void)D_800D613C; /* volatile read, value unused */
    }
    if (getbit_8006B78C(r)) {
        if (getbit_8006B78C(r)) {
            s32 id = getbits_8006B78C(r, 8);

            if (D_800DC610 == 0) {
                func_80039E60(id, 10000, 0);
            }
        } else {
            s32 id = getbits_8006B78C(r, 8);

            if (D_800DC610 == 0) {
                func_80039F88(id);
            }
        }
    }
    if (getbit_8006B78C(r)) {
        if (getbit_8006B78C(r)) {
            func_8004C4A4(sk, getbits_8006B78C(r, 2), 50);
        }
        if (getbit_8006B78C(r)) {
            Node_8006B78C *o;
            s32 n;
            s32 j;
            s32 p;

            n = getbits_8006B78C(r, 8);
            o = D_800DC5E0;
            for (j = 0; j < n; j++) {
                o = o->next;
            }
            o->info = func_800635E4(o->unk0);
            o->info->flags |= 0x400;
            o->info->unk20 = 0x202020;
            o->unk6 = 1;
            if (sk == D_800D61A8) {
                o->unk7 = 1;
                p = 0;
            } else {
                o->unk7 = 2;
                p = 1;
            }
            if (D_800DE7A0 == 8) {
                func_80035138(o->unk0, p, 180);
            }
            D_800DC604 = o->unk7;
            func_80061BC8(func_80061904(o->unk4));
        }
    }
    if (r->prevPos.x != 0 || r->prevPos.y != 0 || r->prevPos.z != 0) {
        s32 who;
        Obj_8006B78C *hit;

        ray.start.x = r->prevPos.x << 12;
        ray.start.y = r->prevPos.y << 12;
        ray.start.z = r->prevPos.z << 12;
        ray.end.x = r->pos.x << 12;
        ray.end.y = r->pos.y << 12;
        ray.end.z = r->pos.z << 12;
        func_8005CCD8(&ray, 0);
        ray.unk88 = 1;
        if (sk == D_800DE7A8) {
            who = 1;
        } else {
            who = 2;
        }
        func_80061E7C(who);
        D_800D61A0 = sk;
        func_8005DF8C(&ray, 1);
        D_800D61A0 = 0;
        func_80061E34(who);
        a.x = r->prevPos.x << 12;
        a.y = r->prevPos.y << 12;
        a.z = r->prevPos.z << 12;
        b.x = r->pos.x << 12;
        b.y = r->pos.y << 12;
        b.z = r->pos.z << 12;
        hit = func_8005CA90(&a, &b, &tmp, D_800DC5A0, 0);
        if (hit != 0) {
            hit->vt[2].fn((u8 *)hit + hit->vt[2].delta);
        }
    }
    switch (sk->unk21E) {
    case 0x36:
        if (sk->unk21C >= 0x70) {
            goto other;
        }
    case 0x2C:
    case 0x2E:
    case 0x37:
        func_8004C7CC(sk);
        break;
    default:
    other:
        func_8004C774(sk);
        break;
    }
    if (D_800D4D80[sk->unk3E0].unkC == 0x4000) {
        if (sk->unk21E != 0x3F) {
            sk->unk28C |= 0x1000;
        } else {
            sk->unk28C &= ~0x1000;
        }
    }
    if (mode != 1) {
        r->unkB8 = D_800D613C;
    }
}
