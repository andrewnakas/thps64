/* cflags: -O2 */
#include "common.h"

void func_800B1A44(s32 *, s32);
s32 func_800B26B0(void *, s32);
extern u8 D_800ECEF4[];

void func_800B1A80(s32 *arg0, s32 arg1) {
    func_800B1A44(arg0, arg1);
    *arg0 = func_800B26B0(D_800ECEF4, arg1);
}
