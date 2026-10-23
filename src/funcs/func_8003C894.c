#include "common.h"

void func_800A735C(void *, s32);
void func_8009E334(void *);

void func_8003C894(void *arg0, s32 arg1) {
    func_800A735C(arg0, 2);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
