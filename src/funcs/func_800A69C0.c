/* cflags: -O2 */
#include "common.h"

void func_800A6A0C(s32);
void func_800A6AB0(s32, s32, s32 *, f32 *);

void func_800A69C0(s32 arg0, s32 arg1) {
    f32 f;

    f = 1000000.0f;
    if (arg1 == -1) {
        func_800A6A0C(arg0);
    } else {
        func_800A6AB0(arg0, 1, &arg1, &f);
    }
}
