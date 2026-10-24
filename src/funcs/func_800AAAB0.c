/* cflags: -O2 */
#include "common.h"

u8 *func_800AAAB0(u8 *arg0, u8 *arg1) {
    u8 v;

    v = *arg1++;
    arg0[0xB8] = v;
    if (v) {
        *(f32 *)(arg0 + 0x50) = *(f32 *)(arg0 + 0x2C);
    }
    return arg1;
}
