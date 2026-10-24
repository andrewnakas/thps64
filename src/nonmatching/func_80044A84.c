/* cflags: -fexpensive-optimizations -fcse-skip-blocks */
/* NON_MATCHING: jump.c range swap reorders the EC block; best 196/202. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* Z1: the game's layout is exactly the natural one of `if (EC == 0) { if (sec == F0) goto skip; EC = 10; } else {
 * draw; EC--; goto set; } call; set: F0 = sec;` but jump.c's "if (foo) bar; else break;" swap (all its conditions
 * hold there) moves the else first (194/202). A play flag with a second test is never threaded (flag stays in s3,
 * 183). Unsolved: what blocked that swap in the game. */
/* NEAR-MISS func_80044A84 196/202 paired (-fexpensive-optimizations -fcse-skip-blocks): u16 args fix s-reg order; only the D_800D60EC block layout differs (game: x==0 path first, then-part jumps over the draw/decrement block to the func_80039E60 call placed after it). */
#include "common.h"

void func_800057E4(char *, char *, s32, s32);
void func_80039E60(s32, s32, s32);
void func_8006EB3C(s32);
void func_8006F178(s32, s32, char *, s32, s32, s32);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);
extern char D_8001B1DC[];
extern s32 D_800D60EC;
extern s32 D_800D60F0;
extern u32 D_800D613C;
extern u8 *D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern u8 *D_800DE7A8;
extern s32 D_800DE994;
extern s32 D_800DE9AC;
extern s32 D_800DE9B8;
extern s32 D_800DE9BC;
extern s32 D_800FA900;

void func_80044A84(u8 *arg0, u16 arg1, u16 arg2) {
    char buf[8];
    s32 *p;
    s32 t;
    s32 min;
    s32 sec;
    s32 d;
    s32 x;

    if (*(s32 *)(*(u8 **)(D_800DE7A8 + 0x2D0) + 0x5B0) != 0x17) {
    if (D_800DE7A0 != 2 && (D_800DE7A0 != 7 || *(s32 *)(arg0 + 0x428) != 0) && D_800DE9AC != 1) {
        func_8006EB3C(D_800DE9BC);
        if (arg0 == D_800D61A8) {
            p = &D_800DC618;
        } else {
            p = &D_800DC6D8;
        }
        if (*p != 2) {
            t = *(s32 *)(arg0 + 0x428) - D_800DE994;
            min = t / 3600;
            sec = (t - min * 3600) / 60;
            if (t < 0) {
                min = sec = 0;
            }
            func_800057E4(buf, D_8001B1DC, min, sec);
            func_8006F1A8(0x80, 0, 0, 0);
            func_8006F274(0);
            func_8006F23C(0x100);
            if (D_800DE7A0 == 7) {
                if (min != 0 || sec >= 4 || D_800D613C % 30 >= 15) {
                    func_8006F178(arg1 & 0xFFFF, arg2 & 0xFFFF, buf, 0, 0, 0x100);
                }
            } else {
                if (min == 0 && sec < 11) {
                    if (D_800D60EC == 0) {
                        if (sec == D_800D60F0) {
                            goto skip;
                        }
                        D_800D60EC = 10;
                        func_80039E60(0x16, 10000, 0);
                    } else {
                        func_8006F178(arg1 & 0xFFFF, arg2 & 0xFFFF, buf, 0, 0, 0x100);
                        D_800D60EC--;
                    }
                    D_800D60F0 = sec;
                skip:;
                } else {
                    func_8006F178(arg1 & 0xFFFF, arg2 & 0xFFFF, buf, 0, 0, 0x100);
                }
                if (arg0 == D_800DE7A8) {
                    if ((u32)(t - 1) < 599) {
                        x = D_800FA900;
                        if (t < x) {
                            d = x / 10;
                            if (d < 10) {
                                d = 10;
                            }
                            D_800FA900 = x - d;
                        }
                    } else {
                        D_800FA900 = 600;
                    }
                }
            }
        }
    }
    func_8006EB3C(D_800DE9B8);
    }
}
