#include "common.h"

extern u8 D_80019378[];
extern u16 D_800D0FD8;
void func_80039500(void *);
void func_800B198C(void *);
void func_800242CC(void);
void func_800B1A80(void *, s32);

void *func_8002B360(u8 *arg0) {
    u8 *p;

    func_80039500(arg0);
    *(void **)(arg0 + 0x2C) = D_80019378;
    p = arg0 + 0x30;
    func_800B198C(p);
    func_800242CC();
    if (D_800D0FD8 == 2) {
        func_800B1A80(p, 0x99);
    } else {
        func_800B1A80(p, 0x98);
    }
    *(s32 *)(arg0 + 0x48) = 0;
    *(s32 *)(arg0 + 0x4C) = 1;
    *(s32 *)(arg0 + 0x44) = 1;
    *(s32 *)(arg0 + 0x50) = 0;
    return arg0;
}
