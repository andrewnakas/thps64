/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    struct Node *next;
    s32 pad4[3];
    s32 t;
} Node;

typedef struct {
    Node *list;
    Node *b;
    Node *c;
    Node *a;
    s32 pad10[8];
    s64 now;
} Mgr;

extern Mgr *D_800ECC34;

s32 func_800B0354(Node **out) {
    Node *n;
    Node *m;
    Node *k;
    Node *j;
    s32 best;
    s32 r;
    s32 d;

    *out = NULL;
    n = D_800ECC34->list;
    best = 0x7FFFFFFF;
    if (n != NULL) do {
        if (n->t - D_800ECC34->now < best) {
            *out = n;
            best = n->t - D_800ECC34->now;
        }
        n = n->next;
    } while (n != NULL);
    m = D_800ECC34->a;
    if (m != NULL) {
        d = m->t - D_800ECC34->now;
        if (d < best) {
            *out = m;
            best = d;
        }
    }
    k = D_800ECC34->b;
    if (k != NULL) {
        d = k->t - D_800ECC34->now;
        if (d < best) {
            *out = k;
            best = d;
        }
    }
    j = D_800ECC34->c;
    if (j != NULL) {
        if (j->t - D_800ECC34->now < best) {
            *out = j;
        }
    }
    r = 0;
    if (*out != NULL) {
        r = (*out)->t;
    }
    return r;
}
