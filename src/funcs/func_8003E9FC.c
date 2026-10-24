/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx3E9FC;

void func_8003EF00(u8 *);
void func_800A773C(void *, f32, f32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_800BEF70(s32, s32, s32);
extern f32 D_800F329C;
extern Gfx3E9FC *D_800F36A4;

#define SCISSOR(ulx, uly, lrx, lry)                                                              \
    {                                                                                            \
        Gfx3E9FC *_g = D_800F36A4++;                                                             \
        _g->w0 = 0xED000000 | (((s32)((f32)(ulx) * 4.0f) & 0xFFF) << 12) |                       \
                 ((s32)((f32)(uly) * 4.0f) & 0xFFF);                                             \
        _g->w1 = (((s32)((f32)(lrx) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(lry) * 4.0f) & 0xFFF); \
    }

#define H(o) (*(s16 *)(arg0 + (o)))
#define SCALE (*(f32 *)(arg0 + 0x30))

void func_8003E9FC(u8 *arg0) {
    func_800BE3D8();
    if (*(s32 *)(arg0 + 0x3A8) < 4) {
        *(s32 *)(arg0 + 0x3A8) += 1;
        func_800BEF70(0, 0, 0);
    } else {
        func_800BE7D0(0, 640, 375, 425, 0, 0, 0, 255);
    }
    func_800B1AC4(arg0 + 0x318, 40.0f, 15.0f, 0.925f, 1.9f);
    switch (arg0[0x67]) {
    case 0:
        func_800B1AC4(arg0 + 0x390, 171.0f, 125.0f, 0.925f, SCALE);
        SCISSOR((s32)(D_800F329C * 150.0f), 133, (s32)(D_800F329C * 265.0f), 387);
        if (arg0[0x62] != arg0[0x61]) {
            func_800B1AC4(arg0 + 0x340, 202.0f, H(0x34), 0.925f, SCALE);
        }
        func_800B1AC4(arg0 + 0x32C, 202.0f, H(0x36), 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x37C, 317.0f, 284.0f, 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x368, 462.0f, H(0x38), 0.925f, SCALE);
        break;
    case 1:
        func_800B1AC4(arg0 + 0x32C, 202.0f, H(0x36), 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x368, 462.0f, H(0x38), 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x390, 306.0f, 261.0f, 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x37C, 317.0f, 284.0f, 0.925f, SCALE);
        break;
    case 2:
        func_800B1AC4(arg0 + 0x32C, 202.0f, H(0x36), 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x37C, 317.0f, 284.0f, 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x390, 437.0f, 274.0f, 0.925f, SCALE);
        SCISSOR((s32)(D_800F329C * 435.0f), 280, (s32)(D_800F329C * 555.0f), 373);
        if (arg0[0x63] != arg0[0x64]) {
            func_800B1AC4(arg0 + 0x354, 462.0f, H(0x34), 0.925f, SCALE);
        }
        func_800B1AC4(arg0 + 0x368, 462.0f, H(0x38), 0.925f, SCALE);
        break;
    default:
        func_800B1AC4(arg0 + 0x390, 171.0f, 125.0f, 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x32C, 202.0f, H(0x36), 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x37C, 317.0f, 284.0f, 0.925f, SCALE);
        func_800B1AC4(arg0 + 0x368, 462.0f, H(0x38), 0.925f, SCALE);
        break;
    }
    func_8003EF00(arg0);
    if (*(s32 *)(arg0 + 0x68) != 0) {
        func_800A773C(arg0 + 0x74, 1.3f, 1.3f);
        func_800A8678(arg0 + 0x74, arg0 + 0x40, H(0x70), 411.0f, 0, 0, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    } else {
        func_800A773C(arg0 + 0x74, 1.1f, 1.3f);
        func_800A8678(arg0 + 0x74, arg0 + 0x40, H(0x70), 411.0f, 0, 0, 3.0f, 0xA0, 0x50, 1, 0, 0, 0, 0);
    }
    func_800BE5A4();
}
