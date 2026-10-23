#include "common.h"

typedef struct {
    u8 pad0[0x40];
    u8 unk40;
    u8 unk41;
    u8 pad42[0x2A0 - 0x42];
    u8 unk2A0[0x14];
    u8 unk2B4[0x14];
} Obj80028F10;

extern void func_800B1AC4(void *, f32, f32, f32, f32);

void func_80028F10(Obj80028F10 *o) {
    s32 i;
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;
    s32 step;
    f32 f;

    x1 = 0xE5;
    y1 = 0xCC;
    x2 = x1;
    y2 = 0x11C;
    step = 0x19;
    for (i = 0; i < o->unk41; i++) {
        func_800B1AC4(o->unk2A0, x1, y1, 1.2501720190048218f, 1.0f);
        x1 += step;
    }
    for (i = 0; i < o->unk40; i++) {
        func_800B1AC4(o->unk2B4, x2, y2, 1.2501720190048218f, 1.0f);
        x2 += step;
    }
}
