#include "common.h"

typedef struct {
    s32 x, y, z;
} V3;

extern char D_8001CD18[];
extern char D_8001CBE4[];
extern u8 D_800DACCD;
extern s32 D_800DE7A0;
extern u8 *D_800DE96C;
extern u8 *D_800DE970;
extern u8 *D_800DE974;
extern u8 *D_800DE978;
extern u8 *D_800DE97C;
extern u8 *D_800DE980;
extern char D_800DC5A0[];
extern void func_8004A08C(u8 *);
extern s32 func_80049D60(s32);
extern s32 func_80048DCC(void *, s32, s32);
extern void func_8004AF84(u8 *);
extern void func_8004B468(u8 *, char *);
extern s16 func_80063654(u32, u8);
extern void func_80033590(u32, u8 *, s32, s32, s32);
extern void func_8004B30C(u8 *, char *);
extern void func_80067308(u8 *);

#define W(o) (*(s32 *)(p + (o)))
#define H(o) (*(s16 *)(p + (o)))
#define UH(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define V(o) (*(V3 *)(p + (o)))

u8 *func_800664D0(u8 *p, s16 type, V3 *pos, V3 *vel, s32 flags, s16 arg5) {
    func_8004A08C(p);
    *(char **)(p + 0x48) = D_8001CD18;
    W(0x234) = 0;
    H(0x3A) = type;
    H(0x230) = arg5;
    B(0x214) = 0;
    V(0x21C) = *pos;
    V(0x4) = *pos;
    if (flags & 8) {
        W(0x88) = 0xFFFC4000;
    } else {
        V(0x84) = *vel;
    }
    B(0xB5) = 5;
    B(0xB6) = 5;
    B(0xB7) = 5;
    H(0xBA) = 100;
    W(0xA0) = 0x8000;
    H(0x22E) = func_80049D60(20) + 90;
    H(0x22A) = 50;
    H(0x22C) = 50;
    if (flags & 0x10) {
        B(0x212) = 1;
        B(0x213) = 1;
    } else if (flags & 4) {
        B(0x212) = 1;
        W(0x218) = func_80048DCC(p + 0x21C, 0, 8000);
    }
    H(0x15C) = 300;
    func_8004AF84(p);
    H(0x154) = 300;
    {
        char *t = D_8001CBE4;
        func_8004B468(p, t);
    }
    switch (UH(0x3A)) {
        case 5:
            B(0x211) = 1;
            H(0x16) = func_80063654(0x311D55D4, D_800DACCD);
            func_80033590(0x311D55D4, p, 1, -1, 0);
            break;
        case 4:
            B(0x211) = 1;
            H(0x16) = func_80063654(0x2328A71C, D_800DACCD);
            func_80033590(0x2328A71C, p, 1, -1, 0);
            break;
        case 6:
            B(0x211) = 1;
            H(0x16) = func_80063654(0x2EBF22CA, D_800DACCD);
            func_80033590(0x2EBF22CA, p, 1, -1, 0);
            break;
        case 15:
            B(0x211) = 1;
            H(0x16) = func_80063654(0x34524351, D_800DACCD);
            func_80033590(0x34524351, p, 1, -1, 0);
            break;
        case 10:
            B(0x211) = 1;
            H(0x16) = func_80063654(0x29B68A16, D_800DACCD);
            func_80033590(0x29B68A16, p, 1, -1, 0);
            break;
        case 16:
        case 18:
            H(0xBA) = 150;
            B(0x211) = 1;
            H(0x16) = func_80063654(0xD5108E8C, D_800DACCD);
            func_80033590(0xD5108E8C, p, 2, -1, 0);
            break;
        case 21:
            H(0xBA) = 200;
            B(0x211) = 1;
            H(0x16) = func_80063654(0x6F0F6B9F, D_800DACCD);
            func_80033590(0x6F0F6B9F, p, 2, -1, 0);
            break;
        case 22:
            H(0xBA) = 200;
            B(0x211) = 1;
            H(0x16) = func_80063654(0xF6063A25, D_800DACCD);
            func_80033590(0xF6063A25, p, 2, -1, 0);
            break;
        case 23:
            H(0xBA) = 200;
            B(0x211) = 1;
            H(0x16) = func_80063654(0x81010AB3, D_800DACCD);
            func_80033590(0x81010AB3, p, 2, -1, 0);
            break;
        case 1000:
            break;
    }
    if (D_800DE7A0 != 1) {
        switch (UH(0x3A)) {
            case 4:
            case 5:
            case 6:
            case 10:
            case 15:
            case 16:
                H(0x230) = 1;
                break;
        }
    } else {
        switch (UH(0x3A)) {
            case 5: D_800DE96C = p; break;
            case 4: D_800DE970 = p; break;
            case 6: D_800DE974 = p; break;
            case 15: D_800DE978 = p; break;
            case 10: D_800DE97C = p; break;
            case 16: D_800DE980 = p; break;
        }
    }
    {
        char *t = D_800DC5A0;
        func_8004B30C(p, t);
    }
    if (B(0x211) == 0) {
        func_80067308(p);
    }
    return p;
}
