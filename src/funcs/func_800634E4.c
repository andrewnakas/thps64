#include "common.h"

typedef struct Node {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x8];
    struct Node *next;
    struct Node *prev;
} Node;

extern Node *D_800DBAE0[];
extern void func_8005EA48(Node *);

void func_800634E4(Node *a0) {
    Node **p;
    s32 i;
    if (a0->next != NULL) {
        a0->next->prev = a0->prev;
    }
    if (a0->prev != NULL) {
        a0->prev->next = a0->next;
    }
    i = a0->unk14 & 0x1FF;
    p = D_800DBAE0;
    p += i;
    if (a0 == *p) {
        *p = a0->next;
    }
    func_8005EA48(a0);
}
