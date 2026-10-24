/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8006F1A8(u8, s32, s32, s32);
void func_8006F274(s32);
void func_8006F23C(s32);
void func_8006F178(s32, s32, char *, s32, s32, s32);
extern u8 *D_800D61A8;
extern s32 D_800D60DC;
extern s32 D_800D60E0;
extern s32 D_800D60E4;
extern s32 D_800D60E8;
extern u32 D_800D613C;
extern char D_8001B1AC[];
extern char D_8001B1B0[];
extern char D_8001B1B4[];
extern char D_8001B1B8[];
extern char D_8001B1BC[];

void func_80044150(void) {
    u8 *p;

    if (*(s32 *)(D_800D61A8 + 0x1C) != 0) {
        return;
    }
    if (D_800D60E4 != 0) {
        p = D_800D61A8;
        if (D_800D60E8 >= 0x1E3 && D_800D60E4 >= 0xB) {
            D_800D60E8 -= 4;
        }
        if (D_800D60E4 < 10) {
            D_800D60E8 = 0x20A - D_800D60E4 * 4;
        }
        D_800D60E4--;
        func_8006F1A8((D_800D613C % 20) * 12, 100, 100, 0);
        func_8006F274(1);
        func_8006F23C(0xFF);
        if (*(s32 *)(p + 0xEE4) != 0) {
            func_8006F178(D_800D60E8, 0x50, D_8001B1AC, 0, 0, 0x100);
        }
        if (*(s32 *)(p + 0xEE8) != 0) {
            func_8006F178(D_800D60E8, 0x69, D_8001B1B0, 0, 0, 0x100);
        }
        if (*(s32 *)(p + 0xEEC) != 0) {
            func_8006F178(D_800D60E8, 0x82, D_8001B1B4, 0, 0, 0x100);
        }
        if (*(s32 *)(p + 0xEF0) != 0) {
            func_8006F178(D_800D60E8, 0x9B, D_8001B1B8, 0, 0, 0x100);
        }
        if (*(s32 *)(p + 0xEF4) != 0) {
            func_8006F178(D_800D60E8, 0xB4, D_8001B1BC, 0, 0, 0x100);
        }
    }
    if (D_800D60DC != 0) {
        if (D_800D60E0 >= 0x1E2 && D_800D60DC >= 0xB) {
            D_800D60E0 -= 4;
        }
        if (D_800D60DC < 0xB) {
            D_800D60E0 = 0x1FF - D_800D60DC * 4;
        }
        D_800D60DC--;
    }
}
