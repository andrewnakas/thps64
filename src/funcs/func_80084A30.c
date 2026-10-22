#include "common.h"

void func_80084BEC(void *, s32);                            /* extern */
void func_800B2860(void *);                            /* extern */
extern s32 D_800E8CE0[];

void func_80084A30(void) {
    s32 *temp_s0 = D_800E8CE0;

    func_80084BEC(temp_s0, 0);
    func_800B2860((u8 *) temp_s0 + 0xC);
    *(s32 *) ((u8 *) temp_s0 + 0x8) = 0;
}
