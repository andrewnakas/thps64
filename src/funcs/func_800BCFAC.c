/* cflags: -O2 */
#include "common.h"

u64 func_800BD540(void); /* extern */

void func_800BCFAC(u8 *arg0) {
    *(u64 *)(arg0 + 0x2308) = func_800BD540() - *(u64 *)(arg0 + 0x2300);
}
