#include "common.h"

extern s32 D_800FA354;
extern void func_800B6F9C(s32, s32, s32);

void func_80035110(void *arg0) {
    func_800B6F9C(D_800FA354, 0, *(s16 *)((u8 *)arg0 + 0x3A));
}
