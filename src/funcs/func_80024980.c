#include "common.h"

s32 func_80039500();                            /* extern */
s32 func_800A72C0(void *);                      /* extern */
s32 func_800A73EC(void *, s32);             /* extern */
s32 func_800A7AF8(void *, s32, s32, s32, s32); /* extern */
s32 func_800A7B10(void *, s32, s32, s32, s32); /* extern */
extern s32 D_80017018;

void *func_80024980(void *arg0) {
    void *temp_s0;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_80017018;
    temp_s0 = arg0 + 0x30;
    func_800A72C0(temp_s0);
    func_800A73EC(temp_s0, 1);
    func_800A7AF8(temp_s0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_800A7B10(temp_s0, 0xFF, 0xFF, 0xFF, 0xFF);
    return arg0;
}
