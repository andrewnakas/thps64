/* cflags: -O2 */
#include "common.h"

void func_80001EC0(void *, void *, s32);
extern u8 D_800FC350[];

void func_800B391C(void) {
    func_80001EC0(D_800FC350, D_800FC350 + 0x18, 1);
}
