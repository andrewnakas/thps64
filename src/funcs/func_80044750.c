#include "common.h"

void func_800057E4(char *, char *, s32);
void func_800461F0(void *);
void func_8006DEB0(void *, s32);
void func_8006EB3C(s32);
void func_8006F178(s32, s32, char *, s32, s32, s32);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);
extern char D_8001B1C8[];
extern char D_8001B1CC[];
extern char D_8001B1D4[];
extern u32 D_800D6100;
extern s32 D_800DC618;
extern s32 D_800DE7A0;
extern u8 *D_800DE7A8;
extern s32 D_800DE9B8;
extern s32 D_800DF3EC;

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_80044750(u8 *arg0, s32 arg1, s32 arg2) {
    char buf1[16];
    char buf2[16];
    s32 show;
    u32 total;
    s32 n;
    s32 i;
    u8 *p;
    s32 sz;
    s32 t;
    s32 r;
    s32 b;
    s32 g;
    u32 v;
    char *fmt;
    s32 lvl;
    s32 cnt;
    s32 m;

    func_8006EB3C(D_800DE9B8);
    show = D_800DC618 != 2;
    total = 0;
    n = total;
    if (D_800DF3EC == 0) {
        return;
    }
    cnt = S32(arg0, 0xDA4);
    if (cnt > 0) {
        lvl = S32(arg0, 0x424);
        cnt <<= 1;
        if (lvl < 3) {
            t = cnt + lvl;
        } else {
            cnt -= 2;
            t = cnt + lvl * 2;
        }
        n = t;
        if (S32(arg0, 0x82C) == 2 && S32(arg0, 0x424) == 1) {
            n--;
        }
        m = S32(arg0, 0xDA4);
        cnt = 0;
        if (m > 0) {
            p = arg0;
            do {
                total += S32(p, 0xC18);
                p += 0x14;
                cnt++;
            } while (cnt < m);
        }
    }
    if (S32(arg0, 0xB5C) != 0) {
        total = S32(arg0, 0xB5C);
    }
    if (total != 0 || S32(arg0, 0xB68) == 5) {
        fmt = D_8001B1C8;
        v = total;
        if (S32(arg0, 0xB68) == 5) {
            v = D_800D6100;
        }
        func_800057E4(buf1, fmt, v);
        func_8006F1A8(0x80, 0x80, 0x80, 0);
        if (D_800DE7A0 == 8) {
            if (arg0 == D_800DE7A8) {
                r = 0x50;
                g = r;
                b = 0x80;
            } else {
                r = 0x80;
                g = 0x50;
                b = g;
            }
            func_8006F1A8(r, g, b, 0);
        }
        if (n >= 3) {
            func_8006F274(2);
        } else {
            func_8006F274(0);
        }
        sz = 0x100;
        func_8006F23C(sz);
        if (show) {
            func_8006DEB0(arg0 + 0xB80, S32(arg0, 0xB68) == 5);
            func_8006F178(arg1 & 0xFFFF, arg2 & 0xFFFF, buf1, 0, 0, sz);
            func_8006DEB0(arg0 + 0xB80, 0);
        }
        if (S32(arg0, 0xF10) > 0) {
            S32(arg0, 0xF10)--;
        }
        if (n >= 3) {
            if (n & 1) {
                fmt = D_8001B1CC;
                func_800057E4(buf2, fmt, n >> 1);
            } else {
                fmt = D_8001B1D4;
                func_800057E4(buf2, fmt, n >> 1);
            }
            func_8006F1A8(0x80, 0x80, 0x80, 0);
            if (D_800DE7A0 == 8) {
                if (arg0 == D_800DE7A8) {
                    r = 0x50;
                    g = r;
                    b = 0x80;
                } else {
                    r = 0x80;
                    g = 0x50;
                    b = g;
                }
                func_8006F1A8(r, g, b, 0);
            }
            func_8006F274(1);
            func_8006F23C(sz);
            if (show) {
                func_8006F178(arg1 & 0xFFFF, arg2 & 0xFFFF, buf2, 0, 0, 0x100);
            }
        }
        if (total != 0) {
            D_800D6100 = (total * n) >> 1;
        }
    }
    if (S32(arg0, 0xDA4) != 0) {
        if (S32(arg0, 0x424) > S32(arg0, 0xED4) && (S32(arg0, 0x82C) != 2 || S32(arg0, 0x424) >= 2)) {
            func_800461F0(arg0 + 0xA1C);
            S32(arg0, 0xED4) = S32(arg0, 0x424);
        }
    }
}
