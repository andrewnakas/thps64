/* cflags: -O2 */
#include "common.h"

extern void func_8009ECF8(void *, s32);
extern u8 D_800EA110[];

void func_800B2BAC(u8 *a0) {
    if (*(s32 *)(a0 + 8) != 0) {
        u8 *p = a0 + 0x18;
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 0x8) = 0;
        func_8009ECF8(D_800EA110, *(s32 *)(a0 + 8));
        *(s32 *)(a0 + 8) = 0;
    }
}
