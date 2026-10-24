/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s32 val;
} Sub;

typedef struct {
    u8 pad0[0x1C8];
    u8 c1C8[0xC];
    u8 c1D4[0xC];
    u8 c1E0[0xC];
    Sub s1EC;
    u8 pad1EC[0x208 - 0x1EC - sizeof(Sub)];
    Sub s208;
    u8 pad208[0x224 - 0x208 - sizeof(Sub)];
    Sub s224;
    u8 pad224[0x240 - 0x224 - sizeof(Sub)];
    Sub s240;
    u8 pad240[0x25C - 0x240 - sizeof(Sub)];
    s32 unk25C;
    s32 unk260;
    s32 unk264;
    s32 unk268;
    s32 unk26C;
    u8 a270[0x18];
    u8 a288[0x22D4 - 0x288];
    s32 unk22D4;
    s32 unk22D8;
    u8 pad22DC[0x22E8 - 0x22DC];
    u64 t22E8;
    u64 t22F0;
    u64 t22F8;
    u64 t2300;
    u64 t2308;
} Player;

void func_800BD5A0(void *, s32);
void func_80001EC0(void *, void *, s32);
void func_80011100(s32);
void func_80003010(s32);
void func_800114E0(void *);
void func_80002E00(s32, void *, s32);
void func_80011470(void *, s32, s32);
void func_80005070(void *, s32, s32);
void func_8009FFD8(Player *, s32, s32, s32);
void func_80004620(Player *);
extern s32 D_800F56BC;
extern u32 D_800F30F0;
extern f32 D_800F30F4;
extern s32 D_80011C18;
extern u8 D_800121F0[][0x50];

void func_800BC378(Player *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    u32 rate;
    Sub *q;
    f64 d;

    rate = 0x32;
    if (D_800F56BC != 0) {
        rate = 0x3C;
    }
    D_800F30F0 = rate;
    d = (s32)rate;
    if ((s32)rate < 0) {
        d += 4294967296.0;
    }
    D_800F30F4 = 1.0 / d;
    p->t22E8 = p->t22F0 = p->t22F8 = p->t2300 = p->t2308 = 0;
    q = &p->s1EC;
    q->val = a2;
    func_800BD5A0(q, a2);
    q = &p->s208;
    q->val = a1;
    func_800BD5A0(q, a1);
    q = &p->s224;
    q->val = a1;
    func_800BD5A0(q, a1);
    q = &p->s240;
    q->val = a1;
    func_800BD5A0(q, a1);
    p->unk26C = p->unk25C = p->unk260 = p->unk264 = p->unk268 = 0;
    func_80001EC0(p->a270, p->a288, 0x800);
    func_800BD5A0(p->c1C8, a3);
    func_800BD5A0(p->c1D4, a3);
    func_800BD5A0(p->c1E0, a3);
    func_80011100(0xFE);
    func_80003010(1);
    p->unk22D4 = 1;
    func_800114E0(D_800121F0[a6]);
    func_80003010(1);
    p->unk22D8 = 0;
    func_80002E00(4, p->a270, 1);
    func_80002E00(9, p->a270, 2);
    func_80002E00(0xE, p->a270, 4);
    func_80011470(p->a270, 3, 1);
    if (D_80011C18 != 0) {
        func_80005070(p->a270, 4, 1);
    }
    func_8009FFD8(p, a4, a5, 0x400);
    func_80004620(p);
}
