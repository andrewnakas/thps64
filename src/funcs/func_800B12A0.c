/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd;

typedef struct {
    u8 pad0[0x14];
    s16 *base;
    u8 pad18[4];
    s32 length;
} Ring;

u32 func_80003520(void *);

#define aSaveBuffer_(pkt, c, d, s)                                                  \
    {                                                                               \
        Acmd *_a = (Acmd *)pkt;                                                     \
        _a->w0 = (4 << 24) | (((c) & 0xFFF) << 12) | ((d) & 0xFFF);                 \
        _a->w1 = (u32)(s);                                                          \
    }

Acmd *func_800B12A0(Ring *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p) {
    Acmd *ptr = p;
    s32 after_end, before_end;
    s16 *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];
    if (curr_ptr < r->base) {
        curr_ptr += r->length;
    }
    updated_ptr = curr_ptr + count;
    if (updated_ptr > delay_end) {
        before_end = delay_end - curr_ptr;
        after_end = updated_ptr - delay_end;
        aSaveBuffer_(ptr++, before_end << 1, buff, func_80003520(curr_ptr));
        aSaveBuffer_(ptr++, after_end << 1, buff + (before_end << 1), func_80003520(r->base));
    } else {
        aSaveBuffer_(ptr++, count << 1, buff, func_80003520(curr_ptr));
    }
    return ptr;
}
