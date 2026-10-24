/* cflags: -O2 */
#include "common.h"

void func_80004ED0(void *, void *, s32);
void func_80005070(void *, void *, s32);
s32 func_8009ED5C(void *, s32);

typedef struct { u8 pad[0x14]; void *mq; } A;

s32 func_8009ECF8(A *arg0, s32 arg1) {
    void *l;
    void **pl = &l;
    s32 r;

    *pl = arg0->mq;
    func_80005070(*pl, NULL, 1);
    r = func_8009ED5C(arg0, arg1);
    func_80004ED0(*pl, NULL, 1);
    return r;
}
