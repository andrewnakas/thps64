#include "common.h"

extern u8 D_8001E388[];
extern u8 D_8001E320[];
extern s32 D_800DE520;

u8 *func_8007E1C4(u8 *a0) {
    *(void **)(a0 + 0x44) = D_8001E388;
    a0[0x3C] = 1;
    a0[0x3D] = 1;
    a0[0x3E] = 1;
    D_800DE520++;
    *(void **)(a0 + 0x44) = D_8001E320;
    *(s32 *)(a0 + 0x90) = 0x2C808080;
    return a0;
}
