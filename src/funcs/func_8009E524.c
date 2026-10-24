/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
} Obj8009E524;

typedef struct {
    s32 h;
} Lock8009E524;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);
extern s32 func_8009E5A8(Obj8009E524 *, s32, s32, s32);

static __inline__ void lock8009E524(Lock8009E524 *l, s32 h) {
    l->h = h;
    func_80005070(h, 0, 1);
}

static __inline__ void unlock8009E524(Lock8009E524 *l) {
    func_80004ED0(l->h, 0, 1);
}

s32 func_8009E524(Obj8009E524 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Lock8009E524 l;
    s32 r;

    lock8009E524(&l, arg0->unk14);
    r = func_8009E5A8(arg0, arg1, arg2, arg3);
    unlock8009E524(&l);
    return r;
}
