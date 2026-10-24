/* cflags: -O2 */
#include "common.h"

f32 func_8009F2CC(void); /* extern */
extern f32 D_800EA13C[];
extern s32 D_800EA530;

void func_8009F538(void) {
    s32 i;

    for (i = 0; i < 0xFD; i++) {
        D_800EA13C[i] = func_8009F2CC();
    }
    D_800EA530 = 0;
}
