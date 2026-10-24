/* cflags: -O2 */
#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    u32 w0;
    u32 w1;
} AcmdF160;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x10 - 0x8];
    s32 unk10;
} BookF160;

typedef struct {
    u8 pad0[0x14];
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    BookF160 *unk20;
    s32 unk24;
    u8 pad28[0x30 - 0x28];
    u32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} StF160;

AcmdF160 *func_800AF720(AcmdF160 *, StF160 *, s32, s32, s16, s16, s32);

AcmdF160 *func_800AF160(void *filter, s16 *outp, s32 outCount, AcmdF160 *p) {
    AcmdF160 *ptr = p;
    s16 inp;
    s32 tsam;
    s32 nframes;
    s32 nbytes;
    s32 overFlow;
    s32 startZero;
    s32 nSam;
    s32 op;
    s32 bEnd;
    s32 nOver;
    s32 nLeft;
    s32 decoded = 0;
    s32 looped = 0;
    StF160 *f = (StF160 *)filter;

    if (outCount == 0) {
        return ptr;
    }
    inp = 0;
    {
        AcmdF160 *_a = ptr++;

        _a->w0 = (f->unk24 & 0xFFFFFF) | 0x0B000000;
        _a->w1 = (f->unk20->unk10 + 8) & 0x1FFFFFFF;
    }
    looped = (outCount + f->unk30 > f->unk18) && (f->unk1C != 0);
    if (looped) {
        nSam = f->unk18 - f->unk30;
    } else {
        nSam = outCount;
    }
    if (f->unk34) {
        nLeft = 16 - f->unk34;
    } else {
        nLeft = 0;
    }
    tsam = nSam - nLeft;
    if (tsam < 0) {
        tsam = 0;
    }
    nframes = (tsam + 15) >> 4;
    nbytes = nframes * 9;
    if (looped) {
        ptr = func_800AF720(ptr, f, tsam, nbytes, *outp, inp, f->unk38);
        if (f->unk34) {
            *outp += f->unk34 << 1;
        } else {
            *outp += 16 << 1;
        }
        f->unk34 = f->unk14 & 0xF;
        f->unk3C = f->unk20->unk0 + 9 * ((s32)(f->unk14 >> 4) + 1);
        f->unk30 = f->unk14;
        bEnd = *outp;
        while (outCount > nSam) {
            op = (bEnd + ((nframes + 1) << 5) + 0x10) & ~0x1F;
            bEnd += nSam << 1;
            outCount -= nSam;
            if (f->unk1C != -1 && f->unk1C != 0) {
                f->unk1C--;
            }
            nSam = MIN(outCount, f->unk18 - f->unk14);
            tsam = nSam - 16 + f->unk34;
            if (tsam < 0) {
                tsam = 0;
            }
            nframes = (tsam + 15) >> 4;
            nbytes = nframes * 9;
            ptr = func_800AF720(ptr, f, tsam, nbytes, op, inp, f->unk38 | 2);
            {
                AcmdF160 *_a = ptr++;

                _a->w0 = ((op + (f->unk34 << 1)) & 0xFFFFFF) | 0x0A000000;
                _a->w1 = (bEnd << 16) | ((nSam << 1) & 0xFFFF);
            }
        }
        f->unk34 = (outCount + f->unk34) & 0xF;
        f->unk30 += outCount;
        f->unk3C += 9 * nframes;
        return ptr;
    }
    nSam = nframes << 4;
    overFlow = f->unk3C + nbytes - ((s32)f->unk20->unk0 + f->unk20->unk4);
    if (overFlow < 0) {
        overFlow = 0;
    }
    nOver = (overFlow / 9) << 4;
    if (nOver > nSam + nLeft) {
        nOver = nSam + nLeft;
    }
    nbytes -= overFlow;
    if (nOver - (nOver & 0xF) < outCount) {
        decoded = 1;
        ptr = func_800AF720(ptr, f, nSam - nOver, nbytes, *outp, inp, f->unk38);
        if (f->unk34) {
            *outp += f->unk34 << 1;
        } else {
            *outp += 16 << 1;
        }
        f->unk34 = (outCount + f->unk34) & 0xF;
        f->unk30 += outCount;
        f->unk3C += 9 * nframes;
    } else {
        f->unk34 = 0;
        f->unk3C += 9 * nframes;
    }
    if (nOver) {
        f->unk34 = 0;
        if (decoded) {
            startZero = (nLeft + nSam - nOver) << 1;
        } else {
            startZero = 0;
        }
        {
            AcmdF160 *_a = ptr++;

            _a->w0 = ((startZero + *outp) & 0xFFFFFF) | 0x02000000;
            _a->w1 = nOver << 1;
        }
    }
    return ptr;
}
