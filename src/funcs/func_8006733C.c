#include "common.h"

extern u8 D_8001CD18[];
extern u8 D_800DC5A0[];
void func_8004B264(void *, void *);
void func_800672A0(void *);
void func_8004B330(void *, s32);
void func_8004B4F8(void *);

void func_8006733C(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x48) = D_8001CD18;
    func_8004B264(arg0, D_800DC5A0);
    func_800672A0(arg0);
    func_8004B330(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
