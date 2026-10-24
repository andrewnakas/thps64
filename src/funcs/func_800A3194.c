/* cflags: -O2 */
#include "common.h"

extern void func_8009ECF8(void *, s32);
extern u8 D_800EA110[];

void func_800A3194(u8 *a0) {
    if (*(s32 *)(a0 + 0x4B4) != 0) {
        func_8009ECF8(D_800EA110, *(s32 *)(a0 + 0x4B4));
        *(s32 *)(a0 + 0x4B4) = 0;
    }
}
