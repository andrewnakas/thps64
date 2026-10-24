#include "common.h"

typedef struct {
    u8 pad0[0x48];
    s16 unk48;
    u8 pad4A[0xB0 - 0x4A];
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
} Obj;

#define PACK(r, g, b) ((((b) & 0xFF) << 16) | (((g) & 0xFF) << 8) | ((r) & 0xFF))

void func_8007E050(Obj *arg0, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2) {
    arg0->unkB0 = PACK(r0, g0, b0);
    arg0->unkB4 = PACK(r1, g1, b1);
    arg0->unkB8 = PACK(r2, g2, b2);
    arg0->unk48 = 1;
}
