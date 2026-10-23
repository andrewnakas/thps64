#include "common.h"
extern u8 D_80017048[];
void func_800A6944(void *, s32);
void func_8009E334(void *);
void func_80024C3C(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x94) = D_80017048;
    func_800A6944(arg0, 2);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
