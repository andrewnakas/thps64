/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* func_80069064 (TC2): matches with the stock cc1. The three D_800D6FC8 toggles (cases 0x37645655, 0x55BCFAB8, 0xE1B9395C) must all be written `if (x == K) x = 0; else x = K;`; any other polarity mix lets jump2 cross-jump the `x = 0` blocks and merge the cases. */
#include "common.h"

s32 func_8005BF24(u32);
void func_80042068(s32);
void func_80068FB0(void);
extern u8 D_800D49E0[];
extern u8 *D_800D61A8;
extern s32 D_800D60FC;
extern s32 D_800D613C;
extern s32 D_800D6F90;
extern s32 D_800D6F94;
extern s32 D_800D6F98;
extern s32 D_800D6FC8;
extern u32 D_800DC5D0;
extern s32 D_800DE7F8;
extern s32 D_800DE834;
extern s32 D_800DE838;
extern s32 D_800DE83C;
extern s32 D_800DE840;
extern s32 D_800DE844;
extern s32 D_800DE848;
extern s32 D_800DE85C;
extern s32 D_800DE860;
extern s32 D_800DE864;
extern s32 D_800DE86C;
extern s32 D_800E9250;

static inline void hash(u32 k) {
    D_800DC5D0 = (((D_800DC5D0 ^ k) << 1) ^ ((D_800DC5D0 ^ k) >> 31)) * 0x209;
    D_800DC5D0 += func_8005BF24(D_800DC5D0);
}

s32 func_80069064(void) {
    s32 r;
    u8 *b;

    r = 1;
    b = D_800D49E0;
    if (b[0xA1] != 0) {
        hash(0x1234567);
    } else if (b[0x91] != 0) {
        hash(0xAB432901);
    } else if (b[0xB1] != 0) {
        hash(0x776643D1);
    } else if (b[0x81] != 0) {
        hash(0x93FE1682);
    } else if (b[0x1] != 0) {
        hash(0x31415926);
    } else if (b[0x21] != 0) {
        hash(0xDEADBEEF);
    } else if (b[0x31] != 0) {
        hash(0xB87610DB);
    } else if (b[0x11] != 0) {
        hash(0x3185332);
    } else {
        return 0;
    }
    switch (D_800DC5D0) {
    case 0x4D8F4CAB:
        func_80042068(0x5CD);
        break;
    case 0xD04A5E2D:
        func_80042068(0x5CF);
        break;
    case 0xA4BD8F4E:
        func_80042068(0x5CE);
        break;
    case 0x12C10E71:
        D_800DE86C ^= 1;
        break;
    case 0x046C607C:
        D_800DE860 = 0;
        D_800DE838 ^= 1;
        break;
    case 0x65931E7B:
        D_800DE838 = 0;
        D_800DE860 ^= 1;
        break;
    case 0x22CA8241:
        D_800DE864 ^= 1;
        break;
    case 0x54AB538A:
        if (D_800D6F90 == 100) {
            D_800D6F90 = 0x31;
            D_800D6F94 = 0x20;
            D_800D6F98 = 0x1B;
        } else {
            D_800D6F90 = 100;
            D_800D6F94 = 0x5A;
            D_800D6F98 = 0x46;
        }
        break;
    case 0x37645655:
        if (D_800D6FC8 == 10) {
            D_800D6FC8 = 0;
        } else {
            D_800D6FC8 = 10;
        }
        break;
    case 0xA7053A01:
        D_800DE844 ^= 1;
        break;
    case 0x55BCFAB8:
        if (D_800D6FC8 == 13) {
            D_800D6FC8 = 0;
        } else {
            D_800D6FC8 = 13;
        }
        break;
    case 0x021A16ED:
        D_800DE848 ^= 1;
        break;
    case 0x636897C0:
        D_800DE7F8 ^= 1;
        func_80068FB0();
        break;
    case 0x06A8548A:
        func_80042068(0x5CA);
        break;
    case 0x4C262611:
        func_80042068(0x5C9);
        break;
    case 0x7F51F79B:
        func_80042068(0x5CB);
        break;
    case 0x1292C125:
        func_80042068(0x5CC);
        break;
    case 0x18D63B4F:
        D_800DE83C ^= 1;
        break;
    case 0x34A3362F:
        *(s32 *)(D_800D61A8 + 0x428) = D_800D613C + 10;
        break;
    case 0x38E83447:
        D_800DE840 ^= 1;
        break;
    case 0x51B08439:
        D_800DE834 ^= 1;
        break;
    case 0xE1B9395C:
        if (D_800D6FC8 == 3) {
            D_800D6FC8 = 0;
        } else {
            D_800D6FC8 = 3;
        }
        break;
    case 0x45A930EF:
        D_800DE85C ^= 1;
        break;
    case 0x0607C10B:
        D_800D60FC ^= 1;
        break;
    case 0x06CA00B4:
        D_800E9250 = !D_800E9250;
        break;
    case 0x03991E38:
        break;
    case 0x9A40C6BC:
        break;
    case 0x8CED399A:
        break;
    case 0xC8488025:
        break;
    default:
        r = 0;
        break;
    }
    return r;
}
