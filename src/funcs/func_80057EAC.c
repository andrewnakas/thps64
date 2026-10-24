/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_80057EAC;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Vec4s_80057EAC;

typedef struct {
    u8 pad0[0x1C];
    s32 x1C;
    u8 pad20[0x154 - 0x20];
} Row80057EAC;

s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
s32 func_80022E14(s32, s32);
s32 func_8004D2D4(u8 *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_80039E60(s32, s32, s32);
extern Row80057EAC D_800D4D80[];
extern s32 D_800D6F94;
extern s32 D_800D6F98;
extern s32 D_800D6FC8;
extern s32 D_800DE7A0;
extern s32 D_800DE86C;
extern s32 D_800DE9C4;
extern u8 D_800DE9F4[];

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))

#define SET_RANGE(p, G) \
    {                                                           \
        s32 *q;                                                 \
        s32 t;                                                  \
        s32 w;                                                  \
        s32 v;                                                  \
        s32 x;                                                  \
        q = &S32(p, 0x430);                                     \
        if ((w = D_800D6FC8) == 0) {                            \
            x = D_800D4D80[S32(p, 0x3E0)].x1C;                  \
            v = (*(u8 **)(p + 0x290))[1];                       \
            if (S32(p, 0x34C) != 0 || D_800DE86C != 0) {        \
                t = G - 10;                                     \
                v += 3;                                         \
                w = x + v;                                      \
            } else {                                            \
                t = G - 10;                                     \
                w = x + v;                                      \
            }                                                   \
        } else {                                                \
            t = G - 10;                                         \
        }                                                       \
        *q = (((t + w) << 12) * 3 * 15) / 28;                   \
    }                                                           \


#define PROJ_80057EAC(V, N)                                     \
    {                                                           \
        struct {                                                \
            s32 pad;                                            \
            Vec4s_80057EAC n;                                   \
            s32 pad2;                                           \
            Vec3i_80057EAC t;                                   \
        } f;                                                    \
        s32 d;                                                  \
                                                                \
        f.n = N;                                                \
        {                                                       \
            s32 nx = f.n.x;                                     \
            s32 ny = f.n.y;                                     \
            s32 nz = f.n.z;                                     \
                                                                \
            f.t.x = nx;                                         \
            f.t.y = ny;                                         \
            f.t.z = nz;                                         \
        }                                                       \
        d = func_80022E54(&V, &f.t);                            \
        V.x -= func_80022E14(d, f.n.x);                         \
        V.y -= func_80022E14(d, f.n.y);                         \
        V.z -= func_80022E14(d, f.n.z);                         \
    }

