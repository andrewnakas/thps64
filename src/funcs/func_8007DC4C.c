#include "common.h"

typedef struct { s32 a; s32 b; } Pair;

void func_8007DC4C(u8 *a0, s32 a1) {
    u32 i;
    for (i = 1; i < *(u32 *)(a0 + 0x50); i += 2) {
        (*(Pair **)(a0 + 0x48))[i].a = a1;
    }
}
