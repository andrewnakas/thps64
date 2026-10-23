#include "common.h"

extern u8 *D_800D61A8;
extern s32 D_800E9038;
extern s32 D_800DE820;
extern s32 D_800DE9A8;
extern u8 *D_800DE7A8;
extern u8 *D_800DE7AC;
extern s32 D_800D60E4;
extern s32 D_800D60DC;
extern s32 D_800DE93C;
extern void func_80044F78(void);
extern void func_8006EC5C(void *);
extern void func_80044DAC(void *, s32, s32);
extern void func_80044150(void);
extern void func_80044750(void *, s32, s32);
extern void func_80045030(void *, void *, s32, s32);
extern void func_8004438C(void *, s32, s32);
extern void func_80044A84(void *, s32, s32);
extern void func_8006EC48(void *, s32);

#define W(q, o) (*(s32 *)((q) + (o)))

void func_800453F0(void) {
    u8 *s = D_800D61A8;

    func_80044F78();
    while (s != NULL) {
        func_8006EC5C(s + 0xB80);
        func_80044DAC(s, 0x100, 0x5A);
        func_80044150();
        if (D_800E9038 != 0) {
            D_800D60E4 = 30;
            D_800D60DC = 30;
            return;
        }
        if (D_800DE820 != 0) {
            if (D_800DE9A8 == 1 && W(D_800DE7A8, 0xB5C) == 0) {
                D_800D60E4 = 30;
                D_800D60DC = 30;
                return;
            }
            if (D_800DE9A8 == 2 && W(D_800DE7A8, 0xB5C) == 0 && D_800DE7AC != NULL && W(D_800DE7AC, 0xB5C) == 0) {
                D_800D60E4 = 30;
                D_800D60DC = 30;
                return;
            }
        }
        switch (D_800DE93C * 2 + *(u16 *)(s + 0xA24)) {
            case 0:
            case 1:
                func_80044750(s, 0x100, 0xE0);
                func_80045030(s + 0xA1C, s, 0x100, 0xCD);
                func_8004438C(s, 0x23, 0x2D);
                func_80044A84(s, 0xFA, 0x30);
                func_8006EC48(s + 0xB80, 0xF0);
                func_8006EC48(s + 0xBCC, 0xF0);
                break;
            case 2:
                func_80044750(s, 0x180, 0xE0);
                func_80045030(s + 0xA1C, s, 0x180, 0xCD);
                func_8004438C(s, 0x143, 0x2D);
                func_8006EC48(s + 0xB80, 0xF0);
                func_8006EC48(s + 0xBCC, 0xF0);
                break;
            case 4:
                func_80045030(s + 0xA1C, s, 0x100, 0xCD);
                func_80044750(s, 0x100, 0xE0);
                func_8004438C(s, 0x23, 0x9B);
                func_80044A84(s, 0x1C4, 0xA0);
                func_8006EC48(s + 0xB80, 0xF0);
                func_8006EC48(s + 0xBCC, 0xF0);
                break;
            case 6:
                func_80044750(s, 0x80, 0xE0);
                func_80045030(s + 0xA1C, s, 0x80, 0xCD);
                func_8004438C(s, 0x70, 0x96);
                func_80044A84(s, 0x37, 0x9B);
                func_8006EC48(s + 0xB80, 0xF0);
                func_8006EC48(s + 0xBCC, 0xF0);
                break;
            case 8:
                func_80044750(s, 0x100, 0xE0);
                func_80045030(s + 0xA1C, s, 0x100, 0xCD);
                func_8004438C(s, 0x46, 0xAF);
                func_80044A84(s, 0x85, 0xD9);
                func_8006EC48(s + 0xB80, 0xF0);
                func_8006EC48(s + 0xBCC, 0xF0);
                break;
            case 3:
                func_80044750(s, 0x80, 0xE0);
                func_80045030(s + 0xA1C, s, 0x80, 0xCD);
                func_8004438C(s, 0x23, 0x2D);
                func_80044A84(s, 0xFA, 0x30);
                func_8006EC48(s + 0xB80, 0xF0);
                func_8006EC48(s + 0xBCC, 0xF0);
                break;
            case 5:
                func_80045030(s + 0xA1C, s, 0x100, 0x55);
                func_80044750(s, 0x100, 0x68);
                func_8004438C(s, 0x23, 0x2D);
                func_80044A84(s, 0x1BF, 0x32);
                func_8006EC48(s + 0xB80, 0x76);
                func_8006EC48(s + 0xBCC, 0x76);
                break;
            case 7:
                func_80044750(s, 0x180, 0x68);
                func_80045030(s + 0xA1C, s, 0x180, 0x55);
                func_8004438C(s, 0x116, 0x28);
                func_80044A84(s, 0x1C9, 0x2A);
                func_8006EC48(s + 0xB80, 0x7A);
                func_8006EC48(s + 0xBCC, 0x7A);
                break;
            case 9:
                func_80044750(s, 0x100, 0x9A);
                func_80045030(s + 0xA1C, s, 0x100, 0x82);
                func_8004438C(s, 0x13B, 0x2B);
                func_80044A84(s, 0x173, 0x55);
                func_8006EC48(s + 0xB80, 0x98);
                func_8006EC48(s + 0xBCC, 0x98);
                break;
        }
        s = *(u8 **)(s + 0x1C);
    }
}
