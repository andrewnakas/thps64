/* cflags: -O2 */
#include "common.h"

extern u32 *D_800F36A4;

void func_800B9D48(u8 *a0) {
    u32 *h = D_800F36A4;
    u32 b;
    h[0] = *(u32 *)(a0 + 0x68);
    b = *(u32 *)(a0 + 0x6C);
    D_800F36A4 = h + 2;
    h[1] = b;
}
