/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *, s32, s32);
} VEnt26650;

typedef struct {
    u8 pad[0x50];
    VEnt26650 e;
} VTbl26650;

typedef struct {
    u8 pad0[0x48];
    VTbl26650 *vt;
    u8 pad4C[0x208 - 0x4C];
    s32 unk208;
    u8 pad20C[0x28C - 0x20C];
    s32 unk28C;
    u8 *unk290;
    u8 pad294[0x2D0 - 0x294];
    void *unk2D0;
    u8 pad2D4[0x34C - 0x2D4];
    s32 unk34C;
    u8 pad350[0x3E0 - 0x350];
    s32 unk3E0;
    u8 pad3E4[0x42C - 0x3E4];
    s32 unk42C;
    s32 unk430;
    u8 pad434[0x964 - 0x434];
    void *unk964;
    s32 unk968;
    u8 pad96C[0xF14 - 0x96C];
    s8 unkF14;
    u8 padF15[0x1B28 - 0xF15];
    u8 unk1B28[0x2208 - 0x1B28];
    f32 unk2208[0x10];
    void *unk2248;
    s32 pad224C;
    s32 unk2250;
    u8 pad2254[0x2384 - 0x2254];
    s32 unk2384;
} Sk26650;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x1C - 0x10];
    s32 unk1C;
    u8 pad20[0x154 - 0x20];
} Rec26650;

typedef struct {
    u8 pad[0x18C];
} Plr26650;

void *func_8004B514(s32);
void *func_80073AE0(void *, Sk26650 *, s32);
void func_800A5730(void *, s32);
void func_80027FF4(Sk26650 *);
void func_80027E20(Sk26650 *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_8004B630(Sk26650 *, s32);
void func_8009CAD0(f32 *);
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;
extern u8 D_800D0FE8;
extern Plr26650 D_800D49E0[];
extern u8 D_800D62DC[][5];
extern s32 D_800D6FC8;
extern s32 D_800D6F90;
extern s32 D_800D6F98;
extern s32 D_800DE86C;
extern Rec26650 D_800D4D80[];

#define CALC(dst, g)                                                         \
    {                                                                        \
        s32 *out = &(dst);                                                   \
        s32 t;                                                               \
        s32 x;                                                               \
        x = D_800D6FC8;                                                      \
        if (x == 0) {                                                        \
            s32 base = D_800D4D80[s->unk3E0].unk1C;                          \
            s32 n = s->unk290[1];                                            \
            if (s->unk34C != 0 || D_800DE86C != 0) {                         \
                t = (g) - 10;                                                \
                n += 3;                                                      \
                x = base + n;                                                \
            } else {                                                         \
                t = (g) - 10;                                                \
                x = base + n;                                                \
            }                                                                \
        } else {                                                             \
            t = (g) - 10;                                                    \
        }                                                                    \
        *out = (((t + x) << 12) * 45) / 28;                                  \
    }

void func_80026650(Sk26650 *s, s32 arg1, s32 arg2) {
    void *b;

    b = func_80073AE0(func_8004B514(0x724), s, 0);
    s->unk2248 = b;
    s->unk2D0 = b;
    func_800A5730(s->unk1B28, 1);
    s->vt->e.fn((u8 *)s + s->vt->e.off, arg1, arg2);
    if (D_800DE7A0 == 7 || D_800DE9A8 == 1) {
        D_800D0FE8 = 3;
    } else {
        D_800D0FE8 = 0;
    }
    func_80027FF4(s);
    func_80027E20(s, 500.0f, -48.0f, s->unkF14 * 200, 0.0f, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f);
    {
        Plr26650 *p = D_800D49E0;
        s->unk964 = &p[s->unkF14];
    }
    {
        u8 (*q)[5] = D_800D62DC;
        s->unk290 = q[s->unkF14];
    }
    func_8004B630(s, s->unkF14);
    s->unk968 = s->unkF14;
    CALC(s->unk42C, D_800D6F90);
    CALC(s->unk430, D_800D6F98);
    if (D_800D4D80[s->unk3E0].unkC == 0x4000) {
        s->unk28C |= 0x1000;
    }
    func_8009CAD0(s->unk2208);
    s->unk2250 = 0;
    s->unk2384 = -1;
    if (s->unk3E0 == 0) {
        s->unk208 &= ~2;
    } else {
        s->unk208 |= 2;
    }
}
