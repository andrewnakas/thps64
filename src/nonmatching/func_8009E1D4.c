/* NON_MATCHING: difflib ratio 0.689 (scheduling and register choice only). libc memmove: copies 8 bytes at a time (as two words) when dst and n are both
 * 8-aligned (src is not checked), choosing the direction from dst < src, then the remaining bytes the same way.
 * Like func_8009E0F0 the game's libc came from a different compiler: its loop and register shapes (t0/t1 copies,
 * a1 reused as the source pointer, unfilled final `jr $ra; nop`) do not come out of our cc1. */
#include "common.h"

void *func_8009E1D4(void *dst, void *src, u32 n) {
    u8 *d;
    u8 *s;
    u64 *dq;
    u64 *sq;
    u32 rem;

    if (n == 0) {
        return dst;
    }
    d = dst;
    s = src;
    if (n >= 8 && !(((u32)dst | n) & 7)) {
        dq = (u64 *)d;
        sq = (u64 *)s;
        rem = n & 7;
        n >>= 3;
        if (dst < src) {
            do {
                *dq++ = *sq++;
            } while (--n != 0);
        } else {
            dq = (u64 *)((u8 *)dst + (n * 8 - 8));
            sq = (u64 *)((u8 *)src + (n * 8 - 8));
            do {
                *dq-- = *sq--;
            } while (--n != 0);
        }
        d = (u8 *)dq;
        s = (u8 *)sq;
        n = rem;
    }
    if (n == 0) {
        return dst;
    }
    if (d < s) {
        do {
            *d++ = *s++;
        } while (--n != 0);
        return dst;
    }
    d += n - 1;
    s += n - 1;
    do {
        *d-- = *s--;
    } while (--n != 0);
    return dst;
}
