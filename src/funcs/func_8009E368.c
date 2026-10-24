/* cflags: -O2 */
#include "common.h"

extern void func_8009E334(s32);
extern s32 D_800EA124;

void func_8009E368(void) {
    if (D_800EA124 != 0) {
        func_8009E334(D_800EA124);
    }
}
