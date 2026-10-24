/* cflags: -O2 */
#include "common.h"

typedef struct Node800B48BC {
    u8 pad0[0x4];
    struct Node800B48BC *next;
    u8 pad8[0x8];
    void *unk10;
} Node800B48BC;

typedef struct {
    u8 pad0[0x3C];
    Node800B48BC *unk3C;
} Obj800B48BC;

extern void func_8009E334(void *);
extern void func_800B5A4C(void *);

void func_800B48BC(Obj800B48BC *arg0) {
    Node800B48BC *n;
    Node800B48BC *next;
    void *c;

    n = arg0->unk3C;
    while (1) {
        if (n == NULL) break;
        c = n->unk10;
        next = n->next;
        if (c != NULL) {
            func_800B5A4C(c);
            func_8009E334(c);
        }
        func_8009E334(n);
        n = next;
    }
    arg0->unk3C = NULL;
}
