/* compiler: cc1plus */
/* cflags: */
/* NON_MATCHING: aln ratio 0.451; FP regalloc + scheduling; X3 draft was missing #include, best 23/50. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2: not reworked (X3 draft; the X3 file lacked #include "common.h", fixed here: 23/50 at -O1). Left: FP regalloc
 * order (game s f20, k/x f22, a f24, n f26, fy f28, fx kept in f12) and the game's -O2-style scheduling; the 5th param
 * must stay in its home slot until use (X2: `const f32 &ff = f` does that). The D_800DE524 if/else is a fakematch
 * shape: both arms are 0.5f, GCC folds the read away (no load emitted), and dropping it lowers the ratio to 0.377. */
#include "common.h"

extern "C" f32 func_80001CA0(f32);
extern "C" f32 func_800018C0(f32);
extern "C" void func_800A4418(void *, f32, f32, f32, f32, f32, f32);
extern s32 D_800DE524;

extern "C" void func_800A4350(void *m, f32 fx, f32 fy, f32 n, f32 f) {
    f32 k;
    f32 a;
    f32 x;
    f32 y;

    if (D_800DE524 != 0) {
        k = 0.5f;
    } else {
        k = 0.5f;
    }
    a = fx * k;
    {
        f32 s = func_80001CA0(a);
        x = s / func_800018C0(a) * n;
    }
    a = fy * k;
    {
        f32 s = func_80001CA0(a);
        y = s / func_800018C0(a) * n;
    }
    func_800A4418(m, -x, x, -y, y, n, f);
}
