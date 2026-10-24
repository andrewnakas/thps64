/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
#include "common.h"

#define F(o) (*(s32 *)((u8 *)arg0 + (o)))

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x154 - 0x10];
} E8004D398;

void *func_80022E54(void *, void *);
s32 func_800233B8(void *);
void func_80039E60(s32, s32, s32);
s32 func_80049D60(s32);
void func_8004A204(void *, s32, s32, s32, s32);
void func_8004BD2C(void *);
void func_8004C7CC(void *);
void func_8004CED0(void *);
void func_8004D048(void *, s32, s32);
void func_8004D2D4(void *);
void func_800B36D8(s32, f32, f32);
extern E8004D398 D_800D4D80[];
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern s32 D_800DE994;
extern s32 D_800DE9C4;
extern struct {
    u8 pad0[0x988];
    s32 unk988[1];
} D_800DE9F4;

void func_8004D398(u8 *arg0, s32 arg1) {
    s32 snd;
    s32 n;
    s32 k;

    F(0x294) = arg1;
    F(0x81C) = 0;
    F(0x310)++;
    func_8004CED0(arg0);
    F(0x814) = 0;
    F(0x450) = 1;
    F(0x83C) = 0;
    F(0x840) = 0;
    F(0x41C) = 0;
    F(0x468) = 0;
    F(0x464) = 0;
    F(0x498) = 0;
    F(0x470) = 0;
    if (D_800DE994 - F(0x36C) >= 9) {
        F(0x378) = 0;
        F(0x374) = 0;
        F(0x36C) = 0;
    }
    F(0x35C) = 0;
    F(0x358) = 0;
    F(0x368) = 0;
    F(0x364) = 0;
    F(0x454) = 0;
    F(0x7D8) = 0;
    func_8004D048(arg0, 1, 0x52F);
    func_8004C7CC(arg0);
    F(0x228) = 0x10000;
    func_8004D2D4(arg0);
    func_8004A204(arg0, 0x36, 0, 0x1D, -1);
    if (func_800233B8(func_80022E54(arg0 + 0x84, arg0 + 0x84)) << 6 > 0x2D000) {
        F(0x344) = 1;
    } else {
        F(0x344) = 6;
    }
    func_8004BD2C(arg0);
    k = D_800D4D80[F(0x3E0)].unkC;
    if (k == 0x9000 || k == 0xB000) {
        func_80039E60(8, 10000, 0);
        snd = 2;
    } else {
        if (func_80049D60(2) != 0) {
            snd = 9;
        } else {
            snd = 10;
        }
    }
    func_80039E60(snd, 10000, 0);
    F(0x7D4) = 0;
    n = F(0x968);
    if (D_800DE7A0 == 7) {
        n ^= D_800DE9C4;
    }
    if (D_800DE9F4.unk988[n] != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
        func_800B36D8(n, 0.7f, 0.45f);
    }
}
