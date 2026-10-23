#include "common.h"

#define I(o) (*(s32 *)((u8 *)p + (o)))
#define U(o) (*(u32 *)((u8 *)p + (o)))

extern char D_8001B8DC[];
extern char D_8001B8E8[];
extern char D_8001B8F4[];
extern char D_8001B900[];
extern char D_8001B90C[];
extern char D_8001B918[];
extern char D_8001B924[];
extern s32 D_800DE7A0;
extern void func_80045A70(void *);
extern void func_8004CACC();
extern void func_80046368(void *);
extern void func_800696B0(s32, void *, u32);
extern void func_8003A2E4(u32);
extern void func_8004C63C(void *, s32, s32, s32, s32);

void func_8004CC10(u8 *p) {
    s32 v;
    s32 n;
    s32 t;
    s32 c;
    char *s;

    I(0x32C)++;
    I(0x818) = 0;
    if (I(0x380) == 0) {
        v = I(0x420);
        if (v < 0) {
            v = -v;
        }
        if (v >= 0x5DD) {
            I(0x424)++;
        }
    }
    if (I(0x424) == 1 && I(0x830) == 2) {
        I(0x424) = 0;
    }
    func_80045A70(p + 0xA1C);
    I(0x380) = 0;
    I(0x37C) = 0;
    if (I(0x45C) == 0) {
        n = I(0x424);
        if (n != 0 && (I(0x830) != 2 || n >= 2)) {
            I(0x424) = 0;
            switch (n) {
                case 1: s = D_8001B8DC; func_8004CACC(p, 0x4A, s, -50, 0); break;
                case 2: s = D_8001B8E8; func_8004CACC(p, 0x4A, s, -100, 0); break;
                case 3: s = D_8001B8F4; func_8004CACC(p, 0x4A, s, -150, 0); break;
                case 4: s = D_8001B900; func_8004CACC(p, 0x4A, s, -200, 0); break;
                case 5: s = D_8001B90C; func_8004CACC(p, 0x4A, s, -250, 0); break;
                case 6: s = D_8001B918; func_8004CACC(p, 0x4A, s, -300, 0); break;
                case 7: s = D_8001B924; func_8004CACC(p, 0x4A, s, -350, 0); break;
            }
            I(0x45C) = 1;
        }
    }
    func_80046368(p);
    if (I(0x45C) != 0) {
        if (I(0x510) != 0 && I(0x514) != 0) {
            func_800696B0(I(0x510), p, U(0xB5C));
            I(0x510) = 0;
        }
        if (I(0x45C) != 0 && D_800DE7A0 == 7) {
            I(0x428) = 0;
        }
    }
    func_8003A2E4(U(0xB5C));
    t = U(0xB5C);
    if (I(0x45C) != 0) {
        c = I(0x34C);
        if (c == 0) {
            v = I(0x348); I(0x348) = v + t;
            if (I(0x348) >= 3000) {
                I(0x348) = 0;
                I(0x34C) = 750;
                func_8004C63C(p, 20, 20, 20, 5);
            }
        } else {
            I(0x34C) = c + (u32)t / 5;
            if (I(0x34C) > 750) {
                I(0x34C) = 750;
            }
        }
    }
    I(0x45C) = 0;
    I(0x460) = 0;
    I(0x424) = 0;
    I(0x420) = 0;
    I(0x858) = 0;
}
