/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    u8 pad0[0xC];
    struct Node *next;
    u8 pad10[8];
    s32 unk18;
    u8 unk1C[4];
} Node;

typedef struct {
    u8 pad0[8];
    Node *head;
    u8 padC[8];
    void *mq;
} A;

void func_80004ED0(void *, void *, s32);
void func_80005070(void *, void *, s32);
void func_8009ED5C(A *, void *);

void func_8009F150(A *arg0) {
    void *l;
    void **pl;
    Node *n;
    Node *next;

    pl = &l;
    *pl = arg0->mq;
    func_80005070(*pl, NULL, 1);
    n = arg0->head;
    while (1) {
        if (n == NULL) {
            break;
        }
        next = n->next;
        if (n->unk18 != 0) {
            func_8009ED5C(arg0, n->unk1C);
        }
        n = next;
    }
    pl = &l;
    func_80004ED0(*pl, NULL, 1);
}
