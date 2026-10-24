/* cflags: -O2 */
#include "common.h"

void func_800B18A4(u8 *dst, u8 val, u32 n) {
    while (n--) {
        *dst++ = val;
    }
}
