/* cflags: -O2 */
#include "common.h"

extern void func_800A5FD0(void *, s32);
extern void func_800A735C(void *, s32);
extern void func_8009E334(void *);

void func_8009BD18(u8 *a0, s32 a1) {
    func_800A5FD0(a0 + 0xE2C, 2);
    func_800A735C(a0, 2);
    if (a1 & 1) {
        func_8009E334(a0);
    }
}
