/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 pad0[8];
    u8 b20;
    u8 pad21[0x8F];
    u8 bB0;
    u8 padB1[0xDB];
} Plr36664;

typedef struct {
    u8 pad0[0xC];
    s32 xC;
    u8 pad10[0x68];
} Ent5C1C_36664;

void func_80027FF4(u8 *);
void func_8003A360(void);
void func_8003A410(void *, s32, s32);
void func_80043B88(void);
void func_800437E8(void);
void func_80043CC0(void);
void func_80044024(s32);
s32 func_8004AEE0(void *);
void func_8006CB4C(void);
void func_8008C170(void);
void func_8008C274(void);
void func_800955C0(void);
void func_80095680(void);
void func_800A9460(void *, s32, f32, s32);
void func_800AA864(void *);
extern s32 D_800C0E20;
extern u8 D_800D0FC0[];
extern u8 D_800D0FE3;
extern s32 D_800D3E94;
extern u8 D_800D3F34[];
extern Plr36664 D_800D49E0[2];
extern u8 D_800D4AD0;
extern Ent5C1C_36664 D_800D5C1C[];
extern volatile s32 D_800D6138;
extern void *D_800D61A8;
extern s32 D_800DE7A0;
extern u8 *D_800DE7A8;
extern u8 *D_800DE7AC;
extern s32 D_800DE7C4;
extern s32 D_800DE7E0;
extern s32 D_800DE804;
extern s32 D_800DE808;
extern s32 D_800DE820;
extern s32 D_800DE868;
extern s32 D_800DE93C;
extern s32 D_800DE964;
extern s32 D_800DE968;
extern s32 D_800DE994;
extern s32 D_800DE9A8;
extern s32 D_800DE9AC;
extern s32 D_800DE9B0;
extern s32 D_800DE9B4;
extern s32 D_800DE9C4;
extern s32 D_800DE9D0;
extern s32 D_800DE9E4;
extern s32 D_800DE9EC;
extern s32 D_800E9038;
extern u8 D_800EA9C0[];

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_80036664(u8 *arg0) {
    Plr36664 tmp;
    s32 m;
    s32 n;
    u8 b;
    Ent5C1C_36664 *e;

    D_800D6138;
    D_800DE808++;
    if (W(D_800DE7A8, 0x82C) == 0 && (D_800DE7AC == NULL || W(D_800DE7AC, 0x82C) == 0) && D_800DE9AC == 1 &&
        --D_800DE9B0 <= 0) {
        D_800DE820 = 1;
        if (D_800DE7A0 != 7 && (W(D_800DE7A8, 0xB5C) != 0 || (D_800DE9A8 == 2 && W(D_800DE7AC, 0xB5C) != 0))) {
            D_800DE9B4 = 0;
            D_800DE9B0 = 1;
        } else if (W(arg0, 0x30) == 0) {
            D_800DE7C4 = 1;
            func_800A9460(D_800EA9C0, 0, 0.0f, -1);
            func_800AA864(D_800EA9C0);
            D_800DE9B4 = 0;
            D_800DE9B0 = 2;
            e = D_800D5C1C;
            if (e[D_800C0E20].xC != 0 && D_800DE7A0 == 1) {
                func_8008C170();
                W(arg0, 0x30) = 0x30;
            } else {
                func_8008C274();
                W(arg0, 0x30) = 0x2B;
                if (D_800DE7E0 == 11) {
                    W(arg0, 0x30) = 0x2C;
                }
            }
        }
    }
    func_8003A360();
    if (W(arg0, 0x54) == 0 && D_800DE994 >= 101) {
        if (D_800DE7A0 != 7 && D_800E9038 == 0 && D_800DE820 == 0 && D_800DE9AC != 1 && D_800D0FE3 != 8) {
            func_8003A410(D_800D3F34, 0, -1);
        }
        W(arg0, 0x54) = 1;
    }
    if (D_800DE7A0 == 7 && D_800DE9C4 == 1) {
        tmp = D_800D49E0[0];
        D_800D49E0[0] = D_800D49E0[1];
        D_800D49E0[1] = tmp;
    }
    func_80043B88();
    func_800437E8();
    func_80043CC0();
    if (D_800DE7A0 == 7 && D_800DE9C4 == 1) {
        tmp = D_800D49E0[0];
        D_800D49E0[0] = D_800D49E0[1];
        D_800D49E0[1] = tmp;
    }
    if (D_800DE964 != 0) {
        func_80044024(0);
    }
    if (D_800DE968 != 0) {
        func_80044024(1);
    }
    func_8006CB4C();
    m = D_800DE9AC;
    if (m == 1 && D_800E9038 == 0) {
        if (W(D_800DE7A8, 0x82C) == 0) {
            b = D_800D49E0[0].b20;
            func_80044024(0);
            D_800D49E0[0].b20 = b;
            D_800D49E0[0].bB0 = m;
        }
        if (D_800DE9A8 == 2 && D_800DE7A0 != 7 && W(D_800DE7AC, 0x82C) == 0) {
            b = D_800D49E0[1].b20;
            func_80044024(1);
            D_800D49E0[1].b20 = b;
            D_800D49E0[1].bB0 = m;
        }
    }
    if (D_800DE9A8 == 1 || (D_800DE7A0 == 7 && D_800DE9EC != 0)) {
        if (D_800DE868 == 0) {
            func_80044024(1);
        }
    }
    if (D_800DE7A0 == 7) {
        if (D_800DE9E4 == 0) {
            D_800DE9D0 = 1;
            D_800DE9E4 = 1;
            func_800955C0();
        } else if (D_800DE9D0 == 0) {
            D_800DE9D0 = 1;
            func_80095680();
        }
    }
    if (D_800DE7A0 != 7 && D_800DE9AC == 1 && D_800DE9B0 < 40 && W(D_800DE7A8, 0x82C) == 0 &&
        (D_800DE7AC == NULL || W(D_800DE7AC, 0x82C) == 0)) {
        W(*(u8 **)(D_800DE7A8 + 0x2248), 0x668) += D_800DE9B4;
        if (D_800DE7AC != NULL) {
            W(*(u8 **)(D_800DE7AC + 0x2248), 0x668) += D_800DE9B4;
        }
    }
    if (func_8004AEE0(D_800D61A8) != 0) {
        D_800DE804 = 2;
    }
    if (D_800DE868 == 0) {
        if (D_800D4AD0 != 0) {
            if (D_800D3E94 != 0) {
                D_800D3E94 = 0;
                n = D_800DE9A8;
                if (n != 2) {
                    return;
                }
                if (D_800DE7A0 != 7) {
                    D_800DE93C++;
                    D_800D0FC0[0x28] = (D_800D0FC0[0x28] + 1) % 3;
                    func_80027FF4(D_800DE7A8);
                    func_80027FF4(D_800DE7AC);
                    if (D_800D0FC0[0x28] == 0) {
                        D_800DE93C = 4;
                    } else if (D_800D0FC0[0x28] == 1) {
                        D_800DE93C = 3;
                    } else if (D_800D0FC0[0x28] == 2) {
                        D_800DE93C = 2;
                    }
                    if (D_800DE93C >= 4) {
                        D_800DE93C = 0;
                    }
                }
            }
        } else {
            D_800D3E94 = 1;
        }
    }
    if (D_800DE9A8 == 2 && D_800DE93C == 0 && D_800DE7A0 != 7) {
        D_800DE93C = 1;
    }
}
