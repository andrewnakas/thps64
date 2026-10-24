/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[3];
    u8 flags[8];
} Ent14_411EC;


void func_800057E4(char *, char *, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
extern char D_8001A528[];
extern char D_8001A52C[];
extern s32 D_800C0E20;
extern u8 D_800D0FC0[];
extern u8 D_800D0FD4;
extern s32 D_800DE7A0;
typedef struct {
    char name[8];
    s32 val;
} Item411EC;

typedef struct {
    Ent14_411EC e[11];
    u8 padDC[8];
    Item411EC items[1][8];
} G411EC;

extern G411EC D_800DE9F4;

void func_800411EC(u8 *arg0) {
    char buf[16];
    s32 n;
    s32 i;
    s32 step;
    s16 y;
    u8 f;

    if (D_800DE7A0 == 1) {
        n = D_800DE9F4.e[D_800D0FD4].b8;
        if (n >= 10) {
            func_800057E4(buf, D_8001A528, n);
        } else {
            func_800057E4(buf, D_8001A52C, n);
        }
        func_800B1AC4(arg0 + 0x83C, 387.0f, 284.0f, 0.922f, 1.0f);
        func_800A8678(arg0 + 0x5FC, buf, 492.0f, 125.0f, 2, 0, 1.0f, 0, 0, 1, 0, 0, 0, 0);
        step = 3;
        y = 304;
        for (i = 3; i < 9; i += step--) {
            f = D_800DE9F4.e[D_800D0FC0[0x14]].flags[i];
            if (f & 0x80) {
                if (f & 0x40) {
                    goto b;
                }
                if (!(f & 0x20)) {
                    func_800B1AC4(arg0 + 0x850, 570.0f, y, 1.0f, 1.0f);
                    goto next;
                }
            }
            f = D_800DE9F4.e[D_800D0FC0[0x14]].flags[i];
            if (f & 0x40) {
            b:
                if (!(D_800DE9F4.e[D_800D0FC0[0x14]].flags[i] & 0x20)) {
                    func_800B1AC4(arg0 + 0x864, 570.0f, y, 1.0f, 1.0f);
                    goto next;
                }
                goto c;
            }
            if (f & 0x20) {
            c:
                func_800B1AC4(arg0 + 0x878, 570.0f, y, 1.0f, 1.0f);
            }
        next:
            y += 25;
        }
    } else if (D_800DE7A0 == 3) {
        s16 y2;
        s32 i2;
        func_800B1AC4(arg0 + 0x83C, 387.0f, 284.0f, 0.922f, 1.0f);
        y2 = 158;
        for (i2 = 0; i2 < 3; i2++) {
            func_800A8678(arg0 + 0x5FC, D_800DE9F4.items[D_800C0E20][i2].name, 418.0f, y2, 0, 0, 1.0f, 0, 0, 1, 1, 0, 0, 0);
            func_800057E4(buf, D_8001A528, D_800DE9F4.items[D_800C0E20][i2].val);
            func_800A8678(arg0 + 0x5FC, buf, 580.0f, y2, 1, 0, 1.0f, 0, 0, 1, 1, 0, 0, 0);
            y2 -= 20;
        }
    }
}
