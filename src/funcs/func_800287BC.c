#include "common.h"

void func_80028F10(void *);
void func_800A773C(void *, s32, s32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern char D_80017328[];
extern char D_80017334[];
extern char D_80017344[];

void func_800287BC(u8 *arg0) {
    f32 scale;
    s32 x;
    s32 y;
    char *s;
    u8 *p2;
    u8 *p3;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x28C, 34.0f, 0.0f, 0.925f, 2.0f);
    func_80028F10(arg0);
    if (*(s32 *)(arg0 + 0x2F8) != 0 && *(s32 *)(arg0 + 0x2F4) != 0) {
        x = *(u16 *)(arg0 + 0x2FC);
        y = *(u16 *)(arg0 + 0x2FE);
        scale = 0.7f;
        func_800B1AC4(arg0 + 0x2C8, x, y, scale, scale);
        func_800B1AC4(arg0 + 0x2DC, *(u16 *)(arg0 + 0x300), *(u16 *)(arg0 + 0x302), scale, scale);
    }
    if (*(u16 *)(arg0 + 0x48) == 0x65) {
        func_800A7AF8(arg0 + 0x4C, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(arg0 + 0x4C, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(arg0 + 0x4C, *(s32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x38));
    } else {
        func_800A7AF8(arg0 + 0x4C, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(arg0 + 0x4C, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(arg0 + 0x4C, *(s32 *)(arg0 + 0x34), *(s32 *)(arg0 + 0x34));
    }
    p2 = arg0 + 0x4C;
    s = D_80017328;
    func_800A8678(p2, s, *(u16 *)(arg0 + 0x30), *(u16 *)(arg0 + 0x32), 2, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (*(u16 *)(arg0 + 0x48) == 0x66) {
        func_800A7AF8(p2, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(p2, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(p2, *(s32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x38));
    } else {
        func_800A7AF8(p2, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(p2, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(p2, *(s32 *)(arg0 + 0x34), *(s32 *)(arg0 + 0x34));
    }
    p3 = arg0 + 0x4C;
    s = D_80017334;
    func_800A8678(p3, s, *(u16 *)(arg0 + 0x30), *(u16 *)(arg0 + 0x3C), 2, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (*(u16 *)(arg0 + 0x48) == 0x67) {
        func_800A7AF8(p3, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(p3, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(p3, *(s32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x38));
    } else {
        func_800A7AF8(p3, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(p3, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(p3, *(s32 *)(arg0 + 0x34), *(s32 *)(arg0 + 0x34));
    }
    s = D_80017344;
    func_800A8678(arg0 + 0x4C, s, *(u16 *)(arg0 + 0x30), *(u16 *)(arg0 + 0x3E), 2, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_800BE5A4();
}
