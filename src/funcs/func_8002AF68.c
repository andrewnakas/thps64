#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_8003C894(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
extern s32 D_800192F0;
extern s32 D_800D3694;
extern s32 D_800D3698;

void func_8002AF68(void *arg0, s32 arg1) {
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_800192F0;
    D_800D3694 = 8;
    D_800D3698 = 6;
    func_800B19C0(arg0 + 0x6CC, 2);
    func_800B19C0(arg0 + 0x6B8, 2);
    func_800B19C0(arg0 + 0x6A4, 2);
    func_8003C894(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
