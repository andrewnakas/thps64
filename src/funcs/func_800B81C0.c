/* cflags: -O2 */
#include "common.h"

u8 *func_800B81C0(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x54) = 0;
    *(s32 *)(arg0 + 0x58) = 0;
    *(s32 *)(arg0 + 0x50) = 0;
    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0x7C) = 0;
    *(s32 *)(arg0 + 0x78) = 0;
    *(s8 *)(arg0 + 0x4D) = 0;
    *(u16 *)(arg0 + 0x66) = 0xFFFF;
    return arg0;
}
