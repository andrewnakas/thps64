/* cflags: -O2 */
#include "common.h"

extern void func_80001EC0(void *, void *, s32);
extern void func_80004ED0(void *, s32, s32);
extern void func_800BC6E4(s32, void *, void *);
extern void func_800BC970(void);

void func_800BC0F4(s32 arg0) {
    u8 sp10[0x18];
    u8 sp28[0x8];
    u8 *p = sp10;

    func_80001EC0(p, sp28, 1);
    func_800BC6E4(arg0, func_800BC970, p);
    func_80004ED0(p, 0, 1);
}
