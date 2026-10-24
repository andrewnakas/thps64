/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: reorg backward fill takes axis=1 into the abs bgez slot; game used optimize_skip bltzl, best 353/355. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* NEAR-MISS C5: 352/355 at -O2 -fno-schedule-insns -fno-schedule-insns2 (flag line below must be moved to line 1). Only diff: then-branch of axis select: game keeps `axis = 1` (addiu v1,1) before lw and uses bltzl for |dir.z|; ours reorg moves axis=1 into a bgez delay slot. Key fixes: inline collide() (temp frame for mtx+lim -> addresses rematerialized), vsub() inline with local r (temp copy at sp40), face() copies dir to a temp, natural do-while. */
/* Z1: reorg fill_simple_delay_slots' backward scan from the then-arm bgez passes lw 0x38 (conflict) and takes
 * `axis = 1` (nothing stops it: no label/jump/SEQUENCE in between); the game's slot was filled by optimize_skip
 * (bltzl+negu), so its RTL had a stop or conflict there. axis = 1 after the compare gets the bltzl but then the j
 * slot takes axis = 1 instead of the slt; if/else axis assignment and explicit abs forms lose more. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_06B8;

typedef struct {
    s16 v[6];
} Lim06B8;

typedef struct {
    u8 pad0[2];
    u16 unk2;
} Node06B8;

typedef struct {
    u8 pad0[0x1C];
    void *unk1C;
} Pl06B8;

typedef struct {
    u8 pad0[4];
    V3_06B8 pos;
    u16 unk10;
    u16 unk12;
    u8 pad14[0x84 - 0x14];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x23C - 0x90];
    u8 unk23C[0x314 - 0x23C];
    s32 unk314;
} O06B8;

void func_80022964(V3_06B8 *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(V3_06B8 *, s32 *);
s32 func_80023190(s32, s32);
void func_80023214(void *, void *);
V3_06B8 func_80046FBC(V3_06B8 *, V3_06B8 *);
void func_800617B8(V3_06B8 *, s32);
Node06B8 *func_80061904(s32);
void func_8006FD98(O06B8 *, void *, void *, Lim06B8 *);
void func_800704C4(O06B8 *, V3_06B8);
extern Lim06B8 D_8001CFB4;
extern Pl06B8 *D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;

typedef struct {
    s16 m[3][3];
    s16 pad;
    V3_06B8 tr;
} Mtx06B8;

static inline void collide_706B8(O06B8 *o) {
    Mtx06B8 m;
    Lim06B8 lim;
    Pl06B8 *p;
    void *q;

    p = D_800D61A8;
    q = p->unk1C;
    lim = D_8001CFB4;
    func_80023214(o->unk23C, &m);
    func_8006FD98(o, p, &m, &lim);
    if (q != NULL) {
        func_8006FD98(o, q, &m, &lim);
    }
}

static inline s32 iabs_706B8(s32 v) {
    return v < 0 ? -v : v;
}

static inline V3_06B8 vsub_706B8(V3_06B8 *b, V3_06B8 *a) {
    V3_06B8 r;
    r = func_80046FBC(b, a);
    return r;
}

static inline void face_706B8(O06B8 *o, V3_06B8 *v) {
    V3_06B8 t;
    t = *v;
    func_800704C4(o, t);
}

void func_800706B8(O06B8 *o) {
    V3_06B8 a;
    V3_06B8 b;
    V3_06B8 dir;
    s32 first;
    s32 next;
    s32 spd;
    s32 len;
    s32 axis;
    s32 ax;
    s32 ay;
    s32 c;
    s32 total;
    s32 cur;
    s32 rem;
    s32 ang;
    s32 d;
    s32 ad;

    first = 1;
    if (D_800DC618 != 2 && D_800DC6D8 != 2) {
        collide_706B8(o);
    }
    do {
        next = func_80061904(o->unk314)->unk2;
        func_800617B8(&a, o->unk314);
        a.y += 0xFFF92000;
        func_800617B8(&b, next);
        b.y += 0xFFF92000;
        dir = vsub_706B8(&b, &a);
        func_80022964(&dir);
        if (first) {
            first = 0;
            len = func_80022E54(&dir, &o->unk84);
            spd = len;
            if (len < 0) {
                len = 0;
            }
            if (len <= 0x4FFFF) {
                len += 0x1000;
            }
            o->unk84 = func_80022E14(dir.x, len);
            o->unk88 = func_80022E14(dir.y, len);
            o->unk8C = func_80022E14(dir.z, len);
        } else {
            o->unk84 = func_80022E14(dir.x, spd);
            o->unk88 = func_80022E14(dir.y, spd);
            o->unk8C = func_80022E14(dir.z, spd);
        }
        ay = __builtin_abs(dir.y);
        ax = __builtin_abs(dir.x);
        axis = 0;
        if (ax < ay) {
            axis = 1;
            c = ay < iabs_706B8(dir.z);
        } else {
            c = ax < iabs_706B8(dir.z);
        }
        if (c) {
            axis = 2;
        }
        switch (axis) {
        case 0:
            total = ((b.x - a.x) / dir.x) << 12;
            cur = ((o->pos.x - a.x) / dir.x) << 12;
            break;
        case 1:
            total = ((b.y - a.y) / dir.y) << 12;
            cur = ((o->pos.y - a.y) / dir.y) << 12;
            break;
        case 2:
            total = ((b.z - a.z) / dir.z) << 12;
            cur = ((o->pos.z - a.z) / dir.z) << 12;
            break;
        }
        if (total - (total >> 4) < cur) {
            len -= len >> 4;
            o->unk84 -= o->unk84 >> 4;
            o->unk88 -= o->unk88 >> 4;
            o->unk8C -= o->unk8C >> 4;
        }
        cur += len;
        if (cur >= 0 && total >= cur) {
            o->pos.x += func_80022E14(dir.x, len);
            o->pos.y += func_80022E14(dir.y, len);
            o->pos.z += func_80022E14(dir.z, len);
            rem = 0;
        } else {
            func_80061904(next);
            o->unk314 = next;
            rem = cur - total;
            o->pos = b;
        }
        len = rem;
    } while (rem != 0);
    ang = func_80023190(-dir.x, -dir.z) & 0xFFF;
    d = ang - (s16)o->unk12;
    if (d < -0x800) {
        d += 0x1000;
    }
    if (d >= 0x800) {
        d -= 0x1000;
    }
    ad = __builtin_abs(d);
    if (ad < 0x80) {
        o->unk12 = ang;
    } else {
        o->unk12 = (o->unk12 + (d >> 2)) & 0xFFF;
    }
    ang = func_80023190(dir.y, 0x1000) & 0xFFF;
    d = ang - (s16)o->unk10;
    if (d < -0x800) {
        d += 0x1000;
    }
    if (d >= 0x800) {
        d -= 0x1000;
    }
    ad = __builtin_abs(d);
    if (ad < 0x80) {
        o->unk10 = ang;
    } else {
        o->unk10 = (o->unk10 + (d >> 3)) & 0xFFF;
    }
    face_706B8(o, &dir);
}
