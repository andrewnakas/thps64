#include "common.h"

extern u8 D_8001E388[];
extern s32 D_800DE520;

u8 *func_8007E598(u8 *a0) {
    *(void **)(a0 + 0x44) = D_8001E388;
    a0[0x3C] = 1;
    a0[0x3D] = 1;
    a0[0x3E] = 1;
    D_800DE520++;
    return a0;
}
