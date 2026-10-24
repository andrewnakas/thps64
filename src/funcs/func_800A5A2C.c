/* cflags: -O2 */
#include "common.h"

void func_8009ECF8(void *, s32);
extern u8 D_800EA110[];

void func_800A5A2C(u8 *arg0) {
    func_8009ECF8(D_800EA110, *(s32 *)(arg0 + 8));
    *(s32 *)(arg0 + 8) = 0;
}
