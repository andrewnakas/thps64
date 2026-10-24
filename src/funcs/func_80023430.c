/* cflags: -fexpensive-optimizations */
#include "common.h"

void func_800242CC(void);
s32 func_800246EC(void *, s32);
void func_8002C0C0(void *);
void func_800352D4(void);
void func_8003A368(void *);
void func_80061F3C(void);
void func_80065CD0(void);
void func_80065E8C(void);
void func_80066164(void);
void func_8006D120(void);
void func_800849B0(void *);
s32 func_80084F00(s32);
void func_8008B25C(s32);
void func_8008B2C0(s32, s32);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_8008BB50(void *);
s32 func_800976B4(s32);
void func_8009BD70(void *, char *, char *, ...);
void func_8009BF04(void *, s32);
void func_8009BF80(void *);
void func_8009C348(void *, s32);
s32 func_8009E30C(s32);
void func_8009FD60(void *, char *);
void func_800A73EC(void *, s32);
void func_800A8E90(void *, f32);
void func_800A8FBC(void *, f32);
void func_800B2660(void *, void *);
s32 func_800B3CF0(s32);
void func_800B41D4(void);
void func_800BAB04(void *, s32);
s32 func_800C01C8(void);
void *func_800C0E00(s32);

extern u8 D_80016B80[];
extern u16 D_80016B84;
extern s32 D_80016B88;
extern s32 D_80016B90;
extern char D_80016B98[];
extern char D_80016BA4[];
extern char D_80016BB4[];
extern char D_80016BB8[];
extern char D_80016BBC[];
extern char D_80016BC0[];
extern char D_80016BC4[];
extern char D_80016BC8[];
extern s32 D_800D0FB4;
extern u8 D_800D0FC0[];
extern s16 D_800D0FD8;
extern u8 D_800D0FE9;
extern u8 *D_800D275C;
extern u8 D_800D3130[];
extern u8 D_800D3F34[];
extern s32 D_800DC614;
extern s32 D_800DE998;
extern u8 D_800E8A20[];
extern u8 D_800EA9C0[];
extern u8 D_800ECEF4[];
extern u8 D_800EECF0[];
extern u8 D_800F566C[];
extern s32 D_800F56BC;

#define CFG(t, o) (*(t *)(D_800D0FC0 + (o)))

void func_80023430(u8 *arg0) {
    u8 buf[8];
    u8 *c;
    u8 *e;
    u8 *e1;
    u8 *e2;
    u8 *e3;
    u8 *e4;
    u8 *sub;
    u8 *t;
    s32 n;

    c = D_800D0FC0;
    c[0x1B] = 0;
    c[0x1C] = 0;
    c[0x1D] = 0;
    *(s32 *)(c + 0x10) = 0;
    *(s32 *)(c + 0xECC) = 0;
    c[0x4] = 0;
    func_8003A368(D_800D3F34);
    if (func_800B3CF0(0) == 0) {
        D_800D0FB4 = 0x24;
    } else {
        D_800D0FB4 = 2;
    }
    if (func_800C01C8() == 0) {
        D_800D0FE9 = 1;
        D_800D0FB4 = 0x24;
    } else {
        D_800D0FE9 = 0;
    }
    e1 = D_800EECF0;
    func_800BAB04(e1, 0x4C6);
    func_800BAB04(e1, 0x501);
    func_8008BB50(buf);
    t = D_800D3130;
    e4 = t + 0x1AC;
    func_800A73EC(e4, 0x4C6);
    func_8008B490(buf, e4, 0x4C6);
    D_800D0FD8 = 0;
    *(u16 *)(t + 0x4E0) = D_80016B84;
    if (D_800F56BC == 0) {
        *(s32 *)(t + 0x4E4) = D_80016B88;
    } else {
        *(s32 *)(t + 0x4E4) = D_80016B90;
    }
    func_8002C0C0(D_80016B80);
    func_800B41D4();
    sub = D_800D0FC0 + 0xEA8;
    func_8009FD60(sub, D_80016B98);
    *(s32 *)(sub + 0x18) = 0x13;
    *(f32 *)(sub + 0x14) = 15000.0f;
    *(s32 *)(arg0 + 0x1EC) = 0;
    D_800DC614 = 0;
    CFG(u8, 0x22) = 0;
    CFG(f32, 0x34) = 25.0f;
    CFG(f32, 0x2C) = CFG(f32, 0x30) = 1.0f;
    e2 = D_800EA9C0;
    func_800A8E90(e2, CFG(f32, 0x2C));
    func_800A8FBC(e2, CFG(f32, 0x2C));
    func_800242CC();
    D_800D275C = (D_800DE998 = 0, (u8 *)func_800C0E00(0x6000));
    e3 = D_800F566C;
    n = func_800246EC(e3, 4);
    {
        u8 *x = *(u8 **)(e3 + 4);
        func_800B2660(D_800ECEF4, x + n);
    }
    func_8008B25C(0);
    func_8008B2C0(1, 0);
    *(s32 *)(sub + 0x20) = func_80084F00(func_8009E30C(0x5960));
    *(s32 *)(arg0 + 0x1F0) = func_800976B4(func_8009E30C(1));
    func_800352D4();
    func_800849B0(D_800E8A20);
    e = &CFG(u8, 0x40);
    func_80065CD0();
    func_8006D120();
    func_80066164();
    func_80065E8C();
    func_80061F3C();
    func_8009C348(e, 1);
    func_8009BD70(e, D_80016BA4, D_80016BB4,
                  0.0, 3.0, 1.5, 0.01, sub - 0x1C, 8, D_80016BB8,
                  0.0, 3.0, 0.0, 0.01, sub - 0x18, 8, D_80016BBC,
                  0.0, 3.0, 1.0, 0.01, sub - 0x14, 8, D_80016BC0,
                  0.0, 3.0, 1.0, 0.01, sub - 0x10, 8, D_80016BC4,
                  0.0, 3.0, 1.0, 0.01, sub - 0xC, 8, D_80016BC8,
                  0.0, 3.0, 1.0, 0.01, sub - 0x8, 8, NULL);
    func_8009BF04(e, -1);
    func_8009BF80(e);
    *(s32 *)(arg0 + 0x1E8) = 0;
    *(s32 *)(sub + 0x24) = 0;
    func_8008BB2C(buf, 2);
}
