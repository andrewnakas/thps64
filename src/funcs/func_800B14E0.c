/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x2];
    u16 unk2;
    u8 pad4[0x4];
    u8 unk8[0x20];
    void *unk28;
    s32 unk2C;
} Obj800B14E0;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B14E0;

extern u32 func_80003520(void *);

Gfx800B14E0 *func_800B14E0(Obj800B14E0 *arg0, s32 arg1, Gfx800B14E0 *arg2) {
    s32 seg;
    Gfx800B14E0 *g = arg2;

    seg = arg1 >> 8;
    {
        Gfx800B14E0 *_g = g++;
        _g->w0 = 0x0B000020;
        _g->w1 = func_80003520(arg0->unk8);
    }
    {
        Gfx800B14E0 *_g = g++;
        _g->w0 = (*((u8 *)arg0 + 0x2F) << 16) | 0x0E000000 | arg0->unk2;
        _g->w1 = (seg << 24) | (func_80003520(arg0->unk28) & 0xFFFFFF);
    }
    arg0->unk2C = 0;
    return g;
}
