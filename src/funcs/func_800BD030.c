#include "common.h"

extern void func_80011010(void *);

void func_800BD030(u8 *a0) {
    if (*(s32 *)(a0 + 0x2314) == 0) {
        *(s32 *)(a0 + 0x25C) = *(s32 *)(a0 + 0x264);
        func_80011010(a0);
    }
}
