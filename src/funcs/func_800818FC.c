/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
} VtE18FC;

typedef struct {
    u8 pad0[0x18];
    VtE18FC e;
} Vt18FC;

typedef struct {
    u8 pad0[0x48];
    Vt18FC *vt;
    u8 pad4C[0x214 - 0x4C];
    s32 unk214;
} W18FC;

typedef struct {
    u8 pad0[0xB4];
    W18FC *unkB4;
    W18FC *unkB8;
    W18FC *unkBC;
    u8 padC0[0x118 - 0xC0];
    s32 unk118;
} S640;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} E78_18FC;

typedef struct {
    u8 pad0[0x2C];
    char *unk2C;
    u8 pad30[0x154 - 0x30];
} E154_18FC;

typedef struct {
    u8 pad0[0x14];
    u8 unk14;
} S0FC0_18FC;

typedef struct {
    u8 pad0[0x3E0];
    s32 unk3E0;
} SE7A8_18FC;

void func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
void func_8006EEF0(void);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);
W18FC *func_80082010(s32, s32, s32, s32, f32, s32);
void func_80095870(s32);
extern char D_8001E424[];
extern char D_8001E4E0[];
extern char D_8001E4F8[];
extern char D_8001E518[];
extern char D_8001E53C[];
extern char D_8001E55C[];
extern char D_8001E568[];
extern char D_8001E588[];
extern char D_8001E5A0[];
extern char D_8001E5B4[];
extern S0FC0_18FC D_800D0FC0;
extern E154_18FC D_800D4D80[];
extern E78_18FC D_800D5C1C[];
extern s32 D_800DDE04;
extern S640 D_800DE640;
extern SE7A8_18FC *D_800DE7A8;
extern u8 D_800DE9F4[];

void func_800818FC(void) {
    s32 kinds[3];
    S640 *ui;
    s32 count;
    s32 i;
    s32 j;
    s32 ok;
    s32 n;
    u8 f;

    ui = &D_800DE640;
    func_8006EEF0();
    func_8006F23C(0x100);
    func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
    func_8006F274(0);
    count = 0;
    for (j = 0; j < 10; j++) {
        if (D_800D5C1C[j].unkC != 0 && (D_800DE9F4[j + D_800DE7A8->unk3E0 * 20 + 0xC] & 0x20)) {
            count++;
        }
    }
    if ((count ^ 3) == 0) {
        func_8006DF40(0x100, 0x28, D_8001E4E0, 0, 0, 0x100, 0);
        func_8006DF40(0x100, 0x3C, D_8001E4F8, 0, 0, 0x100, 0);
        func_8006DF40(0x100, 0x50, D_8001E424, 0, 0, 0x100, 0);
        if (D_800D0FC0.unk14 < 10) {
            func_8006DF40(0x100, 0xB4, D_8001E518, 0, 0, 0x100, 0);
            func_8006DF40(0x100, 0xC8, D_800D4D80[D_800D0FC0.unk14].unk2C, 0, 0, 0x100, 0);
        } else {
            func_8006DF40(0x100, 0xB4, D_8001E53C, 0, 0, 0x100, 0);
            func_8006DF40(0x100, 0xC8, D_8001E55C, 0, 0, 0x100, 0);
        }
        if (ui->unkB4 == NULL) {
            ui->unkB4 = func_80082010(5, 0x6E, 0x73, 0x8C, 0.6f, 5);
        }
        if (ui->unkB8 == NULL) {
            ui->unkB8 = func_80082010(5, 0xA0, 0x73, 0x8C, 0.6f, 5);
        }
        if (ui->unkBC == NULL) {
            ui->unkBC = func_80082010(5, 0xD2, 0x73, 0x8C, 0.6f, 5);
        }
    } else {
        func_8006DF40(0x100, 0x28, D_8001E568, 0, 0, 0x100, 0);
        func_8006DF40(0x100, 0x3C, D_8001E588, 0, 0, 0x100, 0);
        func_8006DF40(0x100, 0x50, D_8001E5A0, 0, 0, 0x100, 0);
        func_8006DF40(0x100, 0xB4, D_8001E5B4, 0, 0, 0x100, 0);
        n = 0;
        for (i = 0; i < 10; i++) {
            f = D_800DE9F4[i + D_800DE7A8->unk3E0 * 20 + 0xC];
            if (f & 0x20) {
                kinds[n++] = 5;
            } else if (f & 0x40) {
                kinds[n++] = 6;
            } else if (f & 0x80) {
                kinds[n++] = 7;
            }
        }
        if (ui->unkB4 == NULL) {
            ui->unkB4 = func_80082010(kinds[0], 0x6E, 0x73, 0x8C, 0.6f, 5);
        }
        if (ui->unkB8 == NULL) {
            ui->unkB8 = func_80082010(kinds[1], 0xA0, 0x73, 0x8C, 0.6f, 5);
        }
        if (ui->unkBC == NULL) {
            ui->unkBC = func_80082010(kinds[2], 0xD2, 0x73, 0x8C, 0.6f, 5);
        }
    }
    ui->unkB4->vt->e.fn((u8 *)ui->unkB4 + ui->unkB4->vt->e.delta);
    ui->unkB8->vt->e.fn((u8 *)ui->unkB8 + ui->unkB8->vt->e.delta);
    ui->unkBC->vt->e.fn((u8 *)ui->unkBC + ui->unkBC->vt->e.delta);
    ok = 1;
    if (ui->unkB4 != NULL) {
        ok = ui->unkB4->unk214 >= 40;
    }
    if (ok && ui->unk118 == 0) {
        func_80095870(D_800DDE04);
    }
}
