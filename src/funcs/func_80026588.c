#include "common.h"

s32 func_80026494(void *, s32);             /* extern */
s32 func_80033D70(s32);                     /* extern */
s32 func_8003925C(void *);                      /* extern */
s32 func_800392E4(void *);                      /* extern */
s32 func_80039500();                            /* extern */
s32 func_800A72C0(void *);                      /* extern */
s32 func_800A73EC(void *, s32);             /* extern */
s32 func_800A7AF8(void *, s32, s32, s32, s32); /* extern */
s32 func_800A7B10(void *, s32, s32, s32, s32); /* extern */
extern s32 D_800171C8;

void *func_80026588(void *arg0) {
    void *temp_s1;
    void *temp_s2;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_800171C8;
    temp_s1 = arg0 + 0x34;
    func_800392E4(temp_s1);
    temp_s2 = arg0 + 0x8C;
    func_800A72C0(temp_s2);
    func_8003925C(temp_s1);
    func_80033D70(0);
    (*(s32 *)((u8 *)(arg0) + 0x30)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x2CC)) = 0;
    func_80026494(arg0, 1);
    func_800A73EC(temp_s2, 1);
    func_800A7AF8(temp_s2, 0xFF, 0xFF, 0xFF, 0xFF);
    func_800A7B10(temp_s2, 0xFF, 0xFF, 0xFF, 0xFF);
    return arg0;
}
