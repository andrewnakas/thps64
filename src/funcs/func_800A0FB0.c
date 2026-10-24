/* cflags: -O2 */
#include "common.h"

void func_800A3750(void *, void *, s32, s32, s32, void *, s32);
extern u8 D_80020CF8[];
extern s32 D_800EA550;

void func_800A0FB0(u8 *arg0) {
    s32 t;
    s32 g = D_800EA550;

    *(s32 *)(arg0 + 4) = 0x2A;
    t = *(s32 *)(arg0 + 0x428);
    *(s32 *)(arg0 + 0x44C) = t;
    *(s32 *)(arg0 + 0x444) = t;
    *(s32 *)(arg0 + 0x448) = g;
    func_800A3750(arg0, D_80020CF8, *(s32 *)(arg0 + 0x434), 3, 1, arg0 + 0x444, 0);
}
