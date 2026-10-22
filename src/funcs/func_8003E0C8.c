#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_800A5FD0(void *, s32);             /* extern */
s32 func_800A735C(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
extern s32 D_8001A2D0;

void func_8003E0C8(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v1;

    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_8001A2D0;
    temp_v1 = (*(void **)((u8 *)(arg0) + 0x4F4));
    if (temp_v1 != NULL) {
        temp_v0 = (*(void **)((u8 *)(temp_v1) + 0x48));
        (*(s32 (**)(void *, s32))((u8 *)(temp_v0) + 0xC))(temp_v1 + (*(s16 *)((u8 *)(temp_v0) + 8)), 3);
    }
    func_800B19C0(arg0 + 0x7F4, 2);
    func_800B19C0(arg0 + 0x7E0, 2);
    func_800B19C0(arg0 + 0x7CC, 2);
    func_800B19C0(arg0 + 0x7B8, 2);
    func_800A735C(arg0 + 0x56C, 2);
    func_800B19C0(arg0 + 0x558, 2);
    func_800B19C0(arg0 + 0x544, 2);
    func_800B19C0(arg0 + 0x530, 2);
    func_800B19C0(arg0 + 0x51C, 2);
    func_800A5FD0(arg0 + 0x4F8, 2);
    func_800A735C(arg0 + 0x28C, 2);
    func_800A735C(arg0 + 0x4C, 2);
    func_800B19C0(arg0 + 0x38, 2);
    func_800394A8(arg0, arg1);
}
