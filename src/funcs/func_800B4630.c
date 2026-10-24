/* cflags: -O2 */
#include "common.h"

void func_800B7160(u8 *, s32);
u8 *func_800B2860(u8 *);

static __inline__ void clear_800B4630(u8 *p) {
    *(s32 *)(p + 0x8) = 0;
    *(s32 *)(p + 0x3C) = 0;
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x1CA0) = 0;
    *(s32 *)(p + 0x1C9C) = 0;
    *(s32 *)(p + 0x1C98) = 0;
    *(s32 *)(p + 0x188C) = 0;
    *(s32 *)(p + 0x80) = 0;
}

u8 *func_800B4630(u8 *arg0) {
    func_800B7160(arg0, 0);
    func_800B2860(arg0 + 0xC);
    clear_800B4630(arg0);
    return arg0;
}
