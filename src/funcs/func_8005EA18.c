#include "common.h"

extern s32 D_800EA110;
extern void func_8009E524(void *, s32, s32, s32);

void func_8005EA18(s32 arg0, s32 arg1) {
    func_8009E524(&D_800EA110, arg0, arg1, 4);
}
