#include "common.h"

void func_8005EA48(void *);
extern u8 D_8001E388[];
extern s32 D_800DE520;

void func_8007D788(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x44) = D_8001E388;
    D_800DE520--;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
