/* cflags: -O2 */
#include "common.h"

extern void func_80002E00(s32, void *, s32);
extern u8 D_800ECFC8[];

void func_800BB55C(u8 *a0) {
    func_80002E00(5, D_800ECFC8, 0x33333333);
    *(s32 *)(a0 + 0x214) = 0;
}
