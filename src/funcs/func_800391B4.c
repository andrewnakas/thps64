#include "common.h"

extern s32 D_800E8A20;
extern s32 func_800847E8(void *);
extern void func_80037DC8(s32, s32);

void func_800391B4(s32 arg0) {
    func_80037DC8(arg0, func_800847E8(&D_800E8A20));
}
