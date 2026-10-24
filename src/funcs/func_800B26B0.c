/* cflags: -O2 */
#include "common.h"

void *func_8009E30C(s32);
void func_800A0270(void *, s32 *);
s32 *func_800B254C(void *, s32);
s32 *func_800B267C(u8 *, s32);

s32 *func_800B26B0(u8 *arg0, s32 arg1) {
    s32 *p = func_800B267C(arg0, arg1);

    if (p == NULL) {
        p = func_800B254C(func_8009E30C(0x18), arg1);
        func_800A0270(arg0 + 0x38, p);
        *p = 0;
    }
    (*p)++;
    return p;
}
