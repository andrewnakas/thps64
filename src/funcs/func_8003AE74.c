#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_8003C894(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
extern s32 D_80019FC0;
extern s32 D_800D3694;
extern s32 D_800D3698;

void func_8003AE74(void *arg0, s32 arg1) {
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_80019FC0;
    D_800D3694 = 4;
    D_800D3698 = 6;
    func_800B19C0(arg0 + 0x6CC, 2);
    func_800B19C0(arg0 + 0x6B8, 2);
    func_8003C894(arg0 + 0x48, 2);
    func_800B19C0(arg0 + 0x34, 2);
    func_800394A8(arg0, arg1);
}
