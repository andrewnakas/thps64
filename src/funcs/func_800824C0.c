#include "common.h"

extern void func_8004B330(u8 *, s32);
extern void func_8004B4F8(u8 *);
extern void func_800824B8(u8 *);
extern u8 D_8001E730[];

void func_800824C0(u8 *arg0, s32 arg1) {
    *(u8 **)(arg0 + 0x48) = D_8001E730;
    func_800824B8(arg0);
    func_8004B330(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
