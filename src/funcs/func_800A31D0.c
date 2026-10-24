/* cflags: -O2 */
#include "common.h"

s32 func_8000B470(void *, void *, s32);
s32 func_8000C900(void *, void *, s32);
void func_800A059C(u8 *);
void func_800A05D8(u8 *);

s32 func_800A31D0(u8 *arg0, s32 arg1) {
    u8 buf[0x68];
    s32 r = 0;

    func_800A059C(arg0);
    if (func_8000B470(arg0 + 0x3EC, buf, *(s32 *)(arg0 + 0x434)) == 10) {
        r = func_8000C900(arg0 + 0x3EC, buf, arg1) == 0;
    }
    func_800A05D8(arg0);
    return r;
}
