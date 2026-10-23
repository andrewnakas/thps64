/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80025174;

typedef struct {
    u8 pad0[0x40];
    u8 unk40[0x48];
    u8 unk88;
    u8 pad89[3];
} Item80025174;

typedef struct {
    u8 pad0[4];
    Item80025174 items[(0x474 - 4) / 0x8C];
    u8 pad[0x474 - 4 - ((0x474 - 4) / 0x8C) * 0x8C];
    u8 unk474;
    u8 unk475;
} Obj80025174;

extern Gfx80025174 *D_800F36A4;
extern void *D_800D27A0;
extern u8 D_800D2760[];
void func_800B9DE0(void *);
void func_800C000C(void *);

void func_80025174(Obj80025174 *arg0) {
    s32 i;
    s32 a;
    s32 last;
    Item80025174 *e;

    last = -1;
    func_800B9DE0(D_800D27A0);
    {
        Gfx80025174 *_g = (Gfx80025174 *)(D_800F36A4++);
        _g->w0 = 0xE200001C;
        _g->w1 = 0x0C184240;
    }
    i = 0;
    while (1) {
        if (i >= arg0->unk475) {
            break;
        }
        e = &arg0->items[i];
        func_800C000C(e->unk40);
        a = arg0->unk474;
        if (e->unk88 != 0) {
            a /= 4;
        }
        if (a != last) {
            Gfx80025174 *_g = (Gfx80025174 *)(D_800F36A4++);
            _g->w0 = 0xFA000000;
            _g->w1 = (a & 0xFF) | 0x64000000;
            last = a;
        }
        {
            Gfx80025174 *_g = (Gfx80025174 *)(D_800F36A4++);
            _g->w0 = 0x01004008;
            _g->w1 = (u32)D_800D2760;
        }
        {
            Gfx80025174 *_g = (Gfx80025174 *)(D_800F36A4++);
            _g->w0 = 0x06000402;
            _g->w1 = 0x604;
        }
        i++;
    }
}
