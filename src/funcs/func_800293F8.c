#include "common.h"

typedef struct {
    u8 pad0[0x30];
    s32 unk30;
    u8 pad34[4];
    u8 unk38[0x6E4 - 0x38];
    f32 unk6E4;
    s32 unk6E8;
    u8 unk6EC[0x70E - 0x6EC];
    s8 unk70E;
} Unk800293F8;

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 unk3;
    u8 pad4[0x12];
    s8 unk16;
    u8 pad17;
    s16 unk18;
} D_800D0FC0_t;

void func_800292CC(Unk800293F8 *);
void func_80039E60(s32, s32, s32);
s8 func_8003C580(void *, s32, void *);
s32 func_8003C6B4(void *, void *);
s32 func_800B4264(s32, s32);
extern u8 D_800173E8[];
extern f64 D_80017408;
extern D_800D0FC0_t D_800D0FC0;
extern s8 D_800D0FD6;
extern s32 D_800D3120;
extern s32 D_800D3124;
extern void *D_800D3128;
extern f32 D_800F5668;

s32 func_800293F8(Unk800293F8 *arg0) {
    s32 sp10[2];
    s32 snd;
    s32 ret;
    s32 hit;
    s32 a;
    s32 b;

    a = D_800D0FC0.unk2;
    b = D_800D0FC0.unk3;
    ret = func_8003C6B4(arg0->unk38, sp10);
    if (ret != arg0->unk30) {
        switch (ret) {
        case 0x48:
            func_80039E60(0x91, 10000, 0);
            D_800D3120 = 0x17;
            D_800D3124 = 0x28;
            D_800D3128 = D_800173E8;
            D_800D0FC0.unk16 = 0x1F;
            D_800D0FC0.unk18 = 3;
            ret = 9;
            break;
        case 0x49:
            ret = 0x25;
            snd = 0x91;
            func_80039E60(snd, 10000, 0);
            break;
        case 0x46:
            ret = 0x27;
            D_800D0FD6 = 0;
            snd = 0x91;
            func_80039E60(snd, 10000, 0);
            break;
        case 0x47:
            ret = 0x27;
            D_800D0FD6 = 1;
            snd = 0x91;
            func_80039E60(snd, 10000, 0);
            break;
        case 0x4A:
            ret = 4;
            snd = 0x93;
            func_80039E60(snd, 10000, 0);
            break;
        default:
            ret = 0;
            break;
        }
    }
    arg0->unk6E4 += D_800F5668;
    hit = 0;
    if (arg0->unk6E4 > D_80017408) {
        arg0->unk6E4 -= D_80017408;
        arg0->unk6E8 = arg0->unk6E8 == 0;
    }
    if (func_800B4264(a, 0x4000) != 0) {
        hit = 1;
    } else if (func_800B4264(b, 0x4000) != 0) {
        hit = 1;
    }
    if (hit) {
        func_80039E60(0x93, 10000, 0);
        ret = 4;
    }
    arg0->unk30 = ret;
    arg0->unk70E = func_8003C580(arg0->unk38, 5, arg0->unk6EC);
    func_800292CC(arg0);
    return ret;
}
