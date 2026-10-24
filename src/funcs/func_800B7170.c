/* cflags: -O2 */
#include "common.h"

extern void func_8009ECF8(void *, s32);
extern void func_8009E334(void *);
extern u8 D_800EA110[];

void func_800B7170(s32 *a0, s32 a1) {
    if (a0[3] != 0) {
        func_8009ECF8(D_800EA110, a0[0]);
    }
    if (a1 & 1) {
        func_8009E334(a0);
    }
}
