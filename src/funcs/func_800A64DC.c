/* cflags: -O2 */
#include "common.h"

void func_800A662C(u8 *);
void func_800A665C(u8 *, s32);

u8 *func_800A64DC(u8 *arg0, s32 arg1) {
    func_800A662C(arg0);
    func_800A665C(arg0, arg1);
    *(s32 *)(arg0 + 0x44) = 0;
    return arg0;
}
