/* cflags: -O2 */
#include "common.h"

void func_800A01E0(u8 *arg0) {
    u32 *p;
    s32 n;
    s32 i;

    p = *(u32 **)(arg0 + 0x1B0);
    n = *(u32 *)(arg0 + 0x1B4) >> 2;
    for (i = 0; i < n; i++) {
        if (*p != 0xDBDBDBDB) {
            break;
        }
        p++;
    }
}
