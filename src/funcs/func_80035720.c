#include "common.h"

typedef struct {
    u8 pad[0x14];
    void *p14;
    u8 pad18[0x48];
    s32 v60;
    u8 pad64[0x14];
} E78;

extern u8 D_80019DF0[];
extern u8 D_800D3130[];
extern u8 D_800E918C[];
extern s32 D_800DE804;
extern s32 D_800DE7CC;
extern char D_80019CA4[];
extern char D_80019CAC[];
extern u8 D_800DAF98[];
extern u8 D_800DACCD;
extern u8 D_800D0FC0[];
extern s32 D_800E929C[];
extern E78 D_800D5C1C[];
extern s32 D_800FA610;
void func_80039500(void);
void func_8002C12C(void *);
void func_8008BB50(void *);
void func_800A73EC(void *, s32);
void func_8008B490(void *, void *, s32);
void func_800356E4(s32, s32, s32);
void func_80043B24(void);
void func_80095A40(void *);
void func_80063160(void);
s32 func_8006278C(char *, s32, s32);
void func_8005F02C(void *);
void func_80036FA4(void *);
void func_800B389C(s32);
void func_8008BB2C(void *, s32);

u8 *func_80035720(u8 *arg0) {
    u8 sp10[8];
    u8 *p;
    u8 *tbl;
    u8 *g;
    s32 *q;
    s32 i;
    s32 j;
    s32 one;

    func_80039500();
    *(void **)(arg0 + 0x2C) = D_80019DF0;
    func_8002C12C(arg0 + 0x58);
    *(s32 *)(arg0 + 0x44) = 0;
    func_8008BB50(sp10);
    p = D_800D3130;
    p += 0x1AC;
    func_800A73EC(p, 0x4C6);
    func_8008B490(sp10, p, 0x4C6);
    func_800356E4(0, 0, 0);
    func_80043B24();
    func_80095A40(D_800E918C);
    tbl = D_800DAF98;
    func_80063160();
    D_800DE804 = 0;
    D_800DE7CC = 0;
    (tbl + func_8006278C(D_80019CA4, 0, 0) * 0x48)[0x13] = (one = 1);
    i = func_8006278C(D_80019CAC, 0, 0);
    (tbl + i * 0x48)[0x13] = one;
    D_800DACCD = i;
    g = D_800D0FC0;
    *(s32 *)(arg0 + 0x38) = g[0x14];
    *(s32 *)(arg0 + 0x3C) = g[0x15];
    *(s32 *)(arg0 + 0x40) = *(s32 *)(g + 0xEC0);
    *(void **)(arg0 + 0x48) = g + 0xEA8;
    q = D_800E929C;
    if (D_800E929C[0] != 0) {
        *(s32 *)(arg0 + 0x38) = q[1];
        *(s32 *)(arg0 + 0x3C) = q[2];
        *(s32 *)(arg0 + 0x40) = j = q[3];
        *(void **)(arg0 + 0x48) = D_800D5C1C[j].p14;
        *(s32 *)(arg0 + 0x40) = D_800D5C1C[*(s32 *)(arg0 + 0x40)].v60;
    }
    func_8005F02C(*(void **)(arg0 + 0x48));
    func_80036FA4(arg0);
    func_800B389C(1);
    D_800FA610 = 3;
    func_8008BB2C(sp10, 2);
    return arg0;
}
