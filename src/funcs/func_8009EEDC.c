/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    struct Node *unk0;
    struct Node *next;
    u8 pad8[0xC];
    u32 size;
} Node;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);

void func_8009EEDC(u8 *arg0, u32 *arg1, u32 *arg2) {
    struct { s32 q; s32 pad; } l;
    Node *n;
    u32 v;

    l.q = *(s32 *)(arg0 + 0x14);
    func_80005070(l.q, 0, 1);
    if (arg1 != NULL) {
        *arg1 = 0;
    }
    if (arg2 != NULL) {
        *arg2 = 0;
    }
    for (n = *(Node **)arg0; n != NULL; n = n->next) {
        if (arg1 != NULL) {
            *arg1 += n->size;
        }
        if (arg2 != NULL) {
            v = n->size;
            if (v < *arg2) {
                v = *arg2;
            }
            *arg2 = v;
        }
    }
    func_80004ED0(l.q, 0, 1);

}
