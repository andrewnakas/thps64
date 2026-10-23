#include "common.h"

typedef struct {
    s32 v[8];
} Blk32_8005C864;

typedef struct {
    s32 v[3];
} Blk12_8005C864;

void func_8005C864(u8 *a0) {
    Blk12_8005C864 *d;
    Blk12_8005C864 *s;

    *(Blk32_8005C864 *)(a0 + 0x884) = *(Blk32_8005C864 *)(a0 + 0x8A4);
    d = (Blk12_8005C864 *)(a0 + 0x4);
    s = (Blk12_8005C864 *)(a0 + 0x8C4);
    *d = *s;
}
