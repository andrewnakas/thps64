#include "common.h"

typedef struct {
    u8 pad0[8];
    s16 off;
    u8 padA[2];
    void (*fn)(void *, s32);
} Vt800307C4;

typedef struct {
    u8 pad0[0x48];
    Vt800307C4 *vt;
} Obj800307C4;

typedef struct {
    u8 pad0[0x2C];
    void *vtbl;
    u8 unk30[0x14];
    u8 unk44[0x14];
    u8 unk58[0x14];
    u8 unk6C[0x14];
    u8 unk80[0x2C0 - 0x80];
    u8 unk2C0[0x500 - 0x2C0];
    u8 unk500[0x7B0 - 0x500];
    Obj800307C4 *a;
    Obj800307C4 *b;
} Self800307C4;

void func_800394A8(Self800307C4 *, s32);
void func_800A735C(void *, s32);
void func_800B19C0(void *, s32);
extern u8 D_80019AD8[];

void func_800307C4(Self800307C4 *arg0, s32 arg1) {
    Obj800307C4 *o;

    arg0->vtbl = D_80019AD8;
    o = arg0->a;
    if (o != NULL) {
        o->vt->fn((void *)((s32)o + o->vt->off), 3);
    }
    o = arg0->b;
    if (o != NULL) {
        o->vt->fn((void *)((s32)o + o->vt->off), 3);
    }
    func_800A735C(arg0->unk500, 2);
    func_800A735C(arg0->unk2C0, 2);
    func_800A735C(arg0->unk80, 2);
    func_800B19C0(arg0->unk6C, 2);
    func_800B19C0(arg0->unk58, 2);
    func_800B19C0(arg0->unk44, 2);
    func_800B19C0(arg0->unk30, 2);
    func_800394A8(arg0, arg1);
}
