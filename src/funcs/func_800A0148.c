/* cflags: -O2 */
#include "common.h"

extern u8 *D_800EA548;

s32 func_800A0148(u8 *a0, s32 *a1, s32 *a2) {
    u8 *p = D_800EA548;
    while (p != NULL) {
        if (p == a0) {
            *a1 = *(s32 *)(p + 0x1B0);
            *a2 = *(s32 *)(p + 0x1B4);
            return 1;
        }
        p = *(u8 **)(p + 0x1C0);
    }
    return 0;
}
