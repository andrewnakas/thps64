/* cflags: -O2 */
#include "common.h"

void func_800A0C6C(u8 *, s32);
void func_800A3750(void *, void *, s32, s32, s32, void *, f32);
extern u8 D_8002100C[];
extern u8 D_80021024[];
extern s32 D_800EA550;
extern u32 D_800F56C0;

void func_800A3250(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *s;

    D_800EA550 = 7;
    *(s32 *)(arg0 + 0x434) = arg1;
    *(s32 *)(arg0 + 0x10) = 0x32;
    *(s32 *)(arg0 + 0x478) = arg3;
    if (arg2 != 0) {
        func_800A0C6C(arg0, 7);
        if (D_800F56C0 > 0x400000) {
            s = D_8002100C;
        } else {
            s = D_80021024;
        }
        func_800A3750(arg0, s, *(s32 *)(arg0 + 0x434), 0, 0, arg0 + 0x444, 10.0f);
    }
}
