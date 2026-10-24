/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    s32 unk18;
} Obj8009F0EC;

typedef struct {
    s32 h;
} Lock8009F0EC;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);

static __inline__ void lock8009F0EC(Lock8009F0EC *l, s32 h) {
    l->h = h;
    func_80005070(h, 0, 1);
}

static __inline__ void unlock8009F0EC(Lock8009F0EC *l) {
    func_80004ED0(l->h, 0, 1);
}

s32 func_8009F0EC(Obj8009F0EC *arg0, s32 arg1) {
    Lock8009F0EC l;
    s32 old;

    lock8009F0EC(&l, arg0->unk14);
    old = arg0->unk18;
    arg0->unk18 = arg1;
    unlock8009F0EC(&l);
    return old;
}
