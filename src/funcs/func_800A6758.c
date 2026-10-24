/* cflags: -O2 */
#include "common.h"

extern u32 func_80007400(void);
extern u32 D_800EA580;
extern s32 D_800EA584;

void func_800A6758(void) {
    u32 t;

    t = func_80007400();
    if (D_800EA580 > 0xF0000000U && t <= 0x0FFFFFFFU) {
        D_800EA584++;
    }
    D_800EA580 = t;
}
