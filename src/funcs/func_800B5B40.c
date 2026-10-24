/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *data;
    s32 base;
} Hdl800B5B40;

typedef struct {
    s32 *items;
    s32 count;
} Obj800B5B40;

extern void func_800B5ADC(Obj800B5B40 *, s32, s32);
extern s32 func_800B713C(Hdl800B5B40 *, s32);
extern void func_800B7160(Hdl800B5B40 *, s32);

static __inline__ s32 *read_(Hdl800B5B40 *c, s32 base) {
    func_800B7160(c, base);
    return (s32 *)(c->base + func_800B713C(c, 0));
}

void func_800B5B40(Obj800B5B40 *arg0, s32 arg1) {
    Hdl800B5B40 h0;
    Hdl800B5B40 *ph;
    Hdl800B5B40 h1;
    Hdl800B5B40 h2;
    s32 i;
    s32 j;
    s32 n;
    s32 found;
    s32 *p;

    i = 0;
    ph = &h0;
    while (1) {
        if (i >= arg0->count) break;
        func_800B7160(ph, arg0->items[i]);
        found = 0;
        func_800B7160(&h1, ph->base + func_800B713C(ph, 1));
        n = *h1.data;
        j = 0;
        while (1) {
            if (j >= n) break;
            p = read_(&h2, h1.base + func_800B713C(&h1, j));
            if (p[1] & 0x8000) {
                func_800B5ADC(arg0, h2.base + func_800B713C(&h2, 2), arg1);
            }
            j++;
            if (!(p[1] & 0x400)) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            func_800B5ADC(arg0, ph->base + func_800B713C(ph, 2), arg1);
        }
        i++;
    }
}
