/* cflags: -O2 */
#include "common.h"

void func_800A662C(u8 *);
void func_800A665C(u8 *, void *);
extern u8 D_80021840[];

u8 *func_800A64A0(u8 *arg0) {
    func_800A662C(arg0);
    func_800A665C(arg0, D_80021840);
    *(s32 *)(arg0 + 0x44) = 0;
    return arg0;
}
