/* cflags: -O2 */
#include "common.h"

void func_800B3A90(u8 *, s32);
void func_8009FF4C(u8 *, s32);
extern u8 D_80021F60[];

void func_800B3CA0(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x1C4) = D_80021F60;
    func_800B3A90(arg0, arg1);
    func_8009FF4C(arg0, arg1);
}
