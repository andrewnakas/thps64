/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[6];
    u16 unk6;
    s16 unk8;
    union {
        s16 h;
        u8 b[2];
    } unkA;
    u8 padC[3];
    u8 unkF;
} Item80025634;

typedef struct {
    s32 unk10;
    s32 base;
    Item80025634 *items;
    s32 *hdr;
} Ctx80025634;

typedef struct {
    u8 pad0[0x38];
    u16 unk38;
    u16 unk3A;
} Scale80025634;

typedef struct {
    u8 pad0[0xB88];
    Scale80025634 *unkB88;
} Obj80025634;

void func_800261C0(Ctx80025634 *, s32);
s32 func_800261A8(Ctx80025634 *, s32);

void func_80025634(Obj80025634 *arg0, s32 **arg1) {
    Ctx80025634 ctx;
    Ctx80025634 *c;
    Item80025634 *it;
    Item80025634 *first;
    s32 *h;
    s32 n;
    s32 i;
    s32 j;
    Item80025634 *it2;

    n = **arg1;
    c = &ctx;
    func_800261C0(c, n);
    h = (s32 *)(ctx.base + func_800261A8(c, 2));
    ctx.hdr = h;
    ctx.items = (Item80025634 *)(h + 2);
    first = ctx.items;
    h = ctx.hdr;
    n = *h;
    i = 0;
    it = first;
loop1:
    if (i < n) {
        i++;
        it->unk6 = it->unk8;
        it->unkF = it->unkA.b[1];
        it++;
        goto loop1;
    }
    j = 0;
    it2 = first;
loop2:
    if (j < n) {
        it2->unk8 = (it2->unk8 * arg0->unkB88->unk38) / 32;
        it2->unkA.h = (it2->unkA.h * arg0->unkB88->unk3A) / 32;
        it2++;
        j++;
        goto loop2;
    }
}
