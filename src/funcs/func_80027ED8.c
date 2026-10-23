#include "common.h"

void func_800A4350(void *, f32, f32, f32, f32);
void func_800A5730(void *, s32);
void func_800A62C4(void *, s32, s32, s32, s32);

void func_80027ED8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *s;

    s = (u8 *)arg0 + 0x1B28;
    func_800A62C4(s, arg1, arg2, arg3, arg4);
    func_800A5730(s, 1);
    func_800A4350(s, 0.200538322f, 0.314159274f, 10.0f, 2000.0f);
    *(f32 *)((u8 *)arg0 + 0x2260) = *(f32 *)((u8 *)arg0 + 0x2264) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x2268) = 1.570796371f;
}
