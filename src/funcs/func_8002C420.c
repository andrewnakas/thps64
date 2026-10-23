#include "common.h"

extern u8 D_800D0FC0[];
extern s32 D_800DE7A0;
extern f32 D_800F5668;
s32 func_8003C6B4(void *, void *);
void func_80039E60(s32, s32, s32);
s32 func_800B4264(s32, s32);
s8 func_8003C580(void *, s32, void *);
void func_8002C308(u8 *);

s32 func_8002C420(u8 *arg0) {
    s32 ret;
    u8 *cfg;
    s32 b2;
    s32 b3;
    s32 r;
    s32 hit;
    u8 buf[8];

    ret = 0;
    cfg = D_800D0FC0;
    b2 = cfg[2];
    b3 = cfg[3];
    r = func_8003C6B4(arg0 + 0x48, buf);
    if (r != *(s8 *)(arg0 + 0x30)) {
        switch (r) {
        case 0xFF:
            func_80039E60(0x91, 10000, 0);
            D_800DE7A0 = 8;
            ret = 5;
            break;
        case 0x100:
            func_80039E60(0x91, 10000, 0);
            D_800DE7A0 = 5;
            ret = 5;
            break;
        case 0x101:
            func_80039E60(0x91, 10000, 0);
            D_800DE7A0 = 7;
            ret = 5;
            break;
        default:
            ret = 0;
            break;
        }
    }
    *(f32 *)(arg0 + 0x6E0) += D_800F5668;
    if (*(f32 *)(arg0 + 0x6E0) > 0.5) {
        *(f32 *)(arg0 + 0x6E0) -= 0.5;
        *(s32 *)(arg0 + 0x6E4) = !*(s32 *)(arg0 + 0x6E4);
    }
    hit = 0;
    if (func_800B4264(b2, 0x4000) || func_800B4264(b3, 0x4000)) {
        hit = 1;
    }
    if (hit) {
        ret = 4;
        func_80039E60(0x93, 10000, 0);
    }
    *(s8 *)(arg0 + 0x30) = r;
    *(s8 *)(arg0 + 0x6FE) = func_8003C580(arg0 + 0x48, 3, arg0 + 0x6E8);
    func_8002C308(arg0);
    return ret;
}
