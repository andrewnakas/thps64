#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80027F60;

typedef struct {
    u8 pad0[0x48];
    s16 off;
    u8 pad4A[2];
    void (*fn)(void *, void *, s32);
} Vt80027F60;

typedef struct {
    u8 pad0[0x48];
    Vt80027F60 *vt;
    u8 pad4C[0x1B28 - 0x4C];
    u8 unk1B28[0x2270 - 0x1B28];
    u8 unk2270[1];
} Obj80027F60;

void func_800A4DD0(void *);
void func_800A602C(void *);
extern Gfx80027F60 *D_800F36A4;

void func_80027F60(Obj80027F60 *arg0) {
    void *s1;
    Gfx80027F60 *g;

    s1 = arg0->unk1B28;
    func_800A4DD0(s1);
    g = D_800F36A4++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_800F36A4++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x100000;
    arg0->vt->fn((u8 *)arg0 + arg0->vt->off, s1, 0);
    func_800A602C(arg0->unk2270);
}
