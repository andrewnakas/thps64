/* cflags: -O2 */
#include "common.h"

void func_800A03C8(void *, s32 *);
void func_800B25BC(s32 *, s32);
void func_800BC0F4(void *);
extern u8 D_800F0DD0[];

void func_800B272C(u8 *arg0, s32 *arg1) {
    if (--*arg1 == 0) {
        func_800BC0F4(D_800F0DD0);
        func_800A03C8(arg0 + 0x38, arg1);
        if (arg1 != NULL) {
            func_800B25BC(arg1, 3);
        }
    }
}
