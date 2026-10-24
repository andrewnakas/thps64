/* cflags: -O2 */
#include "common.h"

void func_800A68E8(u8 *);

u8 *func_800A68A0(u8 *arg0) {
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x0) = 0;
    *(s32 *)(arg0 + 0x7C) = 0;
    arg0[0x80] = 0;
    *(u8 **)(arg0 + 0x6C) = arg0 + 0x28;
    *(u8 **)(arg0 + 0x68) = arg0 + 0x28;
    func_800A68E8(arg0);
    return arg0;
}
