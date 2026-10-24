/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    u8 *data;
    s32 unk4;
    s32 unk8;
    s32 owned;
    struct Node *next;
} Node;

extern void func_8009E334(Node **);
extern void func_8009ECF8(u8 *, void *);
extern void func_800B73D4(Node **);
extern u8 D_800EA110[];

void func_800B720C(Node **arg0, s32 arg1) {
    Node *n;
    Node *next;

    func_800B73D4(arg0);
    n = *arg0;
    while (1) {
        if (n == NULL) break;
        next = n->next;
        if (n->owned != 0) {
            func_8009ECF8(D_800EA110, n->data);
        }
        func_8009ECF8(D_800EA110, n);
        n = next;
    }
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
