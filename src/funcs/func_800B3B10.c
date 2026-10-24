/* cflags: -O2 */
#include "common.h"

s32 func_800BC6E4(s32 *, s32 *, s32);                     /* extern */
s32 func_800C0204();                                  /* extern */
extern s32 D_800F0DD0;
extern s32 func_800BC7A4;

void func_800B3B10(s32 arg0) {
    func_800C0204();
    func_800BC6E4(&D_800F0DD0, &func_800BC7A4, arg0 + 0x1C8);
}
