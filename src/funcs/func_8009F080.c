/* cflags: -O2 */
#include "common.h"

typedef struct Node8009F080 {
    u8 pad0[0xC];
    struct Node8009F080 *next;
    u32 unk10;
} Node8009F080;

typedef struct {
    u8 pad0[0x8];
    Node8009F080 *unk8;
    u8 padC[0x8];
    s32 unk14;
} Obj8009F080;

typedef struct {
    s32 h;
} Lock8009F080;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);

static __inline__ void lock8009F080(Lock8009F080 *l, s32 h) {
    l->h = h;
    func_80005070(h, 0, 1);
}

static __inline__ void unlock8009F080(Lock8009F080 *l) {
    func_80004ED0(l->h, 0, 1);
}

void func_8009F080(Obj8009F080 *arg0) {
    Lock8009F080 l;
    Node8009F080 *n;
    u32 max;
    u32 v;

    lock8009F080(&l, arg0->unk14);
    max = 0;
    for (n = arg0->unk8; n != NULL; n = n->next) {
        v = n->unk10;
        if (v < max) {
            v = max;
        }
        max = v;
    }
    unlock8009F080(&l);
}
