/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x28];
    s32 x3C;
    s32 x40;
    u8 pad44[0x34];
} Ent5C1C;

typedef struct {
    u8 pad0[8];
    u8 f8;
    u8 pad9[0xB];
} Ent14_40EAC;

void func_800057E4(char *, char *, s32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
extern char D_8001A498[];
extern char D_8001A4A8[];
extern char D_8001A4B8[];
extern char D_8001A4CC[];
extern char D_8001A4DC[];
extern char D_8001A4EC[];
extern char D_8001A4F8[];
extern s32 D_800C0E20;
extern u8 D_800D0FD4;
extern Ent5C1C D_800D5C1C[];
extern s32 D_800DE7A0;
extern Ent14_40EAC D_800DE9F4[];

void func_80040EAC(u8 *arg0) {
    char buf[32];
    s32 n;
    f32 x;
    Ent5C1C *tbl;
    Ent5C1C *e;

    if (D_800DE7A0 == 1) {
        tbl = D_800D5C1C;
        e = &tbl[D_800C0E20];
        if (e->x10 != 0) {
            if ((u32)(D_800C0E20 - 1) < 3 || D_800C0E20 == 5 || D_800C0E20 == 6 || D_800C0E20 == 8) {
                n = D_800D5C1C[D_800C0E20].x3C - D_800DE9F4[D_800D0FD4].f8;
                if (n >= 2) {
                    func_800057E4(buf, D_8001A498, n);
                } else {
                    func_800057E4(buf, D_8001A4A8, n);
                }
                arg0 += 0x3BC;
                x = 380.0f;
                func_800A8678(arg0, buf, x, 300.0f, 2, 0, 3.0f, 0xAA, 0x14, 1, 0, 0, 0, 0);
                func_800A8678(arg0, D_8001A4B8, x, 280.0f, 2, 0, 3.0f, 0xAA, 0x14, 1, 0, 0, 0, 0);
            } else if (D_800C0E20 == 4 || D_800C0E20 == 7) {
                n = e->x40 - arg0[0x2B6];
                if (D_800C0E20 != 4) {
                    if (n >= 2) {
                        func_800057E4(buf, D_8001A4CC, n);
                    } else {
                        func_800057E4(buf, D_8001A4DC, n);
                    }
                } else {
                    func_800057E4(buf, D_8001A4EC, n);
                }
                arg0 += 0x3BC;
                x = 380.0f;
                func_800A8678(arg0, buf, x, 300.0f, 2, 0, 3.0f, 0xAA, 0x14, 1, 0, 0, 0, 0);
                func_800A8678(arg0, D_8001A4B8, x, 280.0f, 2, 0, 3.0f, 0xAA, 0x14, 1, 0, 0, 0, 0);
            }
        }
    } else if (D_800D5C1C[D_800C0E20].x10 != 0 && D_800C0E20 != 0) {
        func_800A8678(arg0 + 0x3BC, D_8001A4F8, 370.0f, 280.0f, 2, 0, 3.0f, 0xAA, 0x14, 1, 0, 0, 0, 0);
    }
}
