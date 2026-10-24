/* cflags: -O2 */
#include "common.h"

extern void func_8009B6C0(s32 *);
extern s32 func_8009B6F4(s32 *);
extern s32 func_800B2AE4(s32 *, s32, s32, s32, s32);

s32 func_8009B650(s32 *arg0, s32 arg1) {
    func_8009B6C0(arg0);
    if (func_800B2AE4(arg0 + 3, arg1, 0, 1, 1) == 0) {
        return 0;
    }
    arg0[0] = arg0[2] = func_8009B6F4(arg0);
    arg0[1] = 0;
    return arg0[2] != 0;

}
