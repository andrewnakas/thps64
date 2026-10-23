#include "common.h"

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    u8 pad4[0x10];
    u8 b14;
    u8 pad15;
    u8 b16;
} S0FC0;

extern S0FC0 D_800D0FC0;
extern f32 D_800F5668;
s32 func_8003C6B4(s32, void *);
void func_80039E60(s32, s32, s32);
s32 func_800B4264(s32, s32);
s32 func_8003C580(s32, s32, s32);
void func_800428A8(s32);

s32 func_800429B0(s32 p) {
    s32 buf[2];
    s32 r;
    s32 flag;
    s32 a;
    s32 b;
    S0FC0 *g;
    f32 f;

    g = &D_800D0FC0;
    a = g->b2;
    b = g->b3;
    r = func_8003C6B4(p + 0x34, buf);
    if (r != *(s32 *)(p + 0x30)) {
        switch (r) {
        case 15:
            r = 0x25;
            func_80039E60(0x91, 0x2710, 0);
            break;
        case 16:
            r = 0x1A;
            {
                S0FC0 *h = &D_800D0FC0;
                h->b14 = 5;
                h->b16 = 0x26;
            }
            func_80039E60(0x91, 0x2710, 0);
            break;
        case 17:
            r = 0x1A;
            {
                S0FC0 *h = &D_800D0FC0;
                h->b14 = 6;
                h->b16 = 0x26;
            }
            func_80039E60(0x91, 0x2710, 0);
            break;
        case 18:
            r = 0x1A;
            {
                S0FC0 *h = &D_800D0FC0;
                h->b14 = 7;
                h->b16 = 0x26;
            }
            func_80039E60(0x91, 0x2710, 0);
            break;
        case 19:
            r = 0x1A;
            {
                S0FC0 *h = &D_800D0FC0;
                h->b14 = 8;
                h->b16 = 0x26;
            }
            func_80039E60(0x91, 0x2710, 0);
            break;
        case 20:
            r = 0x1A;
            {
                S0FC0 *h = &D_800D0FC0;
                h->b14 = 9;
                h->b16 = 0x26;
            }
            func_80039E60(0x91, 0x2710, 0);
            break;
        default:
            r = 0;
            break;
        }
    }
    f = *(f32 *)(p + 0x6E0) + D_800F5668;
    *(f32 *)(p + 0x6E0) = f;
    flag = 0;
    if (f > 0.5) {
        *(f32 *)(p + 0x6E0) = f - 0.5;
        *(s32 *)(p + 0x6E4) = *(s32 *)(p + 0x6E4) == 0;
    }
    if (func_800B4264(a, 0x4000) != 0) {
        flag = 1;
    } else if (func_800B4264(b, 0x4000) != 0) {
        flag = 1;
    }
    if (flag) {
        func_80039E60(0x93, 0x2710, 0);
        r = 0x25;
    }
    *(s32 *)(p + 0x30) = r;
    *(u8 *)(p + 0x710) = func_8003C580(p + 0x34, 6, p + 0x6E8);
    func_800428A8(p);
    return r;
}
