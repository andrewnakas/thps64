/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u32 *ptr;
    u32 bits;
    s32 avail;
} BitReader;

s32 func_8006A454(BitReader *br, s32 n) {
    s32 avail;
    s32 rest;
    u32 v;
    u32 r;

    if (br->avail == 0) {
        br->bits = *br->ptr++;
        br->avail = 32;
    }
    avail = br->avail;
    if (avail >= n) {
        br->avail = avail - n;
        v = br->bits & ((1 << n) - 1);
        br->bits >>= n;
    } else {
        v = br->bits & ((1 << avail) - 1);
        rest = n - avail;
        br->bits = *br->ptr++;
        v |= (br->bits & ((1 << rest) - 1)) << br->avail;
        br->bits >>= rest;
        br->avail = 32 - rest;
    }
    r = v;
    if (r & (1 << (n - 1))) {
        r |= -(1 << n);
    }
    return r;
}
