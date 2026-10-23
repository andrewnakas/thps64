#include "common.h"

void func_80005720(void *, s32, s32);
u32 func_8000574C(char *);
void func_8002B030(void);
void func_8002C0C0(char *);
void func_80065FA8(void);
extern u16 D_800D0FD8;
extern s32 D_800D3120;
extern s32 D_800D3124;
extern char D_800D3130[];
extern void *D_800DC61C;
extern u8 D_800DE9F4[];
extern s32 D_800EA550;

s32 func_8002B1A4(s32 *arg0) {
    s32 r;
    char *s;
    s32 a;
    char *base;

    r = 0;
    func_8002B030();
    if (D_800EA550 == 0 && arg0[0x4C / 4] == 0) {
        a = arg0[0x50 / 4];
        if (a != 0) {
            if (D_800D0FD8 == 3) {
                func_80005720(D_800DC61C, a, 0x6000);
            } else {
                func_80005720(D_800DE9F4, a, 0xA10);
            }
            base = D_800D3130;
            s = base + 0x4A0;
            if (func_8000574C(s) >= 4) {
                s = base + 0x4A3;
            }
            func_8002C0C0(s);
            func_80065FA8();
            r = D_800D3124;
        } else {
            r = D_800D3120;
        }
    }
    return r;
}
