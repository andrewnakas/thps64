/* cflags: -O2 */
#include "common.h"

void *func_800A0760(u8 *, s32);
void func_800A3194(u8 *);
void func_800A3750(void *, void *, s32, s32, s32, void *, s32);

void func_800A08F0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *t;

    *(s32 *)(arg0 + 0x14) = 0;
    func_800A3194(arg0);
    t = func_800A0760(arg0, arg1);
    *(s32 *)(arg0 + 0x44C) = arg3;
    *(s32 *)(arg0 + 0x444) = arg3;
    *(s32 *)(arg0 + 0x448) = arg2;
    func_800A3750(arg0, t, *(s32 *)(arg0 + 0x434), 4, 0, arg0 + 0x444, 0);
}
