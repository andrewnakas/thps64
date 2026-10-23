#include "common.h"

typedef struct {
    s16 id;
    u8 pad2[0x10 - 2];
    void *a;
    void *b;
} Ent43630;

void func_8009E0F0(void *, s32, s32);
extern u8 D_800D0FC0[];
extern u8 D_800D49E0[];
extern Ent43630 D_800FA6B0[];

void func_80043630(void) {
    u8 *c;
    u8 *m;
    Ent43630 *e;

    c = D_800D0FC0;
    c[0] = 1;
    c[1] = 1;
    c[0x26] = 0;
    c[0x27] = 0;
    m = D_800D49E0;
    *(s32 *)(m + 0x16C) = 0x41;
    *(s32 *)(m + 0x2F8) = 0x41;
    e = D_800FA6B0;
    func_8009E0F0(e, 0, 0x150);
    D_800FA6B0[0].id = 0x8;
    D_800FA6B0[1].id = 0x2;
    D_800FA6B0[2].id = 0x1;
    D_800FA6B0[3].id = 0x4;
    D_800FA6B0[4].id = 0x20;
    D_800FA6B0[5].id = 0x20;
    D_800FA6B0[6].id = 0x10;
    D_800FA6B0[7].id = 0x10;
    D_800FA6B0[8].id = 0x200;
    D_800FA6B0[9].id = 0x100;
    D_800FA6B0[10].id = 0x800;
    D_800FA6B0[11].id = 0x400;
    D_800FA6B0[12].id = 0x2000;
    D_800FA6B0[13].id = 0x1000;
    D_800FA6B0[0].a = m + 0x0;
    D_800FA6B0[0].b = m + 0x18C;
    D_800FA6B0[1].a = m + 0x10;
    D_800FA6B0[1].b = m + 0x19C;
    D_800FA6B0[2].a = m + 0x20;
    D_800FA6B0[2].b = m + 0x1AC;
    D_800FA6B0[3].a = m + 0x30;
    D_800FA6B0[3].b = m + 0x1BC;
    D_800FA6B0[4].a = m + 0x40;
    D_800FA6B0[4].b = m + 0x1CC;
    D_800FA6B0[5].a = m + 0x50;
    D_800FA6B0[5].b = m + 0x1DC;
    D_800FA6B0[6].a = m + 0x60;
    D_800FA6B0[6].b = m + 0x1EC;
    D_800FA6B0[7].a = m + 0x70;
    D_800FA6B0[7].b = m + 0x1FC;
    D_800FA6B0[8].a = m + 0x80;
    D_800FA6B0[8].b = m + 0x20C;
    D_800FA6B0[9].a = m + 0x90;
    D_800FA6B0[9].b = m + 0x21C;
    D_800FA6B0[10].a = m + 0xA0;
    D_800FA6B0[10].b = m + 0x22C;
    D_800FA6B0[11].a = m + 0xB0;
    D_800FA6B0[11].b = m + 0x23C;
    D_800FA6B0[12].a = m + 0xF0;
    D_800FA6B0[12].b = m + 0x27C;
    D_800FA6B0[13].a = m + 0xE0;
    D_800FA6B0[13].b = m + 0x26C;
}
