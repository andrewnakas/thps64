/* cflags: -O2 */
#include "common.h"

void func_800A0068(u8 *, s32, s32, u8 *, s32);
void func_80004620(u8 *);

void func_800C038C(u8 *arg0) {
    func_800A0068(arg0, 1, 2, arg0 + 0x1C8, 0x400);
    func_80004620(arg0);
}
