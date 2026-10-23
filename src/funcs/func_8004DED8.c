/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s16 **D_800DACB0;
typedef struct {
    u8 pad[0x1C];
    s32 f1C;
    u8 pad20[0x28];
} E48;
extern E48 D_800DAF98[];
extern s32 D_800DE7A0;
u16 *func_80061904(s32);
u8 *func_800635E4(s32);
void *func_800352A4(s32);
void func_800696B0();

void func_8004DED8(u8 *arg0) {
    s16 *p;
    s16 *e;
    u16 *n;
    s32 v;
    s32 i;
    s32 sum;
    s32 cnt;
    s32 a;
    s32 b;
    s32 r;
    u8 *q;
    u8 *t;
    s32 c14;
    s32 c12;
    s32 two;
    s32 pad[2];
    u8 *q2;

    if (*D_800DACB0[*(s32 *)(arg0 + 0x7E0)] == 0xB) {
        n = func_80061904(*(s32 *)(arg0 + 0x7E0));
        e = D_800DACB0[n[1]];
        if (*e == (c14 = 0xE) || *e == (c12 = 0xC)) {
            p = e;
        } else {
            e = D_800DACB0[n[2]];
            if (*e == c14 || *e == c12) {
                p = e;
            }
        }
        p = (s16 *)((u8 *)p + ((u16)p[1] * 2 + 4));
        if ((s32)p & 3) {
            p = (s16 *)((u8 *)p + 2);
        }
        p = (s16 *)*(s32 *)p;
        if (*(void **)(arg0 + 0x510) != NULL && *(s32 *)(arg0 + 0x514) != 0) {
            sum = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0xDA4); i++) {
                sum += *(s32 *)(arg0 + 0xC18 + i * 0x14);
            }
            a = *(s32 *)(arg0 + 0xDA4) * 2;
            b = *(s32 *)(arg0 + 0x424);
            two = 2;
            if (b < 3) {
                r = sum * (a + b) / 2;
            } else {
                r = a;
                r = sum * (r - two + b * 2) >> 1;
            }
            if (r > 0) {
                func_800696B0(*(void **)(arg0 + 0x510), arg0, r, c14);
            }
        }
        q = func_800635E4((s32)p);
        *(u8 **)(arg0 + 0x510) = q;
        *(s32 *)(arg0 + 0x514) = D_800DAF98[q[0x1B]].f1C;
        q2 = func_800352A4((s32)p);
        *(u8 **)(arg0 + 0x510) = q2;
        if (D_800DE7A0 == 1) {
            func_800696B0(q2, arg0, -1);
        }
    }
}
