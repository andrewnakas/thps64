#include "common.h"

typedef struct {
    s16 a;
    s16 b;
    s32 c;
} Item;

typedef struct {
    u8 pad0[0x1C];
    u32 cnt;
    u8 pad20[0x30];
    Item items[5];
} G;

extern G D_800DC618;

void func_8006A6AC(void) {
    Item tmp[5];
    Item zero;
    Item *p;
    Item *q;
    Item *d;
    G *g;
    G *g2;
    Item *end;
    Item *cur;
    Item *src;
    Item *r;
    s32 i;
    s32 n;
    s32 k;
    s32 off;

    zero.c = 0;
    zero.b = 0;
    zero.a = 0;
    g = &D_800DC618;
    p = tmp;
    end = &tmp[5];
loop:
    if ((s32)p < (s32)end) {
        *p = zero;
        off = 0x7FFFFFFF;
        k = -1;
        for (i = 0, q = (Item *)g; i < 5; i++, q++) {
            if (!((u32)q[10].b < g->cnt)) {
                q[10].b = g->cnt - 1;
            }
            if (q[10].c != 0 && q[10].a < off) {
                off = q[10].a;
                k = i;
            }
        }
        if (k != -1) {
            Item *t = (Item *)(k * 8 + (s32)g);
            *p = t[10];
            t[10].c = 0;
        }
        p++;
        goto loop;
    }
    for (n = 4, cur = &tmp[4], off = 0x18; n > 0; n--) {
        s32 a = cur->a;
        Item *prev = (Item *)((u8 *)tmp + off);
        if (!(a > prev->b + 15) && a > prev->a) {
            if (prev->b < cur->b) {
                prev->b = cur->b;
            }
            prev->c += cur->c;
            *cur = zero;
        }
        cur--;
        off -= 8;
    }
    for (k = 0, g2 = &D_800DC618, src = tmp, d = q = (Item *)g2; k < 5; k++) {
        q[10] = zero;
        if (src->c != 0) {
            d[10] = *src;
            d++;
        }
        src++;
        q++;
    }
}
