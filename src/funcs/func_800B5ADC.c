/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0xC];
    u8 c[4];
} Elem;

void func_800B5ADC(s32 arg0, s32 *arg1, u8 *arg2) {
    struct { Elem *p; s32 *h; } s;
    s32 i;
    s32 j;
    s32 n;
    Elem *e;

    i = 0;
    s.h = arg1;
    s.p = (Elem *)(arg1 + 2);
    n = *s.h;
    while (1) {
        j = 0;
        if (i >= n) break;
        e = &s.p[i];
        for (; j < 3; j++) {
            e->c[j] = arg2[e->c[j]];
        }
        i++;
    }

}
