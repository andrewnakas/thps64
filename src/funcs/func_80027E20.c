#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_27E20;

void func_80027E20(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    (*(s32 *)((u8 *)(arg0) + 4)) = (s32) (arg1 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 8)) = (s32) (arg2 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0xC)) = (s32) (arg3 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0x84)) = (s32) (arg4 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0x88)) = (s32) (arg5 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0x8C)) = (s32) (arg6 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0x9C)) = (s32) (arg7 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0xA0)) = (s32) (arg8 * 4096.0f);
    (*(s32 *)((u8 *)(arg0) + 0xA4)) = (s32) (arg9 * 4096.0f);
    *(Vec3i_27E20 *)((u8 *)(arg0) + 0x16C) = *(Vec3i_27E20 *)((u8 *)(arg0) + 4);
}
