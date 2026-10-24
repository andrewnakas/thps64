/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
/* NON_MATCHING: aln 0.612. Equivalent C, same structure region by region; only register allocation of the decoder temporaries differs (step, loop counters, bit-reader registers). */
/* Z3: K18 draft recompiled at -O2 nosched + -Wa,-no-m4100: 168/273 paired (K18 -O1 128, G5 91). Code shape matches
   region by region; left are register choices of the decoder temporaries throughout (step t5 vs t4, loop counters,
   bit-reader regs) and the last key loop's structure (regions +0x25c..+0x3ec). do-while(0) sweep: +1 at most. */
/* NEARLY func_8007E7A0 (89/275 with cflags below): structure matches; diffs are global register allocation (step t5 vs t4, next/d/i swapped among t1..t5). Needs -Wa,-no-m4100 for the mflo/mult nops. */
#include "common.h"

u8 *func_8007E7A0(u8 *src, s16 *dst, s32 stride, s32 count) {
    u32 hdr;
    s32 step;
    s32 nkeys;
    s32 rem;
    s32 tmp;
    s32 i;
    s32 j;
    s32 bits;
    s32 bitpos;
    s32 raw;
    s16 v;
    s16 next;
    s16 d;

    hdr = *src++;
    step = (hdr >> 4) + 1;
    hdr &= 0xF;
    if (step >= 2) {
        nkeys = (count - 1) / step;
        tmp = nkeys * step + 1;
        rem = count - tmp;
    } else {
        nkeys = count - 1;
        rem = 0;
    }
    switch ((u8)hdr) {
    case 0:
        v = *src++;
        v += *src++ << 8;
        *dst = v;
        dst += stride;
        i = 0;
        while (1) {
            if (i >= nkeys) {
                break;
            }
            next = *src++;
            next += *src++ << 8;
            d = (next - v) / step;
            for (j = 0; j < step - 1; j++) {
                v += d;
                *dst = v;
                dst += stride;
            }
            v = next;
            *dst = v;
            dst += stride;
            i++;
        }
        if (rem != 0) {
            next = *src++;
            next += *src++ << 8;
            d = (next - v) / rem;
            for (j = 0; j < rem - 1; j++) {
                v += d;
                *dst = v;
                dst += stride;
            }
            *dst = next;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        bits = hdr + 1;
        v = *src++;
        v += *src++ << 8;
        *dst = v;
        dst += stride;
        bitpos = 0;
        i = 0;
        while (1) {
            if (i >= nkeys) {
                break;
            }
            raw = (s32)(((((src[0] << 8) | src[1]) << 8) | src[2]) << (bitpos + 8)) >> (32 - bits);
            next = v + raw;
            bitpos += bits;
            src += bitpos >> 3;
            bitpos &= 7;
            d = raw / step;
            for (j = 0; j < step - 1; j++) {
                v += d;
                *dst = v;
                dst += stride;
            }
            v = next;
            *dst = v;
            dst += stride;
            i++;
        }
        if (rem != 0) {
            raw = (s32)(((((src[0] << 8) | src[1]) << 8) | src[2]) << (bitpos + 8)) >> (32 - bits);
            next = v + raw;
            bitpos += bits;
            src += bitpos >> 3;
            bitpos &= 7;
            d = raw / rem;
            for (j = 0; j < rem - 1; j++) {
                v += d;
                *dst = v;
                dst += stride;
            }
            *dst = next;
        }
        if (bitpos != 0) {
            src++;
        }
        break;
    case 14:
        v = *src++;
        v += *src++ << 8;
        for (i = 0; i < count; i++) {
            *dst = v;
            dst += stride;
        }
        break;
    case 15:
        for (i = 0; i < count; i++) {
            *dst = 0;
            dst += stride;
        }
        break;
    }
    return src;
}
