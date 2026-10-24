/* cflags: -O2 */
#include "common.h"

s32 func_80011C00(void);
void func_80002BC0(s32);
void func_80001EC0(void *, void *, s32);
void func_80002E00(s32, void *, s32);
void func_80004ED0(void *, s32, s32);
void func_8000CAD0(void);
void func_80002B20(s32);

void func_800C0640(u8 *arg0) {
    func_80002BC0(func_80011C00() | 0x400);
    func_80001EC0(arg0 + 0x1D0, arg0 + 0x1CC, 1);
    func_80002E00(0xC, arg0 + 0x1D0, 0);
    while (1) {
        func_80004ED0(arg0 + 0x1D0, 0, 1);
        func_8000CAD0();
        func_80002B20(1);
        ((void (*)(void))0x80000400)();
    }
}
