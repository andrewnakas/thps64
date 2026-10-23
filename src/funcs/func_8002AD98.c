#include "common.h"

extern u8 D_800D0FC0[];
extern s32 D_800D3120;
extern s32 D_800D3124;
extern char *D_800D3128;
extern s32 D_800D3698;
extern char D_800192E4[];
extern f32 D_800F5668;
s32 func_8003C6B4(void *, void *);
void func_80039E60(s32, s32, s32);
void func_80065CD0(void);
s32 func_800B4264(s32, s32);
u8 func_8003C580(void *, s32, void *);
void func_8002AC80(void *);

s32 func_8002AD98(u8 *arg0) {
    u8 sp10[8];
    s32 ret;
    u8 *g;
    s32 r;
    s32 pad;
    f32 t;

    ret = 0;
    g = D_800D0FC0;
    pad = g[2];
    r = func_8003C6B4(arg0 + 0x30, sp10);
    if (r != *(s8 *)(arg0 + 0x6A0)) {
        switch (r) {
        case 0xFA:
            func_80039E60(0x91, 0x2710, 0);
            g[0x16] = 0x1F;
            ret = 5;
            D_800D3698 = 6;
            break;
        case 0xFB:
            func_80065CD0();
            func_80039E60(0x91, 0x2710, 0);
            g[0x16] = 0x1D;
            ret = 5;
            D_800D3698 = 6;
            break;
        case 0xFC:
            func_80039E60(0x91, 0x2710, 0);
            D_800D3120 = 8;
            D_800D3124 = 5;
            D_800D3698 = 6;
            D_800D3128 = D_800192E4;
            g[0x16] = 0x1F;
            *(s16 *)(g + 0x18) = 1;
            ret = 9;
            break;
        default:
            ret = 0;
            break;
        }
    }
    t = *(f32 *)(arg0 + 0x6E0) + D_800F5668;
    *(f32 *)(arg0 + 0x6E0) = t;
    if (t > 0.5) {
        *(f32 *)(arg0 + 0x6E0) = t - 0.5;
        *(s32 *)(arg0 + 0x6E4) = *(s32 *)(arg0 + 0x6E4) == 0;
    }
    if (func_800B4264(pad, 0x4000) != 0) {
        ret = 4;
        func_80039E60(0x93, 0x2710, 0);
    }
    *(s8 *)(arg0 + 0x6A0) = r;
    arg0[0x6FE] = func_8003C580(arg0 + 0x30, 3, arg0 + 0x6E8);
    func_8002AC80(arg0);
    return ret;
}
