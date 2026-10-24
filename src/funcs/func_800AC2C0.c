/* cflags: -O2 */
#include "common.h"

extern s32 D_800FC2F0;
extern u8 *D_800FC2F8;

s32 func_800AC2C0(s32 arg0) {
    u8 *p;
    s32 i;

    if (arg0 == 0) {
        return 0;
    }
    p = D_800FC2F8;
    for (i = 0; i < D_800FC2F0; i++) {
        if (*(s32 *)(p + 0x44) == arg0) {
            return *(s32 *)(p + 0x7C);
        }
        p += 0x130;
    }
    return 0;
}
