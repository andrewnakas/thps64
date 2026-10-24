/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *p;
    s32 base;
} Rd800B6F9C;

typedef struct {
    s32 *ptr;
    s32 flags;
} Ent800B6F9C;

s32 func_800B713C(Rd800B6F9C *, s32);
void func_800B7160(Rd800B6F9C *, s32);

static __inline__ Ent800B6F9C *read_(Rd800B6F9C *c, s32 base) {
    func_800B7160(c, base);
    return (Ent800B6F9C *)(c->base + func_800B713C(c, 0));
}

s32 func_800B6F9C(s32 **arg0, s32 arg1, s32 arg2) {
    Rd800B6F9C r0;
    Rd800B6F9C r1;
    Rd800B6F9C r2;
    Ent800B6F9C *e;
    s32 i;
    s32 n;
    s32 count;

    Rd800B6F9C *p;

    n = 0;
    p = &r0;
    func_800B7160(p, (*arg0)[arg2]);
    func_800B7160(&r1, p->base + func_800B713C(p, 1));
    i = 0;
    count = *r1.p;
loop:
    if (i < count) {
        e = read_(&r2, r1.base + func_800B713C(&r1, i));
        if ((e->flags & 1) && e->ptr != NULL) {
            if (arg1 == n) {
                return e->ptr[1];
            }
            n++;
        }
        i++;
        goto loop;
    }
    return 0;
}
