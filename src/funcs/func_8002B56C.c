#include "common.h"

extern u8 D_800D3130[];
extern s32 D_800193E8;
extern void func_800A0450(void *);

void func_8002B56C(void) {
    u8 *p = D_800D3130;
    func_800A0450(p);
    *(void **)(p + 0x4F8) = &D_800193E8;
}
