/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u32 unkC;
    u8 pad10[0xC];
    s32 unk1C;
    u8 pad20[0x1E];
    s16 unk3E[5];
    u8 unk48;
    u8 unk49;
    u8 pad4A[0x64];
    u8 unkAE;
} S86C;

extern S86C D_800DE640;
extern char D_8001E6B4[];
extern char D_8001E6C4[];
extern char D_8001E6D4[];
extern char D_8001E6E8[];
extern char D_8001E6F4[];
extern char D_8001E6A8[];
extern s32 D_800DDE04;
void func_8006EEF0(void);
void func_8006F23C(s32);
void func_8006F274(s32);
void func_8006F1A8(s32, s32, s32, s32);
void func_800057E4(char *, char *, ...);
void func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
void func_80039E60(s32, s32, s32);
void func_80095870(s32);

void func_8007F86C(void) {
    u8 c;
    S86C *s;
    char buf[0x10];
    s32 i;
    s32 j;
    s32 pct;
    s32 sum;

    s = &D_800DE640;
    func_8006EEF0();
    func_8006F23C(0x100);
    func_8006F274(0);
    func_8006F1A8(0xB6, 0x84, 0x24, 0);
    func_800057E4(buf, D_8001E6B4, s->unkAE + 1);
    func_8006DF40(0x100, 0x28, buf, 0, 0, 0x100, 0);
    func_8006DF40(0x100, 0x46, D_8001E6C4, 0, 0, 0x100, 0);
    func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
    func_8006F274(1);
    pct = 0;
    if (s->unkC >= 0x4C) {
        pct = (s->unkC - 0x4B) * 4;
    }
    if (pct > 100) {
        pct = 100;
    }
    i = 0;
    c = 0x7A - pct;
    for (; i < 5; i++) {
        if (s->unkC == i * 15 + 1) {
            func_80039E60(0x34, 0x2710, 0);
        }
        if (i * 15 < s->unkC) {
            func_800057E4(buf, D_8001E6D4, i + 1, (s16)(s->unk3E[i] / 10), (s16)(s->unk3E[i] % 10));
        } else {
            func_800057E4(buf, D_8001E6E8, i + 1);
        }
        if (i == s->unk49 || i == s->unk48) {
            func_8006F1A8(c, c, c, 0);
        } else {
            func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        }
        func_8006DF40(0x96, i * 20 + 0x5A, buf, 0, 0, 0x100, 0);
    }
    if (pct >= 100) {
        if (s->unk1C == 0) {
            func_80039E60(0x33, 0x2710, 0);
        }
        func_8006F274(0);
        func_8006F1A8(0xB6, 0x84, 0x24, 0);
        sum = 0;
        for (j = 0; j < 5; j++) {
            if (j != s->unk49 && j != s->unk48) {
                sum += s->unk3E[j];
            }
        }
        sum /= 3;
        func_8006F274(0);
        func_800057E4(buf, D_8001E6F4, s->unkAE + 1);
        func_8006DF40(0xC8, 0xC3, buf, 0, 0, 0x100, 0);
        func_800057E4(buf, D_8001E6A8, sum / 10, sum % 10);
        func_8006F23C(0x180);
        func_8006DF40(0x14F, 0xC3, buf, 0, 0, 0x100, 0);
        s->unk1C = 1;
    } else {
        s->unk1C = 0;
    }
    func_8006F23C(0x100);
    func_80095870(D_800DDE04);
}
