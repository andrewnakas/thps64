#include "common.h"

typedef struct {
    u16 x, y, z;
} V3;

extern V3 D_800D4958[];

void func_80043514(u8 *arg0) {
    s32 i;
    V3 *d;
    u8 *d2;
    V3 *s;

    i = 0;
    d = D_800D4958;
    d2 = (u8 *)d;
    s = (V3 *)arg0;
    do {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
        *(s32 *)(d2 + 0x14) = *(s32 *)(arg0 + 0x14);
        arg0 += 4;
        d2 += 4;
        d++;
        i++;
        s++;
    } while (i < 3);
}
