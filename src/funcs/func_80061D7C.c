#include "common.h"

typedef struct Node {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 pad6[4];
    u16 unkA;
    s32 unkC;
    struct Node *next;
} Node;

void func_800601A0(s32, u16, s32);
extern s32 D_800D61A0;
extern s32 D_800DE7A8;
extern Node *D_800FB750[];

Node *func_80061D7C(s32 arg0) {
    s32 flag;
    Node *n;

    n = D_800FB750[arg0 & 0xFF];
    for (;;) {
        if (n == NULL) {
            return NULL;
        }
        if (n->unkC == arg0) {
            flag = 2;
            if (D_800D61A0 == D_800DE7A8) {
                flag = 1;
            }
            n->unk4 |= flag;
            if (!(n->unk5 & flag)) {
                func_800601A0(n->unk0, n->unkA, 0);
                n->unk5 |= flag;
                return n;
            }
        }
        n = n->next;
    }
}
