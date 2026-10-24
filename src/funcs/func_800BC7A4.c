/* cflags: -O2 */
#include "common.h"

s32 func_80005070(s32, s32, s32); /* extern */

void func_800BC7A4(u8 *arg0, s32 arg1) {
    s32 n;

    n = *(s32 *)(arg0 + 0x1CC);
    (*(s32 **)(arg0 + 0x1C8))[n] = arg1;
    *(s32 *)(arg0 + 0x1CC) = n + 1;
    if (*(s32 *)(arg0 + 0x2314) != 0) {
        func_80005070(arg1, 4, 0);
    }
}
