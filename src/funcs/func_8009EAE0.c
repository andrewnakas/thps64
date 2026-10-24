/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
} Obj8009EAE0;

typedef struct {
    s32 h;
} Lock8009EAE0;

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);
extern s32 func_8009EB54(Obj8009EAE0 *, s32, s32);

static __inline__ void lock8009EAE0(Lock8009EAE0 *l, s32 h) {
    l->h = h;
    func_80005070(h, 0, 1);
}

static __inline__ void unlock8009EAE0(Lock8009EAE0 *l) {
    func_80004ED0(l->h, 0, 1);
}

s32 func_8009EAE0(Obj8009EAE0 *arg0, s32 arg1, s32 arg2) {
    Lock8009EAE0 l;
    s32 r;

    lock8009EAE0(&l, arg0->unk14);
    r = func_8009EB54(arg0, arg1, arg2);
    unlock8009EAE0(&l);
    return r;
}
