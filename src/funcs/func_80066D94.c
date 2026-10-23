#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s16 unk10;
    u8 pad12[2];
    void (*unk14)(void *);
} VT_80066D94;

typedef struct {
    u16 unk0;
    u8 pad2[0x38];
    u16 unk3A;
    u8 pad3C[0xC];
    VT_80066D94 *unk48;
    u8 pad4C[0x162 - 0x4C];
    s16 unk162;
    u8 pad164[0x210 - 0x164];
    u8 unk210;
    u8 pad211[5];
    u16 unk216;
} Unk80066D94;

typedef struct {
    u8 pad0[0x450];
    s32 unk450;
    u8 pad454[0x82C - 0x454];
    s32 unk82C;
} Unk80066D94b;

s32 func_80039E60(s32, s32, s32);
void func_8003A178(s32, s32);
void func_80045870(s32);
s32 func_800462B8(s32);
s32 func_8004C5B8(Unk80066D94b *, s16);
void func_8004C9E8(Unk80066D94b *);
void func_8004CACC(Unk80066D94b *, s32, void *, s32, s32);
void func_8004CC10(Unk80066D94b *);
s32 func_80061904(u16);
void func_80061BC8(s32);
void func_8006EE1C(s32, void *, s32, s32, s32);
void func_8006EEF0(void);
typedef struct { f32 x, y, z; } V3_80066D94;
extern V3_80066D94 D_8001CC6C;
extern V3_80066D94 D_8001CC78;
extern V3_80066D94 D_8001CC84;
extern Unk80066D94b *D_800D61A8;
extern u8 D_800DC95C[];
extern s32 D_800DDEF0;
extern s32 D_800DDEF8;
extern s32 D_800DDEFC;
extern s32 D_800DDF00;
extern s32 D_800DDF04;
extern s32 D_800DE9A8;

void func_80066D94(Unk80066D94 *arg0, Unk80066D94b *arg1) {
    s32 hit;
    s32 snd;
    s32 m;
    s32 h;
    s32 f;
    V3_80066D94 *p;

    if (D_800DE9A8 != 1 && arg1 == D_800D61A8) {
        f = arg0->unk0 & 0x40;
    } else {
        f = arg0->unk0 & 1;
    }
    hit = 0;
    if (f != 0) {
        return;
    }
    snd = hit;
    switch (arg0->unk3A) {
    case 4:
    case 5:
    case 6:
    case 10:
    case 14:
    case 15:
    case 16:
        hit = func_8004C5B8(arg1, arg0->unk162);
        if (hit != 0) {
            m = 0;
            func_8006EEF0();
            switch (arg0->unk3A) {
            case 5:
                func_80039E60(0x14, 10000, 0);
                if (func_800462B8(0) == 0) {
                    m = D_800DDEFC;
                }
                break;
            case 4:
                func_80039E60(0x14, 10000, 0);
                if (func_800462B8(1) == 0) {
                    m = D_800DDF00;
                }
                break;
            case 6:
                func_80039E60(0x14, 10000, 0);
                if (func_800462B8(2) == 0) {
                    m = D_800DDF04;
                }
                break;
            case 15:
                func_80039E60(0x14, 10000, 0);
                if (func_800462B8(3) == 0) {
                    m = D_800DDEF0;
                }
                break;
            case 10:
                func_80039E60(0x14, 10000, 0);
                if (func_800462B8(4) == 0) {
                    m = D_800DDEF8;
                }
                break;
            case 16:
                func_80045870(3);
                m = 0;
                break;
            }
            if (m != 0) {
                func_8006EE1C(m, D_800DC95C, 1, 0, 0);
            }
        }
        break;
    case 21:
    case 22:
    case 23:
        if (arg1->unk450 == 0) {
            hit = 1;
            if (arg1->unk82C == 0) {
                func_8004C9E8(arg1);
            }
            h = func_80039E60(0x12, 10000, 0);
            switch (arg0->unk3A) {
            case 21:
                p = &D_8001CC6C;
                func_8004CACC(arg1, 0x4C, p, -100, 0);
                func_8003A178(h, 900);
                break;
            case 22:
                p = &D_8001CC78;
                func_8004CACC(arg1, 0x4C, p, -200, 0);
                func_8003A178(h, 1114);
                break;
            case 23:
                p = &D_8001CC84;
                func_8004CACC(arg1, 0x4C, p, -500, 0);
                func_8003A178(h, 1500);
                break;
            }
            if (arg1->unk82C == 0) {
                func_8004CC10(arg1);
            }
        }
        break;
    }
    if (arg0->unk210 != 0) {
        func_80061BC8(func_80061904(arg0->unk216));
    }
    if (hit != 0) {
        arg0->unk48->unk14((u8 *)arg0 + arg0->unk48->unk10);
        if (snd != 0) {
            func_80039E60(snd, 10000, 0);
        }
    }
}
