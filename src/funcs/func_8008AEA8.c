#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_800A735C(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
extern s32 D_8001F988;

void func_8008AEA8(void *arg0, s32 arg1) {
    (*(s32 **)((u8 *)arg0 + 0x2C)) = &D_8001F988;
    func_800A735C(arg0 + 0x204, 2);
    func_800B19C0(arg0 + 0xD8, 2);
    func_800B19C0(arg0 + 0xC4, 2);
    func_800B19C0(arg0 + 0xB0, 2);
    func_800B19C0(arg0 + 0x9C, 2);
    func_800B19C0(arg0 + 0x88, 2);
    func_800B19C0(arg0 + 0x74, 2);
    func_800B19C0(arg0 + 0x60, 2);
    func_800B19C0(arg0 + 0x4C, 2);
    func_800B19C0(arg0 + 0x38, 2);
    func_800394A8(arg0, arg1);
}
