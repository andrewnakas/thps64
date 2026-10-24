#include "common.h"

s32 func_80049D60(s32);

typedef struct {
    u8 pad0[0xAC];
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
} Obj;

void func_8007DD50(Obj *arg0, u8 r, u8 g, u8 b) {
    s32 k;

    arg0->unkAC = (b << 16) | (g << 8) | r;
    k = func_80049D60(0x1000);
    arg0->unkB0 = ((b * k >> 12) << 16) | ((g * k >> 12) << 8) | (r * k >> 12);
    k = func_80049D60(0x1000);
    arg0->unkB4 = ((b * k >> 12) << 16) | ((g * k >> 12) << 8) | (r * k >> 12);
    k = func_80049D60(0x1000);
    arg0->unkB8 = ((b * k >> 12) << 16) | ((g * k >> 12) << 8) | (r * k >> 12);
}
