/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.779; FP regalloc, not reworked, best 65/84. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2: not reworked (D8 draft 65/84). Left: FP regalloc (f-n pseudo f22 after sched1, game reuses f10). */
#include "common.h"

typedef struct {
    u8 pad0[0xA0];
    f32 proj[4][4];
    u8 unkE0[0x40];
    u8 unk120[0x40];
    f32 l, r, b, t, n, f;
    u8 pad178[0x4D8];
    u16 persp;
} View;

void func_8009CA00(void *, void *, f32 (*)[4]);

void func_800A4418(View *arg0, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f) {
    f32 (*m)[4];
    f32 n2;
    f32 w;
    f32 h;
    f32 d;
    f32 q;
    u32 u;

    d = f - n;
    n2 = n + n;
    w = r - l;
    h = t - b;
    arg0->proj[0][0] = n2 / w;
    m = arg0->proj;
    m[1][1] = n2 / h;
    m[2][0] = (r + l) / w;
    m[2][1] = (t + b) / h;
    m[2][2] = -(f + n) / d;
    m[2][3] = -1.0f;
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[3][0] = m[3][1] = m[3][3] = 0.0f;
    m[3][2] = -(n2 * f) / d;
    arg0->l = l;
    arg0->r = r;
    arg0->b = b;
    arg0->t = t;
    arg0->n = n;
    arg0->f = f;
    func_8009CA00(arg0->unk120, arg0->unkE0, m);
    q = 131072.0f / (arg0->f + arg0->n);
    if (!(q >= 2147483648.0f)) {
        u = (s32)q;
    } else {
        u = (s32)(q - 2147483648.0f);
        u |= 0x80000000;
    }
    arg0->persp = u;
}
