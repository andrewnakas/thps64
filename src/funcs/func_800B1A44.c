/* cflags: -O2 */
#include "common.h"

extern void func_800B272C(void *, s32);
extern u8 D_800ECEF4[];

void func_800B1A44(s32 *a0) {
    if (*a0 != 0) {
        func_800B272C(D_800ECEF4, *a0);
        *a0 = 0;
    }
}
