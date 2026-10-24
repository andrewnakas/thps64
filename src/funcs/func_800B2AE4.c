/* cflags: -O2 */
#include "common.h"

s32 func_80004ED0(s32 *, s32, s32); /* extern */
s32 func_80005070(s32 *, s32, s32); /* extern */
s32 func_800A59E0(void *, s32);                 /* extern */
s32 func_800B2BAC(void *);                      /* extern */
s32 func_800B2BF4(s32, void *, void *, s32);    /* extern */
extern s32 D_800ECF54;

s32 func_800B2AE4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_s0;

    if (arg3 != 0) {
        func_80005070(&D_800ECF54, 0, 1);
    }
    var_s0 = 1;
    (*(s32 *)((u8 *)arg0 + 0x28)) = arg3;
    (*(s32 *)((u8 *)arg0 + 0)) = arg2;
    func_800B2BAC(arg0);
    if (arg3 == 0) {
        var_s0 = func_800B2BF4(arg4, arg0 + 0x18, arg0 + 8, 0) != 0;
    }
    if ((var_s0 != 0) && (func_800A59E0(arg0 + 0xC, arg1) == 0)) {
        var_s0 = 0;
    }
    if (arg3 != 0) {
        func_80004ED0(&D_800ECF54, 0, 1);
    }
    return var_s0;
}
