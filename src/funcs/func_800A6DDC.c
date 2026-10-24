#include "common.h"

typedef struct { s32 x, y, z; } V3;

void func_800A6DDC(u8 *a0, V3 *a1) {
    *a1 = *(V3 *)(a0 + 0x70);
}
