/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Slot;

typedef struct {
    u8 pad0[0x2288];
    Slot slots[3];
    s32 unk22AC;
    s32 unk22B0;
    s32 unk22B4;
    s32 unk22B8;
    s32 unk22BC;
    s32 unk22C0;
    s32 unk22C4[4];
    s32 unk22D4;
} Obj;

typedef struct {
    s32 count;
    s32 *items;
} List;

void func_80003010(s32);

void func_800BC2C8(Obj *arg0, List *arg1) {
    s32 i;
    s32 c;

    func_80003010(1);
    arg0->unk22D4 = 1;
    arg0->unk22B0 = 0;
    arg0->unk22AC = 0;
    c = arg1->count;
    arg0->unk22B8 = 0;
    arg0->unk22BC = c;
    for (i = 0; i < arg1->count; i++) {
        s32 v = arg1->items[i];
        arg0->slots[i].unk8 = 0;
        arg0->slots[i].unk0 = v;
    }
    arg0->unk22C0 = 0;
    for (i = 3; i >= 0; i--) {
        arg0->unk22C4[i] = 0;
    }
    arg0->unk22B4 = 1;
}
