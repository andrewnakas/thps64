/* cflags: -O2 */
#include "common.h"

s64 func_800BD540(void);

void func_800BCF80(u8 *arg0) {
    *(s64 *)(arg0 + 0x2300) = func_800BD540();
}
