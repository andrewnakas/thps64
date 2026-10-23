#include "common.h"

extern void func_8004A08C(u8 *);
extern s32 D_8001B420;

u8 *func_8004AE80(u8 *arg0) {
    func_8004A08C(arg0);
    *(void **)(arg0 + 0x48) = &D_8001B420;
    *(u16 *)(arg0 + 0) |= 2;
    *(s32 *)(arg0 + 0x208) = 0;
    *(s32 *)(arg0 + 0x228) = 0x10000;
    *(u8 *)(arg0 + 0x226) = 1;
    *(u8 *)(arg0 + 0x227) = 1;
    return arg0;
}
