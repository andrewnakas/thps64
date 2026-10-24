/* cflags: -O2 */
#include "common.h"

extern s32 D_800EA550;

void func_800A1174(u8 *a0, s32 a1, s32 a2) {
    D_800EA550 = 1;
    *(s32 *)(a0 + 0x0) = 10;
    *(s32 *)(a0 + 0x418) = a2;
    *(s32 *)(a0 + 0x434) = a1;
    *(s32 *)(a0 + 0x14) = 0;
    *(s32 *)(a0 + 0x464) = 1;
}
