#include "common.h"

extern u8 D_800D61E0[];
void func_8004B468(void *);
void func_8005DEBC(void *, void *);

void func_8004C4E4(u8 *arg0) {
    u8 *base;

    func_8004B468(arg0);
    base = D_800D61E0;
    func_8005DEBC(arg0, base + *(s32 *)(arg0 + 0x3E0) * 0x14);
}
