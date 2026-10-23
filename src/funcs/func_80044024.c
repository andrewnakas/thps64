#include "common.h"

typedef struct {
    u8 pad[0x168];
    u8 b168;
    u8 b169;
    u8 b16A;
    u8 b16B;
    s32 pad16C;
    s32 w170;
    u8 pad2[0x18C - 0x174];
} Ent;

extern void func_80043FB0(Ent *);
extern Ent D_800D49E0[];

void func_80044024(s32 arg0) {
    Ent *base;
    Ent *p;

    base = D_800D49E0;
    p = &base[arg0];
    func_80043FB0(p);
    p->w170 = 0;
    p->b16B = 0;
    p->b16A = 0;
    p->b169 = 0;
    p->b168 = 0;
}
