/* cflags: -O2 */
#include "common.h"

extern void func_80004ED0(s32, s32, s32);
extern void func_80005070(s32, s32, s32);
extern s32 func_8009E728(u8 *, s32, s32);

s32 func_8009E6B4(u8 *arg0, s32 arg1, s32 arg2) {
    struct { s32 q; s32 pad; } l;
    s32 r;

    l.q = *(s32 *)(arg0 + 0x14);
    func_80005070(l.q, 0, 1);
    r = func_8009E728(arg0, arg1, arg2);
    func_80004ED0(l.q, 0, 1);
    return r;

}
