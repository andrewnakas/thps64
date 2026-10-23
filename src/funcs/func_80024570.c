#include "common.h"

extern s32 D_800EA110;
extern void func_8009F0EC(void *, s32);
extern void func_8008B284(void);
extern void func_8008923C(void);

void func_80024570(void) {
    func_8009F0EC(&D_800EA110, 1);
    func_8008B284();
    func_8008923C();
}
