/* cflags: -O2 */
#include "common.h"

s32 func_800B02E4(void);

s32 func_800B0330(void) {
    return func_800B02E4() & ~0xF;
}
