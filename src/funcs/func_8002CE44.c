#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_800A5FD0(void *, s32);             /* extern */
s32 func_800A735C(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
s32 func_800BABE0(void *, s32);              /* extern */
extern s32 D_800199C8;
extern s32 D_800EECF0;

void func_8002CE44(u8 *arg0, s32 arg1) {
    s32 *p;
    void *temp_v0;
    void *temp_v1;

    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_800199C8;
    temp_v1 = (*(void **)((u8 *)(arg0) + 0x10C));
    if (temp_v1 != NULL) {
        temp_v0 = (*(void **)((u8 *)(temp_v1) + 0x48));
        (*(s32 (**)(void *, s32))((u8 *)(temp_v0) + 0xC))((u8 *)temp_v1 + (*(s16 *)((u8 *)(temp_v0) + 8)), 3);
    }
    p = &D_800EECF0;
    func_800BABE0(p, (*(s32 *)((u8 *)(arg0) + 0x838)));
    func_800BABE0(p, (*(s32 *)((u8 *)(arg0) + 0x83C)));
    func_800BABE0(p, (*(s32 *)((u8 *)(arg0) + 0x840)));
    func_800BABE0(p, (*(s32 *)((u8 *)(arg0) + 0x844)));
    func_800A735C(arg0 + 0x370, 2);
    func_800A735C(arg0 + 0x130, 2);
    func_800A5FD0(arg0 + 0x110, 2);
    func_800B19C0(arg0 + 0xF8, 2);
    func_800B19C0(arg0 + 0xE4, 2);
    func_800B19C0(arg0 + 0xD0, 2);
    func_800B19C0(arg0 + 0xBC, 2);
    func_800B19C0(arg0 + 0xA8, 2);
    func_800B19C0(arg0 + 0x94, 2);
    func_800B19C0(arg0 + 0x80, 2);
    func_800B19C0(arg0 + 0x6C, 2);
    func_800B19C0(arg0 + 0x58, 2);
    func_800B19C0(arg0 + 0x44, 2);
    func_800B19C0(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
