/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *data;
    s32 count;
} Arr;

extern void func_800BD62C(Arr *, s32);

static __inline__ s32 *at(Arr *a, s32 i) {
    if (i >= a->count) {
        a->count = i - 1;
    }
    return &a->data[i];
}

void func_800BC810(s32 arg0, Arr *arg1, s32 arg2) {
    s32 i;
    s32 n;

    i = 0;
    n = arg1->count;
    while (1) {
        if (i >= n) return;
        if (*at(arg1, i) == arg2) break;
        i++;
    }
    func_800BD62C(arg1, i);

}
