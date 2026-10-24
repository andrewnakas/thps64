/* cflags: -frerun-cse-after-loop */
#include "common.h"

typedef struct {
    s16 a, b, c, d;
} Box8;

s32 func_80049034(u8 *, s32, s32);
extern Box8 D_8001FE54;
extern Box8 D_8001FE64;
extern Box8 D_8001FE6C;
extern u8 *D_800E9034;
extern s32 D_800E9070;
extern s32 D_800E9074;
extern s32 D_800E9078;

void func_8008E410(s32 arg0, s32 arg1) {
    Box8 r;
    Box8 r2;
    u8 *s;
    s32 *p;

    if (arg1 != 0) {
        r = D_8001FE54;
        r.b = 0x1FF;
        r.d = 1;
    }
    r = D_8001FE64;
    r2 = D_8001FE6C;
    D_800E9070 = 1;
    D_800E9078 = 0;
    s = D_800E9034;
    while (1) {
        if (*s == 0) {
            break;
        }
        if (func_80049034(s, arg0, -1) != 0) {
            while (*s != 0) {
                s++;
            }
            p = (s32 *)((s32)(s + 3) & ~3);
            while (*p != -1) {
                D_800E9078 += *p;
                p++;
            }
            break;
        }
        while (*s != 0) {
            s++;
        }
        p = (s32 *)((s32)(s + 3) & ~3);
        while (*p != -1) {
            p++;
        }
        s = (u8 *)(p + 1);
    }
    D_800E9074 = 0;
}
