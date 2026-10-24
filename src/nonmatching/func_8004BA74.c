/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: combine puts subreg(step) first in cur+step; best 85/88, was 82. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* Z1 near-miss 85/88 (was 82): the three channels as a block macro (c, tgt, s loaded in statement order fixes the
 * load order). Left: `addu v0, a3(step), v1(cur)` vs game `v1, a3` in each channel: combine canonicalises
 * (plus (reg zext(cur), CSE'd from the compare) (zero_extend step)) by swapping the non-object operand first (subreg
 * step). The game's cur must be the folded operand and step a plain reg (its zext computed in another block);
 * compare on c / (u8)c, step/cur types and operand orders (36 combos, t/ba74.py) do not give it. */
#include "common.h"

static __inline__ s32 pack(s32 c, s32 t) {
    return c | t;
}

#define APPROACH(o, ot) \
    { \
        s32 c = arg0[o]; \
        s32 tgt = arg0[ot]; \
        s32 s = arg0[0x972]; \
        u8 cur = c; \
        u8 step = s; \
        s32 r; \
        s32 f; \
        if (cur < tgt) { \
            r = cur + step; \
            f = tgt < r; \
        } else { \
            r = c - s; \
            f = r < tgt; \
        } \
        if (f) { \
            r = tgt; \
        } \
        arg0[o] = r; \
    }

void func_8004BA74(u8 *arg0) {
    u8 c;
    u8 t;
    u8 s;

    APPROACH(0x96C, 0x96F);
    APPROACH(0x96D, 0x970);
    APPROACH(0x96E, 0x971);
    if (arg0[0x96C] == arg0[0x96F] && ((*(u32 *)(arg0 + 0x96C) >> 8) & 0xFFFF) == *(u16 *)(arg0 + 0x970) && arg0[0x973] != 0) {
        arg0[0x96F] = 0;
        arg0[0x970] = 0;
        arg0[0x971] = 0;
        arg0[0x972] = arg0[0x973];
        arg0[0x973] = 0;
    }
    if ((arg0[0x96C] | arg0[0x96D] | arg0[0x96E]) != 0) {
        *(s32 *)(arg0 + 0x118) = pack(arg0[0x96C], (arg0[0x96D] << 8) | 0x02000000) | (arg0[0x96E] << 16);
        *(s16 *)(arg0 + 0x11C) = 0x2000;
        *(s16 *)(arg0 + 0x11E) = 0xA;
    } else {
        *(s32 *)(arg0 + 0x118) = 0;
    }
}
