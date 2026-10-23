#include "common.h"

typedef struct {
    u8 pad0[0x30];
    s8 unk30;
    u8 pad31[0x17];
    u8 unk48[0x6E0 - 0x48];
    u8 unk6E0[0x708 - 0x6E0];
    s8 unk708;
    u8 pad709[3];
    f32 unk70C;
    s32 unk710;
} Unk8003AC68;

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 unk3;
} D_800D0FC0_t;

void func_80039E60(s32, s32, s32);
void func_8003AB50(Unk8003AC68 *);
s8 func_8003C580(void *, s32, void *);
s32 func_8003C6B4(void *, void *);
s32 func_800B4264(s32, s32);
extern f64 D_80019FB8;
extern D_800D0FC0_t D_800D0FC0;
extern s32 D_800D3698;
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;
extern f32 D_800F5668;

s32 func_8003AC68(Unk8003AC68 *arg0) {
    s32 sp10[2];
    s32 hit;
    s32 v;
    s32 ret;
    s32 a;
    s32 b;

    a = D_800D0FC0.unk2;
    b = D_800D0FC0.unk3;
    ret = func_8003C6B4(arg0->unk48, sp10);
    D_800DE9A8 = 1;
    if (ret != arg0->unk30) {
        switch (ret) {
        case 18:
            func_80039E60(0x91, 10000, 0);
            D_800DE7A0 = 1;
            ret = 8;
            D_800DE9A8 = 1;
            break;
        case 20:
            func_80039E60(0x91, 10000, 0);
            ret = 10;
            D_800DE9A8 = 2;
            break;
        case 19:
            func_80039E60(0x91, 10000, 0);
            D_800DE7A0 = 3;
            D_800DE9A8 = 1;
            ret = 5;
            D_800D3698 = 6;
            break;
        case 21:
            func_80039E60(0x91, 10000, 0);
            D_800DE7A0 = 2;
            D_800DE9A8 = 1;
            ret = 5;
            D_800D3698 = 6;
            break;
        case 23:
        case 24:
            func_80039E60(0x91, 10000, 0);
            break;
        default:
            ret = 0;
            break;
        }
    }
    arg0->unk70C += D_800F5668;
    hit = 0;
    if (arg0->unk70C > D_80019FB8) {
        arg0->unk70C -= D_80019FB8;
        arg0->unk710 = arg0->unk710 == 0;
    }
    if (func_800B4264(a, 0x4000) != 0) {
        hit = 1;
    } else if (func_800B4264(b, 0x4000) != 0) {
        hit = 1;
    }
    if (hit) {
        ret = 3;
        func_80039E60(0x93, 10000, 0);
    }
    arg0->unk30 = ret;
    arg0->unk708 = func_8003C580(arg0->unk48, 6, arg0->unk6E0);
    func_8003AB50(arg0);
    return ret;
}
