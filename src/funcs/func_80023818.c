/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 adj;
    s32 (*fn)(void *, ...);
} VEnt23818;

typedef struct {
    u8 pad0[8];
    VEnt23818 e1;
    VEnt23818 e2;
} VTbl23818;

typedef struct {
    u8 pad0[0x28];
    s32 x28;
    VTbl23818 *vt;
} Scene23818;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    u8 pad4[0xC];
    s32 x10;
    u8 pad14[2];
    u8 b16;
    u8 pad17[0x1D];
    f32 x34;
} G23818;

typedef struct {
    u8 pad0[0x1E8];
    f32 x1E8;
    s32 x1EC;
    s32 x1F0;
} Main23818;

void *func_80024980(void *);
void *func_80026588(void *);
void *func_800284A0(void *);
void *func_800290E0(void *);
void *func_80029660(void *);
void *func_80029EC0(void *, Main23818 *);
void *func_8002AAD0(void *);
void *func_8002B360(void *);
void *func_8002C170(void *);
void *func_8002C8C8(void *);
void *func_8002C950(void *);
void *func_8002EC80(void *);
void *func_800308A0(void *);
void *func_80035720(void *);
void *func_800378BC(void *);
void func_8003A6AC(void *);
void *func_8003A900(void *);
void *func_8003AF00(void *);
void *func_8003BA00(void *);
void *func_8003C9A0(void *);
void *func_8003E2E0(void *);
void *func_8003FFF0(void *);
void func_80042068(s32);
void *func_80042190(void *);
void *func_8004269C(void *);
void *func_80087930(void *);
void func_8008923C(void);
void *func_80089CC0(void *);
void func_8008B284(void);
void func_8008B2C0(s32, s32);
void func_800971E0(s32, s32);
void *func_800976C0(void *);
void *func_8009E30C(s32);
void func_8009F0EC(void *, s32);
void func_8009F150(void *);
void func_800A9460(void *, s32, f32, s32);
void func_800A9588(void *, s32);
void func_800A96BC(void *, s32);
s32 func_800B4240(s32, s32);
void func_800BC0F4(void *);
void func_800BDEA8(s32);
void func_800BE144(void);
extern s32 D_800D0FB0;
extern s32 D_800D0FB4;
extern s32 D_800D0FB8;
extern Scene23818 *D_800D0FBC;
extern G23818 D_800D0FC0;
extern u8 D_800D0FE3;
extern f32 D_800D0FF4;
extern u32 D_800D1E80;
extern u8 D_800D3F34[];
extern s32 D_800D6180;
extern s32 D_800DC5A0;
extern s32 D_800DDC60;
extern s32 D_800DE7A4;
extern s32 D_800DE820;
extern s32 D_800DE994;
extern s32 D_800DE998;
extern s32 D_800DE99C;
extern s32 D_800DE9A0;
extern s32 D_800E9038;
extern u8 D_800EA110[];
extern u8 D_800EA9C0[];
extern s32 D_800EECD8;
extern u8 D_800F0DD0[];
extern f32 D_800F5668;


