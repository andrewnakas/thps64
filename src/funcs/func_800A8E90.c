/* cflags: -O2 */
#include "common.h"

extern void func_800AB734(s32, s32);

void func_800A8E90(s32 *arg0, f32 arg1) {
    if (arg0[0] != 0) {
        arg0[25] = (s32)(arg1 * 32767.0f);
        if (arg0[25] > 0x7FFF) {
            arg0[25] = 0x7FFF;
        }
        if (arg0[25] < 0) {
            arg0[25] = 0;
        }
        func_800AB734(2, arg0[25]);
    }
}
