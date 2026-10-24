/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd;

typedef struct {
    u8 pad0[0xC];
    u32 unkC;
    u32 unk10;
    u8 pad14[0x14];
    s32 (*dma)(s32, s32, s32);
    s32 unk2C;
    u8 pad30[8];
    s32 unk38;
    s32 unk3C;
} Dec;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))

Acmd *func_800AF720(Acmd *ptr, Dec *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags) {
    s32 dramAlign;
    s32 dramLoc;

    if (nbytes > 0) {
        dramLoc = f->dma(f->unk3C, nbytes, f->unk2C);
        dramAlign = dramLoc & 0x7;
        nbytes += dramAlign;
        {
            Acmd *_a = ptr++;
            _a->w0 = _SHIFTL(4, 24, 8) | _SHIFTL(nbytes + 8 - (nbytes & 0x7), 12, 12) | _SHIFTL(inp, 0, 12);
            _a->w1 = (u32)(dramLoc - dramAlign);
        }
    } else {
        dramAlign = 0;
    }
    if (flags & 2) {
        Acmd *_a = ptr++;
        _a->w0 = _SHIFTL(0x0F, 24, 8);
        _a->w1 = (u32)(f->unk10 & 0x1FFFFFFF);
    }
    {
        Acmd *_a = ptr++;
        _a->w0 = _SHIFTL(1, 24, 8) | _SHIFTL(f->unkC, 0, 24);
        _a->w1 = _SHIFTL(flags, 28, 4) | _SHIFTL(tsam << 1, 16, 12) | _SHIFTL(dramAlign, 12, 4) | _SHIFTL(outp, 0, 12);
    }
    f->unk38 = 0;
    return ptr;
}
