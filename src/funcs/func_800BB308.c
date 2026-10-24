/* cflags: -O2 */
#include "common.h"

extern void func_80001EC0(void *, void *, s32);
extern void func_80005070(void *, void *, s32);
extern void func_80004ED0(void *, void *, s32);

void func_800BB308(u8 *arg0) {
    u8 sp10[0x18];
    u8 sp28[8];
    u8 *p = sp10;

    func_80001EC0(p, sp28, 1);
    func_80005070(arg0 + 0x1CC, p, 1);
    func_80004ED0(p, 0, 1);
}
