/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80025C54;

typedef struct {
    u8 pad0[0xB8];
} Item80025C54;

typedef struct {
    u8 pad0[8];
    Item80025C54 items[16];
    u8 pad[0xB88 - 8 - 16 * 0xB8];
    void *unkB88;
} Obj80025C54;

extern Gfx80025C54 *D_800F36A4;
void func_800B9DE0(void *);
void func_800A6E74(void *, s32, s32, s32, s32);

void func_80025C54(Obj80025C54 *arg0, s32 arg1) {
    s32 i;
    Gfx80025C54 *h;

    if (arg0->unkB88 != NULL) {
        func_800B9DE0(arg0->unkB88);
    }
    {
        Gfx80025C54 *_g = (Gfx80025C54 *)(D_800F36A4++);
        _g->w0 = 0xFA000000;
        _g->w1 = 0xB4B4B464;
    }
    h = D_800F36A4;
    D_800F36A4 = h + 1;
    h[0].w0 = 0xFC30B3FF;
    h[0].w1 = 0xFFFFFE38;
    D_800F36A4 = h + 2;
    h[1].w0 = 0xE200001C;
    h[1].w1 = 0x0C184A50;
    D_800F36A4 = h + 3;
    h[2].w0 = 0xD9FFFBFF;
    h[2].w1 = 0;
    i = 0;
    while (1) {
        if (i >= 16) {
            break;
        }
        func_800A6E74(&arg0->items[i], arg1, -1, 0, -1);
        i++;
    }
    {
        Gfx80025C54 *_g = (Gfx80025C54 *)(D_800F36A4++);
        _g->w0 = 0xD9FFFFFF;
        _g->w1 = 0x400;
    }
}
