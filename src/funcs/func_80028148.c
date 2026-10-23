#include "common.h"

void func_800A4418(void *, s32, s32, s32, f32, f32, s32);

void func_80028148(u8 *arg0, s32 arg1) {
    func_800A4418(arg0 + 0x1B28, *(s32 *)(arg0 + 0x1C88), *(s32 *)(arg0 + 0x1C8C), *(s32 *)(arg0 + 0x1C90),
                  *(f32 *)(arg0 + 0x1C94), *(f32 *)(arg0 + 0x1C98), arg1);
}
