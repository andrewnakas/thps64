/* cflags: -O2 */
#include "common.h"

s32 func_8009E728(void *, u32, s32);
s32 func_8009EFF8(void *, s32);
void func_8009ED5C(void *, u8 *);
s32 func_8009EB54(void *, u8 *, u32);
void func_8009E1D4(s32, u8 *, u32);

s32 func_8009E5A8(void *arg0, u8 *arg1, u32 arg2, s32 arg3) {
    u32 old;
    s32 saved;
    s32 p;

    if (arg1 == NULL) {
        return func_8009E728(arg0, arg2, arg3);
    }
    old = *(s32 *)(arg1 - 0xC) - 0x1C;
    saved = func_8009EFF8(arg0, 0);
    func_8009ED5C(arg0, arg1);
    p = func_8009EB54(arg0, arg1, arg2);
    if (p == 0) {
        p = func_8009E728(arg0, arg2, arg3);
        if (p != 0) {
            func_8009E1D4(p, arg1, old < arg2 ? old : arg2);
        } else {
            func_8009EB54(arg0, arg1, old);
        }
    }
    func_8009EFF8(arg0, saved);
    return p;
}
