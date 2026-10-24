/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mtx_8004B77C;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} Lvl_8004B77C;

void func_8004AE80(void *);
void func_8006ED10(void *);
void func_8005BED8(void *);
void func_8004B30C(void *, void *);
extern u8 D_8001B4E8[];
extern s32 D_800C0E20;
extern u8 D_800D49E0[];
extern u8 D_800D4B6C[];
extern Lvl_8004B77C D_800D5C1C[];
extern s32 D_800D61A4;
extern u8 D_800D61A8[];
extern u8 D_800D61AC[];
extern s32 D_800DE7A0;

#define W(o) (*(s32 *)(arg0 + (o)))
#define H(o) (*(s16 *)(arg0 + (o)))
#define P(o) (*(void **)(arg0 + (o)))

static inline void seth3(u8 *arg0, s32 x, s32 y, s32 z) {
    H(0x100) = x;
    H(0x102) = y;
    H(0x104) = z;
}

static inline void setb3(u8 *arg0, u8 x, u8 y, u8 z) {
    arg0[0xE0] = x;
    arg0[0xE1] = y;
    arg0[0xE2] = z;
}

void *func_8004B77C(u8 *arg0) {
    u8 *sub;
    s32 i;
    s32 k;

    func_8004AE80(arg0);
    P(0x48) = D_8001B4E8;
    sub = arg0 + 0xA1C;
    P(0xA1C) = arg0;
    W(0xA20) = 0;
    W(0xB70) = 0;
    W(0xB74) = 0;
    func_8006ED10(arg0 + 0xB80);
    W(0xBC8) = 0;
    func_8006ED10(arg0 + 0xBCC);
    W(0xDA4) = 0;
    W(0xED8) = 0;
    W(0xF10) = 0;
    {
        s32 j;
        for (j = 4; j >= 0; j--) {
            ((s32 *)(sub + 0x4C8))[j] = 0;
        }
    }
    *(s32 *)(sub + 0x4E4) = 0;
    *(s32 *)(sub + 0x4E0) = 0;
    *(s32 *)(sub + 0x4DC) = 0;
    W(0x228) = 0x10000;
    if (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) {
        W(0x428) = 0xE2E;
    } else if (D_800DE7A0 == 7) {
        W(0x428) = 0x276;
    } else {
        W(0x428) = 0x1C3E;
    }
    k = 1000;
    W(0x2C0) = 0;
    W(0x2C4) = k;
    W(0x2C8) = 0;
    *(u16 *)arg0 |= 0x200;
    H(0x24) = 0x1000;
    H(0x26) = 0x1000;
    H(0x28) = 0x1000;
    W(0x438) = 0x1E;
    W(0x43C) = 0x1E;
    W(0x208) |= 1;
    W(0x7D4) = 0;
    W(0x7D8) = 0;
    W(0x804) = 0;
    W(0x808) = -1;
    W(0x7C0) = 0;
    W(0x7C4) = 0;
    W(0x82C) = 1;
    W(0x830) = 1;
    W(0x7A0) = 0;
    W(0x834) = 0;
    W(0x838) = 0;
    W(0x83C) = 0;
    W(0x454) = 0;
    W(0x848) = 0;
    W(0x51C) = 0;
    for (i = 0x4F; i >= 0; i--) {
        ((s32 *)(arg0 + 0x520))[i] = 0;
    }
    for (i = 0x4F; i >= 0; i--) {
        ((s32 *)(arg0 + 0x660))[i] = 0;
    }
    W(0x85C) = 0;
    W(0x860) = 0;
    W(0x8F4) = 0;
    W(0x8F8) = 0;
    W(0x8FC) = 0;
    W(0x900) = 0;
    H(0x904) = 0;
    H(0x906) = -0x1000;
    H(0x908) = 0;
    W(0x92C) = 0;
    W(0x930) = 0;
    W(0x934) = 0;
    W(0x938) = 0;
    H(0x884) = -0x1000;
    H(0x88A) = 0;
    H(0x890) = 0;
    H(0x886) = 0;
    H(0x88C) = -0x1000;
    H(0x892) = 0;
    H(0x888) = 0;
    H(0x88E) = 0;
    H(0x894) = -0x1000;
    func_8005BED8(arg0);
    *(Mtx_8004B77C *)(arg0 + 0x864) = *(Mtx_8004B77C *)(arg0 + 0x884);
    W(0x91C) = H(0x886);
    W(0x920) = H(0x88C);
    W(0x924) = H(0x892);
    seth3(arg0, W(0x91C), W(0x920), W(0x924));
    W(0x918) = 0;
    H(0xE4) = 2;
    func_8004B30C(arg0, D_800D61A8);
    D_800D61A4++;
    *(u16 *)(arg0 + 0x52) &= ~2;
    if (D_800D61A4 == 1) {
        P(0x964) = D_800D49E0;
    } else {
        P(0x964) = D_800D4B6C;
    }
    setb3(arg0, 5, 1, 5);
    P(0x3C) = D_800D61AC;
    return arg0;
}
