#include "common.h"

void func_80022964(s32 *);
void func_80043590(s32 *);
void func_8004356C(s32 *);
void func_80042C70(void);
void func_80043264(s32 *);

#define H(o) (*(s16 *)(arg0 + (o)))
#define W(o) (*(s32 *)(arg0 + (o)))

void func_800598B8(u8 *arg0) {
    s32 c[4];
    s32 a[4];
    s32 b[4];
    s32 v;
    s16 x;
    s32 h;

    v = W(0x918);
    if (v < 0x19) {
        if (v == 0x18) {
            s32 x0 = H(0x100);
            s32 x1 = H(0x102);
            s32 x2 = H(0x104);
            a[0] = x0;
            a[1] = x1;
            a[2] = x2;
        } else {
            h = H(0x100);
            v = W(0x91C);
            v += (h - v) >> 2;
            a[0] = v;
            h = H(0x102);
            v = W(0x920);
            v += (h - v) >> 2;
            a[1] = v;
            h = H(0x104);
            v = W(0x924);
            v += (h - v) >> 2;
            a[2] = v;
        }
        func_80022964(a);
        {
            s32 y0 = H(0x888);
            s32 y1 = H(0x88E);
            s32 y2 = H(0x894);
            W(0x8D0) = y0;
            W(0x8D4) = y1;
            W(0x8D8) = y2;
        }
        func_80043590((s32 *)(arg0 + 0x8D0));
        func_8004356C(a);
        func_80042C70();
        func_80043264(b);
        func_80022964(b);
        func_80043590(a);
        func_8004356C(b);
        func_80042C70();
        func_80043264(c);
        x = b[0];
        H(0x884) = x;
        W(0x8DC) = x;
        x = b[1];
        H(0x88A) = x;
        W(0x8E0) = x;
        x = b[2];
        H(0x890) = x;
        W(0x8E4) = x;
        x = a[0];
        H(0x886) = x;
        W(0x8E8) = x;
        x = a[1];
        H(0x88C) = x;
        W(0x8EC) = x;
        x = a[2];
        H(0x892) = x;
        W(0x8F0) = x;
        x = c[0];
        H(0x888) = x;
        W(0x8D0) = x;
        x = c[1];
        H(0x88E) = x;
        W(0x8D4) = x;
        x = c[2];
        H(0x894) = x;
        W(0x8D8) = x;
        {
            s32 z0 = a[0];
            s32 z1 = a[1];
            s32 z2 = a[2];
            W(0x91C) = z0;
            W(0x920) = z1;
            W(0x924) = z2;
        }
    }
}
