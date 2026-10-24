/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 pad1D[0xB];
} AudCfg;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x20];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} AudInit;

typedef struct {
    void *buf;
    s32 unk4;
} AudBuf;

s32 func_800BBB50(s32, s32);
s32 func_80002EB0(s32);
s32 func_800B1898(void);
void func_800AE560(void *, AudCfg *);
s32 func_800BBA50(f32, f32, f32, s32);
void *func_800B1850(s32);
void func_800043D0(void *, s32, void (*)(void *), void *, void *, s32);
void func_80004620(void *);
void func_800BB8F8(void *);
extern u8 D_800F0D48[];
extern u8 D_800FC680[];
extern u8 *D_800FC830;
extern AudBuf *D_800FC834;
extern void *D_800FC838;

void func_800BB7B0(AudInit *arg0, s32 arg1, u8 arg2) {
    AudCfg c;
    s32 n;
    s32 i;

    c.unk0 = c.unk4 = arg0->unk4;
    c.unk8 = arg0->unk28;
    c.unk10 = func_800BBB50(arg0->unk38, arg0->unk3C);
    c.unk1C = arg2;
    i = 0;
    c.unk18 = func_80002EB0(arg0->unk2C);
    c.unk14 = func_800B1898();
    func_800AE560(D_800F0D48, &c);
    n = func_800BBA50(arg0->unk34, c.unk18, arg1, 0x1E0);
    D_800FC838 = func_800B1850(arg0->unk30 * 8);
    D_800FC834 = func_800B1850(0x18);
    do {
        D_800FC834[i].buf = func_800B1850(n * 4);
        i++;
    } while (i < 3);
    D_800FC830 = func_800B1850(0x2000);
    func_800043D0(D_800FC680, 3, func_800BB8F8, NULL, D_800FC830 + 0x2000, 3);
    func_80004620(D_800FC680);
}
