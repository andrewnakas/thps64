#include "common.h"

extern u8 D_8001E388[];
extern u8 D_8001E368[];
extern s32 D_800DE520;

u8 *func_8007E4C8(u8 *arg0) {
    *(void **)(arg0 + 0x44) = D_8001E388;
    arg0[0x3C] = 1;
    arg0[0x3D] = 1;
    arg0[0x3E] = 1;
    D_800DE520++;
    *(void **)(arg0 + 0x44) = D_8001E368;
    return arg0;
}
