#include "common.h"

typedef struct {
    u8 pad0[0x38];
    s16 unk38;
} Unk8003912CItem;

typedef struct {
    u8 pad0[0xC];
    Unk8003912CItem **items;
    s32 count;
} Unk8003912C;

void func_8003912C(Unk8003912C *arg0) {
    s32 i;

    for (i = 0; i < arg0->count; i++) {
        arg0->items[i]->unk38 = 0;
    }
}
