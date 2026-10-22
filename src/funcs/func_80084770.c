#include "common.h"

void func_80084A20(void *, s32);                            /* extern */
void func_800B2860(void *);                            /* extern */
extern s32 D_800E8A20[];

void func_80084770(void) {
    s32 *temp_s0 = D_800E8A20;

    func_80084A20(temp_s0, 0);
    func_800B2860((u8 *) temp_s0 + 0xC);
    *(s32 *) ((u8 *) temp_s0 + 0x8) = 0;
}
