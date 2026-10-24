#include "common.h"

extern char D_800194A0[];
extern s32 D_800D3694;
extern s32 D_800D3698;
extern void func_800B19C0(void *, s32);
extern void func_8003C894(void *, s32);
extern void func_800394A8(void *, s32);

void func_8002C5D0(void *a0, s32 a1) {
    *(void **)((u8 *)a0 + 0x2C) = D_800194A0;
    D_800D3694 = 10;
    D_800D3698 = 7;
    func_800B19C0((u8 *)a0 + 0x6CC, 2);
    func_800B19C0((u8 *)a0 + 0x6B8, 2);
    func_8003C894((u8 *)a0 + 0x48, 2);
    func_800B19C0((u8 *)a0 + 0x34, 2);
    func_800394A8(a0, a1);
}
