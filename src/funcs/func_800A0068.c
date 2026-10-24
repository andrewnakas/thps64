/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0x1B0]; s32 a; s32 b; s32 c; } S800A0068;
void func_800043D0(S800A0068 *, s32, void *, S800A0068 *, s32, s32);
void func_800A00F4();

void func_800A0068(S800A0068 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->a = arg3;
    arg0->c = 0;
    arg0->b = arg4;
    func_800043D0(arg0, arg1, func_800A00F4, arg0, arg0->a + arg0->b, arg2);
}
