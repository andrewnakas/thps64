/* cflags: -O2 */
#include "common.h"

s32 func_80005720(s32, s32, s32);           /* extern */
s32 func_8009E6B4(s32 *, s32, s32);         /* extern */
s32 func_800A0CEC(void *, s32);                 /* extern */
s32 func_800A0D0C(void *, s32 *);           /* extern */
s32 func_800A1E70(void *);                      /* extern */
extern s32 D_80020DAC;
extern s32 D_800EA110;
extern s32 D_800EA550;

void func_800A169C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 *arg6, s32 arg7) {
    s32 *var_s1;
    s32 temp_a1;
    s32 temp_v0;

    var_s1 = arg6;
    if (var_s1 == NULL) {
        var_s1 = &D_80020DAC;
    }
    func_800A1E70(arg0);
    temp_a1 = (arg3 + 0x1F) & ~0x1F;
    (*(s32 *)((u8 *)arg0 + 0x438)) = temp_a1;
    temp_v0 = func_8009E6B4(&D_800EA110, temp_a1, 4);
    (*(s32 *)((u8 *)arg0 + 0x4EC)) = temp_v0;
    if (temp_v0 != 0) {
        func_80005720(temp_v0, arg2, arg3);
        D_800EA550 = 5;
        (*(s32 *)((u8 *)arg0 + 0xC)) = 0x1E;
        (*(s32 *)((u8 *)arg0 + 0x424)) = arg7;
        (*(s32 *)((u8 *)arg0 + 0x434)) = arg1;
        (*(s32 *)((u8 *)arg0 + 0x45C)) = arg4;
        (*(s32 *)((u8 *)arg0 + 0x47C)) = 0;
        func_800A0CEC(arg0, arg5);
        func_800A0D0C(arg0, var_s1);
    }
}
