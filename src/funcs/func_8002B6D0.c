/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_800B4264(s32, s32);
void func_80039E60(s32, s32, s32);
void func_800A7B28(void *, s32, s32, s32, s32);
void func_800A85C8(void *, f32, f32, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800BFC3C(s32, s32, s32, s32);
void func_800BEB0C(s32, s32, s32, s32, s32, s32, s32);
void func_800A773C(void *, f32, f32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_8002BF6C(u8 *);
s32 func_8002BD0C(u8 *);

typedef struct {
    char c[14];
} Name8002B6D0;

extern char D_80019440[];
extern u8 D_800D3630;
extern u8 D_800D3631;
extern u8 D_800D3632;
extern u8 D_800D3633;
extern u8 D_800D3634;
extern u8 D_800D3635;
extern f32 D_800D3638;
extern f32 D_800D363C;
extern f32 D_800D3640;
extern s32 D_800D3644;
extern s32 D_800D3648;
extern s32 D_800D364C;
extern s32 D_800D3650;
extern s32 D_800D3654;
extern s32 D_800D3658;
extern s32 D_800D365C;
extern s32 D_800D3660;
extern s32 D_800D3664;
extern u8 D_800D3668[];
extern s32 D_800F3294;
extern f32 D_800F5668;

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))

void func_8002B6D0(u8 *arg0) {
    char buf[2];
    s32 d;
    u8 c;
    s32 x;
    s32 i;
    s32 sel;
    s32 snd;
    f32 t;

    if (S32(arg0, 0x240) != 0) {
        return;
    }
    d = 0;
    if (func_800B4264(S32(arg0, 0x248), 0x200)) {
        d = -1;
    } else if (func_800B4264(S32(arg0, 0x248), 0x100)) {
        d = 1;
    }
    if (d != 0) {
        func_80039E60(0x11, 10000, 0);
        F32(arg0, 0x250) = D_800D3638;
        {
            s32 t = d + 13;

            S32(arg0, 0x24C) = (S32(arg0, 0x24C) + t) % 13;
        }
    }
    d = 0;
    if (func_800B4264(S32(arg0, 0x248), 0x400)) {
        d = -1;
    } else if (func_800B4264(S32(arg0, 0x248), 0x800)) {
        d = 1;
    }
    if (d != 0) {
        func_80039E60(0x90, 10000, 0);
        F32(arg0, 0x250) = D_800D3638;
        c = D_800D3668[S32(arg0, 0x24C)];
        if (c >= 'a' && c <= 'z') {
            if (d == 1) {
                if (c == 'z') {
                    c = '0';
                } else {
                    c++;
                }
            } else {
                if (c == 'a') {
                    c = ' ';
                } else {
                    c--;
                }
            }
        } else if ((u8)(c - '0') < 10) {
            if (d == 1) {
                if (c == '9') {
                    c = ' ';
                } else {
                    c++;
                }
            } else {
                if (c == '0') {
                    c = 'z';
                } else {
                    c--;
                }
            }
        } else if (d == 1) {
            c = 'a';
        } else {
            c = '9';
        }
        D_800D3668[S32(arg0, 0x24C)] = c;
    }
    func_800A7B28(arg0, D_800D3630, D_800D3631, D_800D3632, 0xFF);
    func_800A85C8(arg0, 0.800000012f, 0.899999976f, D_80019440, D_800F3294 / 2, D_800D3644, 2, 2, 1.0f, 0xFF, 0, 1, 1, 0, 0, 0);
    x = D_800D364C << 1;
    x += D_800D364C;
    x <<= 2;
    x = D_800F3294 - x;
    x += (u32)x >> 31;
    x >>= 1;
    func_800BFC3C(x - D_800D3650, D_800F3294 - x + D_800D3650, D_800D3658, D_800D3654);
    buf[1] = 0;
    i = 0;
    while (1) {
        if (i >= 13) {
            break;
        }
        buf[0] = D_800D3668[i];
        func_800BEB0C(x - D_800D365C + 2, x + D_800D365C + 1, D_800D3664 - 1, D_800D3664 + D_800D3660 - 1, 0, 0, 0);
        sel = 0;
        if (i == S32(arg0, 0x24C)) {
            func_800A7B28(arg0, D_800D3633, D_800D3634, D_800D3635, 0xFF);
            if (F32(arg0, 0x250) != 0.0f) {
                t = D_800D3640 + F32(arg0, 0x250) / D_800D3638 * (D_800D363C - 1.0f);
                func_800A773C(arg0, t * 0.899999976f, t);
                sel = 1;
            }
            func_800BEB0C(x - D_800D365C + 1, x + D_800D365C, D_800D3664, D_800D3664 + D_800D3660, D_800D3633, D_800D3634, D_800D3635);
        } else {
            func_800A7B28(arg0, D_800D3630, D_800D3631, D_800D3632, 0xFF);
            func_800BEB0C(x - D_800D365C + 1, x + D_800D365C, D_800D3664, D_800D3664 + D_800D3660, D_800D3630, D_800D3631, D_800D3632);
        }
        func_800A8678(arg0, buf, x, D_800D3648, 2, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
        if (sel) {
            func_800A773C(arg0, D_800D3640 * 0.899999976f, D_800D3640);
        }
        x += D_800D364C;
        i++;
    }
    if (F32(arg0, 0x250) != 0.0f) {
        F32(arg0, 0x250) -= D_800F5668;
        if (F32(arg0, 0x250) < 0.0f) {
            F32(arg0, 0x250) = 0.0f;
        }
    }
    if (func_800B4264(S32(arg0, 0x248), 0x8000)) {
        func_8002BF6C(arg0);
        if (func_8002BD0C(arg0)) {
            S32(arg0, 0x244) = 0;
            D_800D3668[0] = 0;
            snd = 0xA2;
        } else {
            S32(arg0, 0x244) = D_800D3668[0] != 0;
            snd = S32(arg0, 0x244) ? 0x91 : 0x93;
        }
        func_80039E60(snd, 10000, 0);
    } else if (func_800B4264(S32(arg0, 0x248), 0x4000)) {
        func_8002BF6C(arg0);
        *(Name8002B6D0 *)D_800D3668 = *(Name8002B6D0 *)(arg0 + 0x254);
        func_80039E60(0x93, 10000, 0);
    }
}
