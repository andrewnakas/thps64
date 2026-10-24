/* cflags: -O2 */
#include "common.h"

extern u8 *D_800ECC34;

s32 *func_800B0208(void) {
    u8 *m = D_800ECC34;
    s32 *p = *(s32 **)(m + 0x40);
    s32 *r = NULL;
    if (p != NULL) {
        r = p;
        *(s32 *)(m + 0x40) = *r;
        *r = 0;
    }
    return r;
}
