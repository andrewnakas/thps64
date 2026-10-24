/* cflags: -O2 */
#include "common.h"

extern void func_800AE43C(void *, s32);
extern u8 D_800ECB30[];

void func_800AE3F0(void) {
    u8 *p = D_800ECB30;
    func_800AE43C(p, 0);
    *(s32 *)(p + 8) = 0;
}
