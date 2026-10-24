/* cflags: -O2 */
#include "common.h"

s32 func_8009BC18(s32 *, s32);                          /* extern */
s32 func_800B9DE0(s32);                               /* extern */

void func_8009BBD8(s32 *arg0, s32 arg1) {
    func_800B9DE0(*arg0);
    func_8009BC18(arg0, arg1);
}