void func_80023818(Main23818 *arg0) {
    s32 t;
    s32 r;
    s32 a;
    s32 b;
    s32 c;

    D_800DE99C = D_800F5668 * 7680.0f;
    D_800DE9A0 = (D_800DE99C * D_800DE99C) >> 8;
    t = D_800E9038 == 0;
    D_800EECD8 = t;
    if (D_800D0FB4 != D_800D0FB0) {
        if (D_800D0FBC != NULL) {
            func_800BC0F4(D_800F0DD0);
            if (D_800D0FBC != NULL) {
                D_800D0FBC->vt->e1.fn((u8 *)D_800D0FBC + D_800D0FBC->vt->e1.adj, 3);
            }
            func_8008B2C0(1, 0);
            D_800E9038 = 0;
            D_800DE820 = 0;
            func_80042068(-1);
            func_8009F150(D_800EA110);
            func_8009F0EC(D_800EA110, 0);
            D_800D0FE3 = 1;
            D_800DC5A0 = 0;
            D_800DE7A4 = 0;
            D_800D6180 = 0;
            D_800DDC60 = 0;
        }
        if (D_800D0FB4 < 0) {
            D_800D0FB4 = -D_800D0FB4;
        }
        switch (D_800D0FB4) {
        case 1:
            D_800D0FBC = func_80029EC0(func_8009E30C(0x304), arg0);
            break;
        case 5:
            D_800D0FBC = func_8002C8C8(func_8009E30C(0x48));
            break;
        case 4:
            D_800D0FF4 = 25.0f;
            func_800BE144();
            arg0->x1EC = 1;
            D_800D0FBC = func_8003A900(func_8009E30C(0x714));
            break;
        case 2:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_800976C0(func_8009E30C(0x98));
            break;
        case 3:
            func_800BE144();
            arg0->x1EC = 1;
            D_800D0FBC = func_8003BA00(func_8009E30C(0x284));
            break;
        case 17:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_80089CC0(func_8009E30C(0x444));
            break;
        case 6:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_8003C9A0(func_8009E30C(0x808));
            break;
        case 10:
            D_800D0FBC = func_8002C170(func_8009E30C(0x700));
            break;
        case 11:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_8003E2E0(func_8009E30C(0x3AC));
            break;
        case 14:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_8003FFF0(func_8009E30C(0x88C));
            break;
        case 8:
            D_800D0FBC = func_8002AAD0(func_8009E30C(0x700));
            break;
        case 9:
            D_800D0FBC = func_8002B360(func_8009E30C(0x58));
            break;
        case 7:
            D_800D0FBC = func_8002EC80(func_8009E30C(0x7B8));
            break;
        case 12:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_800308A0(func_8009E30C(0x67C));
            break;
        case 32:
            arg0->x1EC = 0;
            func_800BDEA8(0);
            D_800D0FBC = func_800378BC(func_8009E30C(0x830));
            break;
        case 36:
            arg0->x1EC = 0;
            func_800BDEA8(0);
            D_800D0FBC = func_80024980(func_8009E30C(0x274));
            break;
        case 35:
            arg0->x1EC = 0;
            func_800BDEA8(0);
            D_800D0FBC = func_80026588(func_8009E30C(0x2D0));
            break;
        case 33:
            if (arg0->x1EC != 0) {
                switch (D_800D1E80) {
                case 0x0:
                case 0x1:
                case 0x4:
                case 0x5:
                case 0xA:
                case 0xB:
                case 0xE:
                case 0xF:
                case 0x13:
                case 0x14:
                case 0x19:
                case 0x1A:
                case 0x31:
                case 0x32:
                case 0x37:
                case 0x38:
                case 0x3F:
                    func_800BDEA8(1);
                    break;
                default:
                    func_800BDEA8(0);
                    break;
                }
            }
            arg0->x1EC = 0;
            func_8009F0EC(D_800EA110, 1);
            func_8008B284();
            func_8008923C();
            D_800D0FBC = func_80035720(func_8009E30C(0x2BC));
            D_800D0FB4 = D_800D0FB0 = 1000;
            break;
        case 30:
            func_800971E0(arg0->x1F0, -1);
            if (arg0->x1EC != 0) {
                func_800BDEA8(0);
            }
            arg0->x1EC = 0;
            func_8009F0EC(D_800EA110, 1);
            func_8008B284();
            func_8008923C();
            D_800D0FBC = func_80035720(func_8009E30C(0x2BC));
            D_800D0FB4 = D_800D0FB0 = 1000;
            break;
        case 40:
            func_800971E0(arg0->x1F0, -2);
            if (arg0->x1EC != 0) {
                func_800BDEA8(0);
            }
            arg0->x1EC = 0;
            func_8009F0EC(D_800EA110, 1);
            func_8008B284();
            func_8008923C();
            D_800D0FBC = func_80035720(func_8009E30C(0x2BC));
            break;
        case 24:
            if (arg0->x1EC == 0) {
                func_800BE144();
            }
            arg0->x1EC = 1;
            D_800D0FBC = func_8003AF00(func_8009E30C(0x96C));
            break;
        case 28:
            D_800D0FBC = func_80087930(func_8009E30C(0x560));
            break;
        case 25:
            D_800D0FBC = func_800284A0(func_8009E30C(0x304));
            break;
        case 23:
            if (arg0->x1EC == 0) {
                func_800BE144();
            }
            arg0->x1EC = 1;
            D_800D0FBC = func_800290E0(func_8009E30C(0x710));
            break;
        case 26:
            D_800D0FBC = func_8002C950(func_8009E30C(0x848));
            break;
        case 37:
            D_800D0FBC = func_80042190(func_8009E30C(0x714));
            break;
        case 38:
            D_800D0FBC = func_8004269C(func_8009E30C(0x714));
            break;
        case 39:
            if (arg0->x1EC == 0) {
                func_800BE144();
                arg0->x1EC = 1;
            }
            D_800D0FBC = func_80029660(func_8009E30C(0x2C8));
            break;
        case 41:
            break;
        }
        D_800D0FBC->x28 = 0;
        D_800D0FB8 = D_800D0FB0;
        D_800D0FB0 = D_800D0FB4;
    }
    func_8003A6AC(D_800D3F34);
    r = D_800D0FBC->vt->e2.fn((u8 *)D_800D0FBC + D_800D0FBC->vt->e2.adj);
    if (r != 0) {
        D_800D0FB4 = r;
    }
    D_800D0FBC->x28++;
    if ((u32)(D_800D0FB4 - 3) < 2) {
        D_800D0FC0.x34 -= D_800F5668;
        if (D_800D0FC0.x34 <= 0.0) {
            D_800D0FB4 = 30;
            D_800D0FC0.x34 = 25.0f;
            func_800A9460(D_800EA9C0, 0, 0.0f, -1);
            func_800A9588(D_800EA9C0, 0x1F);
            func_800A96BC(D_800EA9C0, 0x39);
            *(s32 *)(D_800D3F34 + 0xD0) = 1;
        }
    }
    a = 0;
    if (D_800D0FC0.x10 == 1) {
        D_800D0FB4 = 39;
        D_800D0FC0.b16 = 0;
        D_800D0FC0.x10 = 0;
    }
    if (func_800B4240(D_800D0FC0.b2, 0x2000) != 0) {
        a = func_800B4240(D_800D0FC0.b2, 0x1000) != 0;
    }
    b = 0;
    if (func_800B4240(D_800D0FC0.b3, 0x2000) != 0) {
        b = func_800B4240(D_800D0FC0.b3, 0x1000) != 0;
    }
    if (a == 0 && b == 0) {
        arg0->x1E8 = 0.0f;
        c = 0;
    } else {
        arg0->x1E8 += D_800F5668;
        c = 0;
        if (arg0->x1E8 > 3.0) {
            c = 1;
        }
    }
    if (c != 0) {
        D_800D0FB4 = 4;
    }
    if (D_800E9038 == 0) {
        D_800DE998 += D_800DE99C * 2;
        D_800DE994 = D_800DE998 >> 8;
    }
}
