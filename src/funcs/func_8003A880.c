#include "common.h"

extern s32 D_800EA9C0;
extern s32 func_800A9460(void *, s32, f32, s32);

void func_8003A880(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0xD0) = 1;
    func_800A9460(&D_800EA9C0, 0, 0.0f, -1);
}
