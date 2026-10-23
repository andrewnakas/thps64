/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x10];
    u8 a, b, c;
    u8 pad2[0x154 - 0x13];
} Ent;

typedef struct {
    u8 pad[0x28C];
    s32 flags;
    u8 pad2[0x3E0 - 0x290];
    s32 idx;
} Obj;

extern Ent D_800D4D80[];

void func_8004C774(Obj *arg0) {
    Ent *base;
    Ent *e;
    s32 m;

    base = D_800D4D80;
    e = &base[arg0->idx];
    arg0->flags &= ~((1 << e->a) | (1 << e->b) | (1 << e->c));
}
