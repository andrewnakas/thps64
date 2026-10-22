#include "common.h"

typedef struct Node80063554 {
    u8 pad0[0x10];
    u32 a : 16;
    u32 b : 4;
    u32 c : 12;
    s32 id;
    u8 pad18[0x20 - 0x18];
    struct Node80063554 *next;
    struct Node80063554 *prev;
} Node80063554;

Node80063554 *func_8005EAB4(s32, s32, s32);
extern Node80063554 *D_800DBAE0[];

Node80063554 *func_80063554(s32 arg0) {
    Node80063554 *n;
    s32 i;

    n = func_8005EAB4(0x28, 0, 1);
    i = arg0 & 0x1FF;
    n->next = D_800DBAE0[i];
    n->prev = NULL;
    D_800DBAE0[i] = n;
    if (n->next != NULL) {
        n->next->prev = n;
    }
    n->id = arg0;
    n->b = 0;
    n->a = 0;
    return n;
}
