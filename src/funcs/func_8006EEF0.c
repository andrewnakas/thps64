#include "common.h"

typedef struct Node {
    u8 pad[0x14];
    struct Node *next;
} Node;

extern Node *D_800DCAA0;
extern void func_8005EA48(Node *);

void func_8006EEF0(void) {
    Node *p;
    Node *n;

    p = D_800DCAA0;
    if (p != NULL) {
        n = p->next;
        while (1) {
            func_8005EA48(p);
            if (n == NULL) {
                break;
            }
            p = n;
            n = n->next;
        }
    }
    D_800DCAA0 = NULL;
}
