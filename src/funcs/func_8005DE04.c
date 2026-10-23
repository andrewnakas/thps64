#include "common.h"

typedef struct {
    u8 pad[0x20];
    u8 *p20;
    u8 pad2[0x14];
    u16 h38;
    u8 pad3[0x48 - 0x3A];
} Ent;

extern Ent D_800DAF98[];
void func_8005D0B0(s32, s32, u8 *, u8 *, s32, s32);

void func_8005DE04(u8 *a) {
    Ent *base;
    Ent *e;
    u8 *p;
    s32 v;
    s32 h;
    s32 n;

    base = D_800DAF98;
    e = &base[a[0x1B]];
    p = e->p20;
    v = *(u16 *)(p + *(u16 *)(a + 0x21E) * 8 + 8);
    n = v + 1;
    if (v != 0) {
        h = e->h38;
        func_8005D0B0(h * 4, n, p, a, 0, h);
    }
}
