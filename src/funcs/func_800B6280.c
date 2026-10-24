/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *data;
    s32 base;
} Reader;

typedef struct {
    s32 *items;
    s32 count;
} List;

s32 func_800B713C(Reader *, s32);
void func_800B7160(Reader *, s32);
s32 func_800BAB04(s32 *, s32);
extern s32 D_800EECF0;

static __inline__ s32 *read_(Reader *c, s32 base) {
    func_800B7160(c, base);
    return (s32 *)(c->base + func_800B713C(c, 0));
}

void func_800B6280(List *arg0) {
    Reader a;
    Reader b;
    Reader c;
    s32 i;
    s32 j;
    s32 n;
    s32 *p;
    Reader *pa;

    i = 0;
    pa = &a;
    while (1) {
        if (i >= arg0->count) {
            break;
        }
        func_800B7160(pa, arg0->items[i]);
        func_800B7160(&b, pa->base + func_800B713C(pa, 1));
        j = 0;
        n = *b.data;
        while (1) {
            if (j >= n) {
                break;
            }
            p = read_(&c, b.base + func_800B713C(&b, j));
            if (p[1] & 1) {
                p[0] = func_800BAB04(&D_800EECF0, p[0]);
            } else {
                p[0] = 0;
            }
            j++;
        }
        i++;
    }
}
