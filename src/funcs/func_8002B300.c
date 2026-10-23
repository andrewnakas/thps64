#include "common.h"

extern char D_80019378[];
extern char D_800EA110[];
extern void func_8009ECF8(void *, s32);
extern void func_800B19C0(void *, s32);
extern void func_800394A8(void *, s32);

void func_8002B300(void *a0, s32 a1) {
    *(void **)((u8 *)a0 + 0x2C) = D_80019378;
    func_8009ECF8(D_800EA110, *(s32 *)((u8 *)a0 + 0x50));
    func_800B19C0((u8 *)a0 + 0x30, 2);
    func_800394A8(a0, a1);
}
