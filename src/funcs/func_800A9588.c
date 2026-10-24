/* cflags: -O2 */
#include "common.h"

extern s32 func_800A9D64(s32 *, s32);
extern void func_800ABE14(s32, s32);

s32 func_800A9588(s32 *arg0, s32 arg1) {
    u8 *p;

    if (*arg0 == 0 || func_800A9D64(arg0, arg1) == 0) {
        return 0;
    }
    p = (u8 *)arg0;
    p += arg1 * 0x24;
    func_800ABE14(*(s32 *)(p + 0x538), 0);
    return 1;
}
