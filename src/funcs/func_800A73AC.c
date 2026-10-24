/* cflags: -O2 */
#include "common.h"

extern void func_800BAC04(void *, s32);
extern u8 D_800EECF0[];

void func_800A73AC(u8 *a0) {
    if (*(s32 *)(a0 + 0x22C) != 0) {
        func_800BAC04(D_800EECF0, *(s32 *)(a0 + 0x14));
        *(s32 *)(a0 + 0x22C) = 0;
    }
}
