#include "common.h"

typedef struct Node_6EE1C {
    s32 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    s32 f;
    s32 g;
    struct Node_6EE1C *next;
    struct Node_6EE1C *prev;
} Node_6EE1C;

Node_6EE1C *func_8005EAB4(s32, s32, s32);
extern Node_6EE1C *D_800DCAA0;

Node_6EE1C *func_8006EE1C(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    Node_6EE1C *n;
    s32 e;

    e = arg4;
    n = func_8005EAB4(0x1C, 0, 1);
    n->next = D_800DCAA0;
    n->prev = NULL;
    D_800DCAA0 = n;
    if (n->next != NULL) {
        n->next->prev = n;
    }
    n->a = arg0;
    n->g = arg1;
    n->b = 0;
    n->c = 0;
    n->f = arg2;
    n->d = arg3;
    n->e = e;
    return n;
}
