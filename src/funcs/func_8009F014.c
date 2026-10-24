/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    struct Node *unk0;
    struct Node *next;
    u8 pad8[0xC];
    u32 unk14;
} Node;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);

void func_8009F014(u8 *arg0) {
    struct { s32 q; s32 pad; } l;
    Node *n;
    u32 m;
    u32 v;

    l.q = *(s32 *)(arg0 + 0x14);
    func_80005070(l.q, 0, 1);
    m = 0;
    for (n = *(Node **)arg0; n != NULL; n = n->next) {
        v = n->unk14;
        if (v < m) {
            v = m;
        }
        m = v;
    }
    func_80004ED0(l.q, 0, 1);

}
