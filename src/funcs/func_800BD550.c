/* cflags: -O2 */
#include "common.h"

void func_8009ECF8(void *, s32);
void func_8009E334(s32 *);
extern u8 D_800EA110[];

void func_800BD550(s32 *arg0, s32 arg1) {
    func_8009ECF8(D_800EA110, *arg0);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
