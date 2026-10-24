/* cflags: -O2 */
#include "common.h"

s32 func_80004ED0(s32, s32 *, s32);                     /* extern */

s32 func_800BAF94(s32 arg0) {
    s32 sp10;

    func_80004ED0(arg0 + 0x1DE0, &sp10, 1);
    return sp10;
}
