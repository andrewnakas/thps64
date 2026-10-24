/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B4A08;

typedef struct {
    u8 pad0[0x40];
    s32 mtx[16];
    s32 n;
    u8 pad84[0x180C];
    s32 a;
    s32 b;
    u8 pad1898[0x408];
    s32 batching;
} Batch800B4A08;

void func_800B5210(Batch800B4A08 *);
void func_800B6B80(s32, s32);
extern Gfx800B4A08 *D_800F36A4;

void func_800B4A08(Batch800B4A08 *arg0, s32 a, s32 b, s32 mtx) {
    s32 n;
    s32 *p;

    if (arg0->batching != 0) {
        if (a != arg0->a || b != arg0->b || arg0->n == 0x10) {
            func_800B5210(arg0);
        }
        n = arg0->n;
        arg0->a = a;
        arg0->b = b;
        p = &arg0->mtx[n];
        n++;
        arg0->n = n;
        *p = mtx;
        return;
    }
    if (mtx != 0) {
        Gfx800B4A08 *g = D_800F36A4++;
        g->w0 = 0xDA380003;
        g->w1 = mtx;
    }
    func_800B6B80(a, b);
}
