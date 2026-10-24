/* cflags: -O2 */
#include "common.h"

extern s32 D_800EA550;

void func_800A15C8(s32 *arg0) {
    if (arg0[0x474 / 4] != 0) { arg0[0] = 10; return; } D_800EA550 = arg0[0x418 / 4];
}
