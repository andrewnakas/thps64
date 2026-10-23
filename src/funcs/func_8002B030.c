#include "common.h"

s32 func_800A050C(void *, s32);
void func_800A0DBC(void *, s32);
void func_800A1EA4(void *, s32, char *, char *, void *, void *, s32, s32, u8 *, s32);
void func_800A3750(void *, char *, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern char D_80019310[];
extern char D_80019334[];
extern char D_80019354[];
extern char D_80019358[];
extern u8 D_800D0FC0[];
extern u8 D_800D0FC2;
extern u8 *D_800D3128;
extern u8 D_800D3130[];
extern s32 D_800D3148;
extern s32 D_800EA550;

void func_8002B030(u8 *arg0) {
    char *s;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x30, 34.0f, 0.0f, 0.925f, 2.0f);
    if (D_800EA550 == 0) {
        if (*(s32 *)(arg0 + 0x44) == 0 && D_800D3148 == 1) {
            *(s32 *)(arg0 + 0x4C) = 0;
        } else {
            u8 *a = D_800D3130;
            u8 *b = D_800D0FC0;
            if (func_800A050C(a, b[2]) != 0) {
                if (*D_800D3128 == 0x72) {
                    s = D_80019310;
                } else {
                    s = D_80019334;
                }
                {
                    void *buf;
                    void *fmt;
                    s32 id;
                    buf = D_800D3130;
                    id = D_800D0FC2;
                    fmt = D_80019354;
                    func_800A1EA4(buf, id, fmt, s, arg0 + 0x50, arg0 + 0x54, 1, 0, D_800D3128, 0);
                }
                *(s32 *)(arg0 + 0x4C) = 0;
            } else {
                char *str;
                u8 val;
                str = D_80019358;
                val = b[2];
                func_800A3750(a, str, val, 4, 0, 0, 0);
            }
            *(s32 *)(arg0 + 0x44) = 0;
        }
    }
    func_800A0DBC(D_800D3130, 1);
    func_800BE5A4();
}
