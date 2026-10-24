/* cflags: -O2 */
#include "common.h"

extern void func_80005070(void *, s32, s32);
extern void func_80004ED0(void *, s32, s32);

void func_800BB514(u8 *a0) {
    *(s32 *)(a0 + 0x218) = 1;
    func_80005070(a0 + 0x1CC, 0, 1);
    func_80004ED0(a0 + 0x1E4, 0, 1);
}
