/* cflags: -O2 */
#include "common.h"

void func_80004ED0(void *, void *, s32);
void func_80005070(void *, void *, s32);

typedef struct { u8 pad[0x14]; void *mq; } A;
typedef struct { u8 pad[0x14]; u32 n; } C;

s32 func_8009E4C8(A *arg0, u8 *arg1) {
    void *l;
    void **pl = &l;
    s32 r;
    C *p;

    *pl = arg0->mq;
    func_80005070(*pl, NULL, 1);
    p = *(C **)(arg1 - 0x14);
    r = 0;
    if (p != NULL) {
        r = p->n > 0;
    }
    func_80004ED0(*pl, NULL, 1);
    return r;
}
