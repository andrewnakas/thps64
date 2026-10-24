/* cflags: -O2 */
#include "common.h"

extern s32 func_800B7580(u8 *);

u8 *func_800B75DC(u8 *a0) {
    if (func_800B7580(a0) != 0) {
        return a0 + 0xC;
    }
    return NULL;
}