void func_80057EAC(u8 *arg0) {
    Vec3i_80057EAC pos;
    Vec3i_80057EAC *pp;
    s32 has;
    s32 len;
    s32 d;
    s32 dot;
    s32 k;
    s32 *e;

    if (D_800DE7A0 != 7) {
        s32 *t = (s32 *)D_800DE9F4;

        e = &t[S32(arg0, 0x968)];
    } else {
        s32 *t = (s32 *)D_800DE9F4;

        e = &t[S32(arg0, 0x968) ^ D_800DE9C4];
    }
    has = S32(e, 0x980);
    if (S32(arg0, 0x82C) != 0) {
        return;
    }
    if (arg0[0x227] != 0) {
        switch (U16(arg0, 0x21E)) {
        case 1:
            S32(arg0, 0x228) = 0x14000;
            func_8004D2D4(arg0);
            func_8004A204(arg0, 3, 0, -1, -1);
            break;
        case 3:
            S32(arg0, 0x228) = 0x10000;
            func_8004D2D4(arg0);
            func_8004A204(arg0, 0, 0, -1, -1);
            break;
        }
    }
    if (S32(arg0, 0x938) > 0) {
        S32(arg0, 0x938)--;
    }
    len = func_800233B8(func_80022E54(arg0 + 0x84, arg0 + 0x84)) << 6;
    pp = &pos;
    pos = *(Vec3i_80057EAC *)(arg0 + 0x84);
    PROJ_80057EAC(pos, *(Vec4s_80057EAC *)(arg0 + 0x904))
    dot = func_80022E54(arg0 + 0x8F4, pp);
    if ((*(u8 **)(arg0 + 0x964))[0x10] != 0 || has != 0) {
        if (S32(arg0, 0x410) == 0 || S32(arg0, 0x414) == 0) {
            if (S32(arg0, 0x938) == 0) {
                if ((dot >= -0x4CC && S32(arg0, 0x430) / 2 < len) || S32(arg0, 0x834) != 0) {
                    S32(arg0, 0x938) = 20;
                } else if (S32(arg0, 0x82C) == 0) {
                    switch (U16(arg0, 0x21E)) {
                    case 0:
                    case 5:
                    case 6:
                    case 7:
                        SET_RANGE(arg0, D_800D6F98)
                        S32(arg0, 0x938) = 20;
                        S32(arg0, 0x228) = 0x14000;
                        S32(arg0, 0x80C) = 1;
                        func_8004D2D4(arg0);
            func_8004A204(arg0, 1, 0, -1, -1);
                        break;
                    }
                }
            }
            len = func_800233B8(func_80022E54(arg0 + 0x84, arg0 + 0x84)) << 6;
            if ((u32)(U16(arg0, 0x21E) - 2) < 2) {
                k = 4;
                if (S16(arg0, 0x21C) >= 11 && S32(arg0, 0x80C) != 0) {
                    S32(arg0, 0x810) = 0x22;
                    func_80039E60(0x22, 10000, 0);
                    S32(arg0, 0x80C) = 0;
                }
                if ((u32)(U16(arg0, 0x21C) - 11) < 5) {
                    if ((*(u8 **)(arg0 + 0x964))[0x10] != 0) {
                        k = 8;
                    }
                    if (len < S32(arg0, 0x430) && S32(arg0, 0x82C) != 2) {
                        S32(arg0, 0x9C) = -S32(arg0, 0x8D0) * k;
                        S32(arg0, 0xA0) = -S32(arg0, 0x8D4) * k;
                        S32(arg0, 0xA4) = -S32(arg0, 0x8D8) * k;
                    }
                }
            } else if ((u32)(S32(arg0, 0x938) - 11) < 5 && len < S32(arg0, 0x430) && S32(arg0, 0x82C) != 2) {
                S32(arg0, 0x9C) = -S32(arg0, 0x8D0) * 4;
                S32(arg0, 0xA0) = -S32(arg0, 0x8D4) * 4;
                S32(arg0, 0xA4) = -S32(arg0, 0x8D8) * 4;
            }
        }
        if (has != 0) {
            return;
        }
    }
    if ((*(u8 **)(arg0 + 0x964))[0x10] != 0 && dot >= -0x4CC && S32(arg0, 0x834) == 0 && S32(arg0, 0x82C) == 0) {
        switch (U16(arg0, 0x21E)) {
        case 0:
        case 5:
        case 6:
        case 7:
            SET_RANGE(arg0, D_800D6F94)
            S32(arg0, 0x938) = 20;
            S32(arg0, 0x228) = 0x14000;
            func_8004D2D4(arg0);
            func_8004A204(arg0, 1, 0, -1, -1);
            S32(arg0, 0x80C) = 1;
            break;
        }
    }
    len = func_800233B8(func_80022E54(arg0 + 0x84, arg0 + 0x84)) << 6;
    if ((u32)(U16(arg0, 0x21E) - 2) < 2) {
        s32 k2 = 4;

        if ((u32)(U16(arg0, 0x21C) - 11) < 5) {
            if ((*(u8 **)(arg0 + 0x964))[0x10] != 0) {
                k2 = 8;
            }
            if (len < S32(arg0, 0x430) && S32(arg0, 0x82C) != 2) {
                S32(arg0, 0x9C) = -S32(arg0, 0x8D0) * k2;
                S32(arg0, 0xA0) = -S32(arg0, 0x8D4) * k2;
                S32(arg0, 0xA4) = -S32(arg0, 0x8D8) * k2;
            }
        }
    }
}
