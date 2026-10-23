#include "common.h"

typedef struct {
    u8 pad[0x10];
    u8 a;
    u8 b;
    u8 c;
    u8 pad2[0x154 - 0x13];
} Ent;

extern Ent D_800D4D80[];

void func_8004C7CC(u8 *arg0) {
    Ent *base;
    Ent *e;
    s32 mask;
    s32 t;

    base = D_800D4D80;
    e = &base[*(s32 *)(arg0 + 0x3E0)];
    mask = (1 << e->a) | (1 << e->b) | (1 << e->c);
    t = *(s32 *)(arg0 + 0x28C);
    t |= mask;
    *(s32 *)(arg0 + 0x28C) = t;
}
