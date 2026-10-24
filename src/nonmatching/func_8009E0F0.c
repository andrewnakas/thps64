/* NON_MATCHING: 55 vs 57 insns, difflib ratio 0.938 (6/55 by position, shifted by one insn). libc memset (fills 8 bytes at a time when dst and n are
 * both 8-aligned). Remaining diff: the game's 64-bit shift sequence branches with `bgez $zero` where our gas
 * emits `b` (the game's libc came from a different compiler/assembler; this is the only `bgez $zero` in the
 * binary), plus the game's extra andi->v0->t1 copy and its unfilled final `jr $ra; nop`
 * (we put the `move v0, a3` in the delay slot). Behaviour is identical. */
#include "common.h"

void *func_8009E0F0(void *dst, s32 c, u32 n) {
    u8 *p;
    u64 *q;
    u64 b;
    u64 v;
    u32 i;

    if (n >= 8 && !(((u32)dst | n) & 7)) {
        b = (u8)c;
        v = 0;
        for (i = 0; i < 8; i++) {
            v |= b << (i * 8);
        }
        q = dst;
        n >>= 3;
        while (n-- != 0) {
            *q++ = v;
        }
        return dst;
    }
    p = dst;
    while (n-- != 0) {
        *p++ = c;
    }
    return dst;
}
