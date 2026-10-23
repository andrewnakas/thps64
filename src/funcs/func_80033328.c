#include "common.h"

void func_800B1AC4(void *, f32, f32, f32, f32);

typedef struct {
    u8 pad0[0x48];
    u8 n0;
    u8 n1;
    u8 pad4A[0x534 - 0x4A];
    u8 obj[4];
} S80033328;

void func_80033328(S80033328 *arg0) {
    s32 i;
    s32 x0;
    s32 x1;

    x0 = 0xD4;
    x1 = 0x1CC;
    for (i = 0; i < arg0->n0; i++) {
        func_800B1AC4(arg0->obj, (f32) x0, 382.0f, 1.0f, 1.0f);
        x0 += 0xE;
    }
    for (i = 0; i < arg0->n1; i++) {
        func_800B1AC4(arg0->obj, (f32) x1, 382.0f, 1.0f, 1.0f);
        x1 += 0xE;
    }
}
