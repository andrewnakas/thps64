/* cflags: -O2 */
#include "common.h"

extern f64 func_800A67B4(void *);
extern u8 D_800EA570[];

void func_800A6520(u8 *a0) {
    if (a0[0x48] == 0) {
        *(f64 *)(a0 + 8) = func_800A67B4(D_800EA570);
    }
}
