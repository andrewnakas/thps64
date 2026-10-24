/* cflags: -O2 */
#include "common.h"

void func_8009FFD8(u8 *, s32, s32, s32);
void func_800BC6E4(void *, void *, void *);
void func_80004620(u8 *);
void func_800BC7A4();
extern u8 D_800F0DD0[];

void func_800BB29C(u8 *arg0, s32 arg1, s32 arg2) {
    func_8009FFD8(arg0, arg1, arg2, 0x800);
    func_800BC6E4(D_800F0DD0, func_800BC7A4, arg0 + 0x1CC);
    func_80004620(arg0);
}
