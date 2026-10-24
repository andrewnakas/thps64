/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: documentation only, never a match: uses GCC inline asm (gte_mfc2_*) for the three PSX GTE reads
 * (mfc2 $25/$26/$27), which src/funcs does not allow. Structural ratio 0.758 (immediates masked): s-reg rotation
 * (count in s3 not s2), the game reads the three MACs into t0-t2 (one PSY-Q-style asm block), loop shapes differ. */
/* Leftover from the PlayStation original: after func_80042D1C (the port's software stand-in for a GTE
 * interpolate op, it updates D_800D48AC[3] and D_800D48A4[3]) the code still reads GTE data registers 25-27
 * (MAC1..MAC3) with mfc2 instead of the software results. On the VR4300 these read the COP2 latch, not the
 * interpolated vector; the helpers keep that exact behaviour. Picks the keyframe pair for the object's current
 * frame (s16 at 0x21C) in a block of `n` frames, copies `count` 6-byte vectors into D_800D7450[idx] directly when
 * the blend factor is 0, else blends via func_8004342C/func_80042D1C. */
#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s8005D0B0;

extern u8 D_800D7450[]; /* 0x18-byte entries */
void func_8004342C(s32);
void func_80042D1C(void);

/* GTE data register 25: MAC1 (accumulator X) */
static inline s32 gte_mfc2_mac1(void) {
    s32 v;
    __asm__ volatile("mfc2 %0, $25" : "=r"(v));
    return v;
}

/* GTE data register 26: MAC2 (accumulator Y) */
static inline s32 gte_mfc2_mac2(void) {
    s32 v;
    __asm__ volatile("mfc2 %0, $26" : "=r"(v));
    return v;
}

/* GTE data register 27: MAC3 (accumulator Z) */
static inline s32 gte_mfc2_mac3(void) {
    s32 v;
    __asm__ volatile("mfc2 %0, $27" : "=r"(v));
    return v;
}

void func_8005D0B0(s32 count, s32 n, u8 *nodes, u8 *obj, s32 idx, s32 h) {
    u8 *node;
    u8 *data;
    Vec3s8005D0B0 *src;
    Vec3s8005D0B0 *dst;
    s32 x;
    s32 y;
    s32 z;
    s32 total;
    s32 frame;
    s32 lo;
    s32 hi;
    s32 t;
    s32 num;
    s32 den;
    s32 i;

    node = nodes + *(u16 *)(obj + 0x21E) * 8;
    total = *(u16 *)(node + 0xA);
    data = nodes + *(s32 *)(node + 4);
    frame = *(s16 *)(obj + 0x21C);
    lo = frame - frame % n;
    hi = lo + n;
    if (hi < total) {
        num = frame - lo;
        den = hi - lo;
    } else if (obj[0x220] == 1) {
        num = frame - lo;
        den = total - lo;
    } else {
        lo -= n;
        if (lo < 0) {
            lo = 0;
        }
        hi -= n;
        num = frame - lo;
        if (hi == 0) {
            t = 0;
            goto have_t;
        }
        den = hi - lo;
    }
    t = (num << 12) / den;
have_t:
    dst = (Vec3s8005D0B0 *)(D_800D7450 + idx * 0x18);
    src = (Vec3s8005D0B0 *)(data + (h * lo / n) * 0x18 + idx * 0x18);
    if (t == 0) {
        for (i = 0; i < count; i++) {
            *dst = *src; /* 6-byte struct copy: lwl/lwr + lh, swl/swr + sh */
            src++;
            dst++;
        }
    } else {
        func_8004342C(t);
        for (i = 0; i < count; i++) {
            func_80042D1C();
            x = gte_mfc2_mac1();
            y = gte_mfc2_mac2();
            z = gte_mfc2_mac3();
            dst->x = x;
            dst->y = y;
            dst->z = z;
            dst++;
        }
    }
}
