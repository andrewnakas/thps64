#include "common.h"

typedef struct Node {
    u8 pad[0x14];
    struct Node *next;
    struct Node *prev;
} Node;

extern Node *D_800DCAA0;
void func_8005EA48(Node *);

void func_8006EF44(Node *a) {
    if (a->next != NULL) {
        a->next->prev = a->prev;
    }
    if (a->prev != NULL) {
        a->prev->next = a->next;
    }
    if (a == D_800DCAA0) {
        D_800DCAA0 = a->next;
    }
    func_8005EA48(a);
}
