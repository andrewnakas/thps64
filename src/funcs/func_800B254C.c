/* cflags: -O2 */
#include "common.h"

extern s32 func_8009B7D8(u8 *, u8 *, s32, s32);
extern void func_800B2848(u8 *, s32);
extern u8 D_800ECEF4[];

u8 *func_800B254C(u8 *arg0, s32 arg1) {
    u8 *p;
    s32 v;

    p = arg0 + 8;
    func_800B2848(p, 0);
    v = func_8009B7D8(D_800ECEF4, D_800ECEF4, arg1, 8);
    *(s32 *)(p + 4) = v;
    *(s32 *)(arg0 + 8) = v;
    *(s32 *)(arg0 + 4) = arg1;
    return arg0;
}
