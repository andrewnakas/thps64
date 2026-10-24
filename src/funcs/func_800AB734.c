/* cflags: -O2 */
#include "common.h"

extern s16 D_800FC308;
extern s16 D_800FC30A;

void func_800AB734(s32 arg0, s16 arg1) {
    if (arg0 & 1) {
        D_800FC308 = arg1;
    }
    if (arg0 & 2) {
        D_800FC30A = arg1;
    }
}
