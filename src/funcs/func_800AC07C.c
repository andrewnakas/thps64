/* cflags: -O2 */
#include "common.h"

extern s32 D_800FC2F0;
extern u8 *D_800FC2F8;

u8 *func_800AC07C(s32 arg0) {
    u8 *p;
    s32 i;

    if (arg0 == 0) {
        return NULL;
    }
    p = D_800FC2F8;
    for (i = 0; i < D_800FC2F0; i++) {
        if (*(s32 *)(p + 0x44) == arg0) {
            return p;
        }
        p += 0x130;
    }
    return NULL;
}
