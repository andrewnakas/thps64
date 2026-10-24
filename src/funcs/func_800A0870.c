/* cflags: -O2 */
#include "common.h"

extern s32 func_800A0760(u8 *, s32);
extern void func_800A0C6C(u8 *, s32);
extern void func_800A3194(void);
extern void func_800A3750(u8 *, s32, s32, s32, s32, u8 *, s32);

void func_800A0870(u8 *arg0, s32 arg1, s32 arg2) {
    s32 v;

    *(s32 *)(arg0 + 0x14) = 0;
    func_800A3194();
    v = func_800A0760(arg0, arg1);
    func_800A0C6C(arg0, arg2);
    func_800A3750(arg0, v, *(s32 *)(arg0 + 0x434), 0, 0, arg0 + 0x444, 0);

}
