/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x10];
} Slot;

typedef struct Node {
    s32 unk0;
    u8 pad4[0x3C];
    struct Node *unk40;
} Node;

typedef struct {
    u8 pad0[0x528];
    Slot slots[200];
    u8 pad2148[0x2154 - 0x528 - 200 * 0x24];
    Node *unk2154;
} Obj;

void func_800ABE14(s32, s32);

void func_800AA864(Obj *arg0) {
    Node *n;

    for (n = arg0->unk2154; n != NULL; n = n->unk40) {
        func_800ABE14(arg0->slots[n->unk0].unk10, 0);
    }
    arg0->unk2154 = NULL;
}
