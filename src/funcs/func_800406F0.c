#include "common.h"

void func_80041E40(void *);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800B231C(void *, s32, s32, s32, s32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_800BEF70(s32, s32, s32);

typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x78 - 0x14];
} Ent800D5C1C;

extern s32 D_800C0E20;
extern Ent800D5C1C D_800D5C1C[];

#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_800406F0(u8 *arg0) {
    f32 f26;
    f32 f24;
    f32 f22;
    f32 f20;
    u8 *s3;
    s32 t;

    func_800BE3D8();
    if (S32(arg0, 0x2A4) < 4) {
        S32(arg0, 0x2A4)++;
        func_800BEF70(0, 0, 0);
    } else {
        func_800BE7D0(0, 0x280, 0x177, 0x1A9, 0, 0, 0, 0xFF);
    }
    func_800B1AC4(arg0 + 0x308, 40.0f, 15.0f, 0.925f, 1.9f);
    if (D_800D5C1C[D_800C0E20].x10 == 0) {
        func_800B231C(arg0 + 0x31C, 0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        func_800B231C(arg0 + 0x31C, 0x32, 0x32, 0x32, 0xFF);
    }
    func_800B1AC4(arg0 + 0x31C, (f32) U16(arg0, 0x27C), (f32) (U16(arg0, 0x27E) - 2), 0.945f, 0.94f);
    f26 = 120.0f;
    f22 = 160.0f;
    f20 = 1.0f;
    func_800B1AC4(arg0 + 0x36C, f26, f22, f20, f20);
    f24 = 580.0f;
    func_800B1AC4(arg0 + 0x358, f24, f22, f20, f20);
    if (S16(arg0, 0x34) > 0) {
        func_800B1AC4(arg0 + 0x344, f24, f22, f20, f20);
        S16(arg0, 0x34)--;
    } else if (S16(arg0, 0x36) > 0) {
        func_800B1AC4(arg0 + 0x330, f26, f22, f20, f20);
        S16(arg0, 0x36)--;
    }
    func_800B1AC4(arg0 + 0x380, (f32) U16(arg0, 0x2A8), (f32) U16(arg0, 0x2AA), 1.0f, 1.0f);
    func_80041E40(arg0);
    s3 = arg0 + 0x3C;
    t = S16(arg0, 0x2B0);
    f22 = 412.0f;

    func_800A8678(s3, arg0 + 0x2B7, (f32) t, f22, 0, 0, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_800A8678(s3, arg0 + 0x2CF, (f32) S16(arg0, 0x2B2), f22, 0, 0, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_800BE5A4();
}
