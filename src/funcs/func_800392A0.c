#include "common.h"

void func_80037C84(void *, s32);
void func_8009E334(void *);

void func_800392A0(void *arg0, s32 arg1) {
    func_80037C84(arg0, arg1);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
